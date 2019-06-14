#include <iostream>
#include <string>

#include <grpc/grpc.h>
#include <grpcpp/server.h>
#include <grpcpp/server_builder.h>
#include <grpcpp/server_context.h>
#include <grpcpp/security/server_credentials.h>

#include "base/string/format.h"
#include "testapi.grpc.pb.h"

class TestApiServerImpl final : public Greeter::Service {
     grpc::Status SayHello(grpc::ServerContext* context, const HelloRequest* request,
                  HelloResponse* reply) override {     
    reply->set_message(FormatString("Hello %s", request->name()));
    return grpc::Status::OK;
  }
};

int main(int argc, char const *argv[])
{
    std::cout << "Bringing up server" << std::endl;
	 std::string server_address("0.0.0.0:50051");
  TestApiServerImpl service;

  grpc::ServerBuilder builder;
  // Listen on the given address without any authentication mechanism.
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  // Register "service" as the instance through which we'll communicate with
  // clients. In this case it corresponds to an *synchronous* service.
  builder.RegisterService(&service);
  // Finally assemble the server.
  std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << server_address << std::endl;

  // Wait for the server to shutdown. Note that some other thread must be
  // responsible for shutting down the server for this call to ever return.
  server->Wait();
	return 0;
}