// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: execution/execution.proto

#include "execution/execution.pb.h"
#include "execution/execution.grpc.pb.h"

#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/sync_stream.h>
#include <gmock/gmock.h>
namespace execution {

class MockExecutionStub : public Execution::StubInterface {
 public:
  MOCK_METHOD3(InsertBlocks, ::grpc::Status(::grpc::ClientContext* context, const ::execution::InsertBlocksRequest& request, ::execution::InsertionResult* response));
  MOCK_METHOD3(AsyncInsertBlocksRaw, ::grpc::ClientAsyncResponseReaderInterface< ::execution::InsertionResult>*(::grpc::ClientContext* context, const ::execution::InsertBlocksRequest& request, ::grpc::CompletionQueue* cq));
  MOCK_METHOD3(PrepareAsyncInsertBlocksRaw, ::grpc::ClientAsyncResponseReaderInterface< ::execution::InsertionResult>*(::grpc::ClientContext* context, const ::execution::InsertBlocksRequest& request, ::grpc::CompletionQueue* cq));
  MOCK_METHOD3(ValidateChain, ::grpc::Status(::grpc::ClientContext* context, const ::execution::ValidationRequest& request, ::execution::ValidationReceipt* response));
  MOCK_METHOD3(AsyncValidateChainRaw, ::grpc::ClientAsyncResponseReaderInterface< ::execution::ValidationReceipt>*(::grpc::ClientContext* context, const ::execution::ValidationRequest& request, ::grpc::CompletionQueue* cq));
  MOCK_METHOD3(PrepareAsyncValidateChainRaw, ::grpc::ClientAsyncResponseReaderInterface< ::execution::ValidationReceipt>*(::grpc::ClientContext* context, const ::execution::ValidationRequest& request, ::grpc::CompletionQueue* cq));
  MOCK_METHOD3(UpdateForkChoice, ::grpc::Status(::grpc::ClientContext* context, const ::execution::ForkChoice& request, ::execution::ForkChoiceReceipt* response));
  MOCK_METHOD3(AsyncUpdateForkChoiceRaw, ::grpc::ClientAsyncResponseReaderInterface< ::execution::ForkChoiceReceipt>*(::grpc::ClientContext* context, const ::execution::ForkChoice& request, ::grpc::CompletionQueue* cq));
  MOCK_METHOD3(PrepareAsyncUpdateForkChoiceRaw, ::grpc::ClientAsyncResponseReaderInterface< ::execution::ForkChoiceReceipt>*(::grpc::ClientContext* context, const ::execution::ForkChoice& request, ::grpc::CompletionQueue* cq));
  MOCK_METHOD3(AssembleBlock, ::grpc::Status(::grpc::ClientContext* context, const ::execution::AssembleBlockRequest& request, ::execution::AssembleBlockResponse* response));
  MOCK_METHOD3(AsyncAssembleBlockRaw, ::grpc::ClientAsyncResponseReaderInterface< ::execution::AssembleBlockResponse>*(::grpc::ClientContext* context, const ::execution::AssembleBlockRequest& request, ::grpc::CompletionQueue* cq));
  MOCK_METHOD3(PrepareAsyncAssembleBlockRaw, ::grpc::ClientAsyncResponseReaderInterface< ::execution::AssembleBlockResponse>*(::grpc::ClientContext* context, const ::execution::AssembleBlockRequest& request, ::grpc::CompletionQueue* cq));
  MOCK_METHOD3(GetAssembledBlock, ::grpc::Status(::grpc::ClientContext* context, const ::execution::GetAssembledBlockRequest& request, ::execution::GetAssembledBlockResponse* response));
  MOCK_METHOD3(AsyncGetAssembledBlockRaw, ::grpc::ClientAsyncResponseReaderInterface< ::execution::GetAssembledBlockResponse>*(::grpc::ClientContext* context, const ::execution::GetAssembledBlockRequest& request, ::grpc::CompletionQueue* cq));
  MOCK_METHOD3(PrepareAsyncGetAssembledBlockRaw, ::grpc::ClientAsyncResponseReaderInterface< ::execution::GetAssembledBlockResponse>*(::grpc::ClientContext* context, const ::execution::GetAssembledBlockRequest& request, ::grpc::CompletionQueue* cq));
  MOCK_METHOD3(CurrentHeader, ::grpc::Status(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::execution::GetHeaderResponse* response));
  MOCK_METHOD3(AsyncCurrentHeaderRaw, ::grpc::ClientAsyncResponseReaderInterface< ::execution::GetHeaderResponse>*(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq));
  MOCK_METHOD3(PrepareAsyncCurrentHeaderRaw, ::grpc::ClientAsyncResponseReaderInterface< ::execution::GetHeaderResponse>*(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq));
  MOCK_METHOD3(GetTD, ::grpc::Status(::grpc::ClientContext* context, const ::execution::GetSegmentRequest& request, ::execution::GetTDResponse* response));
  MOCK_METHOD3(AsyncGetTDRaw, ::grpc::ClientAsyncResponseReaderInterface< ::execution::GetTDResponse>*(::grpc::ClientContext* context, const ::execution::GetSegmentRequest& request, ::grpc::CompletionQueue* cq));
  MOCK_METHOD3(PrepareAsyncGetTDRaw, ::grpc::ClientAsyncResponseReaderInterface< ::execution::GetTDResponse>*(::grpc::ClientContext* context, const ::execution::GetSegmentRequest& request, ::grpc::CompletionQueue* cq));
  MOCK_METHOD3(GetHeader, ::grpc::Status(::grpc::ClientContext* context, const ::execution::GetSegmentRequest& request, ::execution::GetHeaderResponse* response));
  MOCK_METHOD3(AsyncGetHeaderRaw, ::grpc::ClientAsyncResponseReaderInterface< ::execution::GetHeaderResponse>*(::grpc::ClientContext* context, const ::execution::GetSegmentRequest& request, ::grpc::CompletionQueue* cq));
  MOCK_METHOD3(PrepareAsyncGetHeaderRaw, ::grpc::ClientAsyncResponseReaderInterface< ::execution::GetHeaderResponse>*(::grpc::ClientContext* context, const ::execution::GetSegmentRequest& request, ::grpc::CompletionQueue* cq));
  MOCK_METHOD3(GetBody, ::grpc::Status(::grpc::ClientContext* context, const ::execution::GetSegmentRequest& request, ::execution::GetBodyResponse* response));
  MOCK_METHOD3(AsyncGetBodyRaw, ::grpc::ClientAsyncResponseReaderInterface< ::execution::GetBodyResponse>*(::grpc::ClientContext* context, const ::execution::GetSegmentRequest& request, ::grpc::CompletionQueue* cq));
  MOCK_METHOD3(PrepareAsyncGetBodyRaw, ::grpc::ClientAsyncResponseReaderInterface< ::execution::GetBodyResponse>*(::grpc::ClientContext* context, const ::execution::GetSegmentRequest& request, ::grpc::CompletionQueue* cq));
  MOCK_METHOD3(HasBlock, ::grpc::Status(::grpc::ClientContext* context, const ::execution::GetSegmentRequest& request, ::execution::HasBlockResponse* response));
  MOCK_METHOD3(AsyncHasBlockRaw, ::grpc::ClientAsyncResponseReaderInterface< ::execution::HasBlockResponse>*(::grpc::ClientContext* context, const ::execution::GetSegmentRequest& request, ::grpc::CompletionQueue* cq));
  MOCK_METHOD3(PrepareAsyncHasBlockRaw, ::grpc::ClientAsyncResponseReaderInterface< ::execution::HasBlockResponse>*(::grpc::ClientContext* context, const ::execution::GetSegmentRequest& request, ::grpc::CompletionQueue* cq));
  MOCK_METHOD3(GetBodiesByRange, ::grpc::Status(::grpc::ClientContext* context, const ::execution::GetBodiesByRangeRequest& request, ::execution::GetBodiesBatchResponse* response));
  MOCK_METHOD3(AsyncGetBodiesByRangeRaw, ::grpc::ClientAsyncResponseReaderInterface< ::execution::GetBodiesBatchResponse>*(::grpc::ClientContext* context, const ::execution::GetBodiesByRangeRequest& request, ::grpc::CompletionQueue* cq));
  MOCK_METHOD3(PrepareAsyncGetBodiesByRangeRaw, ::grpc::ClientAsyncResponseReaderInterface< ::execution::GetBodiesBatchResponse>*(::grpc::ClientContext* context, const ::execution::GetBodiesByRangeRequest& request, ::grpc::CompletionQueue* cq));
  MOCK_METHOD3(GetBodiesByHashes, ::grpc::Status(::grpc::ClientContext* context, const ::execution::GetBodiesByHashesRequest& request, ::execution::GetBodiesBatchResponse* response));
  MOCK_METHOD3(AsyncGetBodiesByHashesRaw, ::grpc::ClientAsyncResponseReaderInterface< ::execution::GetBodiesBatchResponse>*(::grpc::ClientContext* context, const ::execution::GetBodiesByHashesRequest& request, ::grpc::CompletionQueue* cq));
  MOCK_METHOD3(PrepareAsyncGetBodiesByHashesRaw, ::grpc::ClientAsyncResponseReaderInterface< ::execution::GetBodiesBatchResponse>*(::grpc::ClientContext* context, const ::execution::GetBodiesByHashesRequest& request, ::grpc::CompletionQueue* cq));
  MOCK_METHOD3(IsCanonicalHash, ::grpc::Status(::grpc::ClientContext* context, const ::types::H256& request, ::execution::IsCanonicalResponse* response));
  MOCK_METHOD3(AsyncIsCanonicalHashRaw, ::grpc::ClientAsyncResponseReaderInterface< ::execution::IsCanonicalResponse>*(::grpc::ClientContext* context, const ::types::H256& request, ::grpc::CompletionQueue* cq));
  MOCK_METHOD3(PrepareAsyncIsCanonicalHashRaw, ::grpc::ClientAsyncResponseReaderInterface< ::execution::IsCanonicalResponse>*(::grpc::ClientContext* context, const ::types::H256& request, ::grpc::CompletionQueue* cq));
  MOCK_METHOD3(GetHeaderHashNumber, ::grpc::Status(::grpc::ClientContext* context, const ::types::H256& request, ::execution::GetHeaderHashNumberResponse* response));
  MOCK_METHOD3(AsyncGetHeaderHashNumberRaw, ::grpc::ClientAsyncResponseReaderInterface< ::execution::GetHeaderHashNumberResponse>*(::grpc::ClientContext* context, const ::types::H256& request, ::grpc::CompletionQueue* cq));
  MOCK_METHOD3(PrepareAsyncGetHeaderHashNumberRaw, ::grpc::ClientAsyncResponseReaderInterface< ::execution::GetHeaderHashNumberResponse>*(::grpc::ClientContext* context, const ::types::H256& request, ::grpc::CompletionQueue* cq));
  MOCK_METHOD3(GetForkChoice, ::grpc::Status(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::execution::ForkChoice* response));
  MOCK_METHOD3(AsyncGetForkChoiceRaw, ::grpc::ClientAsyncResponseReaderInterface< ::execution::ForkChoice>*(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq));
  MOCK_METHOD3(PrepareAsyncGetForkChoiceRaw, ::grpc::ClientAsyncResponseReaderInterface< ::execution::ForkChoice>*(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq));
  MOCK_METHOD3(Ready, ::grpc::Status(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::execution::ReadyResponse* response));
  MOCK_METHOD3(AsyncReadyRaw, ::grpc::ClientAsyncResponseReaderInterface< ::execution::ReadyResponse>*(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq));
  MOCK_METHOD3(PrepareAsyncReadyRaw, ::grpc::ClientAsyncResponseReaderInterface< ::execution::ReadyResponse>*(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq));
  MOCK_METHOD3(FrozenBlocks, ::grpc::Status(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::execution::FrozenBlocksResponse* response));
  MOCK_METHOD3(AsyncFrozenBlocksRaw, ::grpc::ClientAsyncResponseReaderInterface< ::execution::FrozenBlocksResponse>*(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq));
  MOCK_METHOD3(PrepareAsyncFrozenBlocksRaw, ::grpc::ClientAsyncResponseReaderInterface< ::execution::FrozenBlocksResponse>*(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq));
};

} // namespace execution

