/*
   Copyright 2020 The Silkworm Authors

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#include <CLI/CLI.hpp>
#include <boost/endian/conversion.hpp>
#include <cstring>
#include <ctime>  // TODO(Andrew) replace with the logger
#include <iostream>
#include <limits>
#include <memory>
#include <optional>
#include <silkworm/db/chaindb.hpp>
#include <silkworm/db/tables.hpp>
#include <silkworm/execution/execution.hpp>

using namespace silkworm;

static constexpr const char* kExecutionStage{"Execution"};

static constexpr const char* kTimeFormat{"%Y-%m-%d_%H:%M:%S_%Z"};

static uint64_t already_executed_block(lmdb::Transaction& txn) {
    std::unique_ptr<lmdb::Table> progress_table{txn.open(db::table::kSyncStageProgress)};
    ByteView stage_key{reinterpret_cast<const uint8_t*>(kExecutionStage), std::strlen(kExecutionStage)};
    std::optional<ByteView> already_executed{progress_table->get(stage_key)};
    if (already_executed) {
        return boost::endian::load_big_u64(already_executed->data());
    } else {
        return 0;
    }
}

static void save_progress(lmdb::Transaction& txn, uint64_t block_number) {
    std::unique_ptr<lmdb::Table> progress_table{txn.open(db::table::kSyncStageProgress)};
    ByteView stage_key{reinterpret_cast<const uint8_t*>(kExecutionStage), std::strlen(kExecutionStage)};
    Bytes val(8, '\0');
    boost::endian::store_big_u64(&val[0], block_number);
    progress_table->put(stage_key, val);
}

int main(int argc, char* argv[]) {
    CLI::App app{"Execute Ethereum blocks and write the result into the DB"};

    std::string db_path{db::default_path()};
    app.add_option("-d,--datadir", db_path, "Path to a database populated by Turbo-Geth");

    uint64_t to_block{std::numeric_limits<uint64_t>::max()};
    app.add_option("--to", to_block, "Block execute up to");

    CLI11_PARSE(app, argc, argv);

    lmdb::options opts{};
    opts.read_only = false;
    std::shared_ptr<lmdb::Environment> env{lmdb::get_env(db_path.c_str(), opts)};
    std::unique_ptr<lmdb::Transaction> txn{env->begin_rw_transaction()};
    auto buffer{std::make_unique<db::Buffer>(txn.get())};

    uint64_t previous_progress{already_executed_block(*txn)};
    uint64_t current_progress{0};

    for (uint64_t block_number{previous_progress + 1}; block_number <= to_block; ++block_number) {
        if (!execute_block(*buffer, block_number)) {
            break;
        }

        current_progress = block_number;
        if (current_progress % 1000 == 0) {
            std::time_t t = std::time(nullptr);
            std::cout << std::put_time(std::gmtime(&t), kTimeFormat) << " Blocks <= " << current_progress
                      << " have been executed\n";
        }

        if (buffer->full_enough()) {
            buffer->write_to_db();
            save_progress(*txn, current_progress);
            lmdb::err_handler(txn->commit());

            std::time_t t = std::time(nullptr);
            std::cout << std::put_time(std::gmtime(&t), kTimeFormat) << " Blocks <= " << current_progress
                      << " have been committed\n";

            txn = env->begin_rw_transaction();
            buffer = std::make_unique<db::Buffer>(txn.get());
        }
    }

    if (current_progress) {
        buffer->write_to_db();
        save_progress(*txn, current_progress);
        lmdb::err_handler(txn->commit());
        std::time_t t = std::time(nullptr);
        std::cout << std::put_time(std::gmtime(&t), kTimeFormat) << " All blocks <= " << current_progress
                  << " have been executed and committed\n";
    } else {
        std::cout << "No blocks have been executed\n";
    }

    return 0;
}