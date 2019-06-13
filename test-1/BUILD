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

