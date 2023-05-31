/*
   Copyright 2022 The Silkworm Authors

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

#include <filesystem>

#include <CLI/CLI.hpp>

#include "state_transition.hpp"

void execute_test(const std::string& path, bool terminate_flag, bool diagnostics_flag);
using namespace silkworm::cmd::state_transition;
namespace fs = std::filesystem;

int main(int argc, char* argv[]) {
    CLI::App app{"Executes Ethereum State Transition tests"};

    std::string path = fs::current_path();
    app.add_option("path", path, "Path to test file or directory")
        ->check(CLI::ExistingPath);

    bool terminate_flag = false;
    app.add_flag("-t,--terminateOnError", terminate_flag, "Terminate execution on failure");

    bool diagnostics_flag = true;
    app.add_flag("-d,--diagnostics", diagnostics_flag, "Enable extended diagnostics output");

    CLI11_PARSE(app, argc, argv)

    //    path = "/home/jacek/dev/silkworm/cmd/state-transition/state_transition_sample3.json";
    //    path = "/home/jacek/dev/ethereum-tests/GeneralStateTests/stTransactionTest/ValueOverflow.json";

    try {
        if (std::filesystem::is_directory(path)) {
            for (const auto& test_file : std::filesystem::recursive_directory_iterator(path)) {
                if (!test_file.is_directory() && test_file.path().extension() == ".json") {
                    execute_test(test_file.path(), terminate_flag, diagnostics_flag);
                }
            }
        } else {
            execute_test(path, terminate_flag, diagnostics_flag);
        }

    } catch (const std::exception& e) {
        // code to handle exceptions of type std::exception and its derived classes
        const auto desc = e.what();
        std::cerr << "Exception: " << desc << std::endl;
    } catch (...) {
        // code to handle any other type of exception
        std::cerr << "An unknown exception occurred" << std::endl;
    }
}

void execute_test(const std::string& path, bool terminate_flag, bool diagnostics_flag) {
    std::ifstream input_file(path);
    nlohmann::json baseJson;
    input_file >> baseJson;
    auto stateTransition = StateTransition(baseJson, terminate_flag, diagnostics_flag);
    stateTransition.run();
}