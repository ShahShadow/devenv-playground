package(default_visibility = ["//visibility:public"])

load("@com_github_grpc_grpc//bazel:grpc_build_system.bzl", "grpc_proto_library")
load("@com_github_grpc_grpc//bazel:cc_grpc_library.bzl", "cc_grpc_library")

proto_library(
    name = "testdata_proto",
    srcs = ["testdata.proto"],    
)

cc_proto_library(
    name = "testdata_cc_proto",
    deps = [":testdata_proto"],
)

cc_binary(
	name = "hello-world",
	srcs = ["hello-world.cc"],
	deps = [":testdata_cc_proto"],
)

proto_library(
    name = "testapi_proto",
    srcs = ["testapi.proto"],    
)

cc_proto_library(
    name = "testapi_cc_proto",
    deps = [":testapi_proto"],
)

cc_grpc_library(
    name = "testapi_cc_grpc",
    srcs = [":testapi_proto"],
	grpc_only = True,
    deps = [":testapi_cc_proto"],
)

cc_binary(
	name = "testapi-server",
	srcs = ["testapi-server.cc"],
	deps = [
        "@com_github_gflags_gflags//:gflags",
		"@com_github_grpc_grpc//:grpc++_reflection",
		":testapi_cc_grpc",
        "//base",
	],
)


