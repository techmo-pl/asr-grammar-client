// Generated by the gRPC protobuf plugin.
// If you make any local change, they will be lost.
// source: asr_service.proto

#include "asr_service.pb.h"
#include "asr_service.grpc.pb.h"

#include <grpc++/impl/codegen/async_stream.h>
#include <grpc++/impl/codegen/async_unary_call.h>
#include <grpc++/impl/codegen/channel_interface.h>
#include <grpc++/impl/codegen/client_unary_call.h>
#include <grpc++/impl/codegen/method_handler_impl.h>
#include <grpc++/impl/codegen/rpc_service_method.h>
#include <grpc++/impl/codegen/service_type.h>
#include <grpc++/impl/codegen/sync_stream.h>
namespace sarmata {

static const char* ASR_method_names[] = {
  "/sarmata.ASR/Recognize",
  "/sarmata.ASR/DefineGrammar",
};

std::unique_ptr< ASR::Stub> ASR::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  std::unique_ptr< ASR::Stub> stub(new ASR::Stub(channel));
  return stub;
}

ASR::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_Recognize_(ASR_method_names[0], ::grpc::RpcMethod::BIDI_STREAMING, channel)
  , rpcmethod_DefineGrammar_(ASR_method_names[1], ::grpc::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::ClientReaderWriter< ::sarmata::RecognizeRequest, ::sarmata::RecognizeResponse>* ASR::Stub::RecognizeRaw(::grpc::ClientContext* context) {
  return new ::grpc::ClientReaderWriter< ::sarmata::RecognizeRequest, ::sarmata::RecognizeResponse>(channel_.get(), rpcmethod_Recognize_, context);
}

::grpc::ClientAsyncReaderWriter< ::sarmata::RecognizeRequest, ::sarmata::RecognizeResponse>* ASR::Stub::AsyncRecognizeRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) {
  return new ::grpc::ClientAsyncReaderWriter< ::sarmata::RecognizeRequest, ::sarmata::RecognizeResponse>(channel_.get(), cq, rpcmethod_Recognize_, context, tag);
}

::grpc::Status ASR::Stub::DefineGrammar(::grpc::ClientContext* context, const ::sarmata::DefineGrammarRequest& request, ::sarmata::DefineGrammarRespone* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_DefineGrammar_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::sarmata::DefineGrammarRespone>* ASR::Stub::AsyncDefineGrammarRaw(::grpc::ClientContext* context, const ::sarmata::DefineGrammarRequest& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::sarmata::DefineGrammarRespone>(channel_.get(), cq, rpcmethod_DefineGrammar_, context, request);
}

ASR::Service::Service() {
  (void)ASR_method_names;
  AddMethod(new ::grpc::RpcServiceMethod(
      ASR_method_names[0],
      ::grpc::RpcMethod::BIDI_STREAMING,
      new ::grpc::BidiStreamingHandler< ASR::Service, ::sarmata::RecognizeRequest, ::sarmata::RecognizeResponse>(
          std::mem_fn(&ASR::Service::Recognize), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      ASR_method_names[1],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< ASR::Service, ::sarmata::DefineGrammarRequest, ::sarmata::DefineGrammarRespone>(
          std::mem_fn(&ASR::Service::DefineGrammar), this)));
}

ASR::Service::~Service() {
}

::grpc::Status ASR::Service::Recognize(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::sarmata::RecognizeResponse, ::sarmata::RecognizeRequest>* stream) {
  (void) context;
  (void) stream;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status ASR::Service::DefineGrammar(::grpc::ServerContext* context, const ::sarmata::DefineGrammarRequest* request, ::sarmata::DefineGrammarRespone* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace sarmata

