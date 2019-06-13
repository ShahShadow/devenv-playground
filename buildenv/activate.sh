#!/bin/bash -xe

docker container run --rm -it --name=bazel-test --user admin:admin -v ~/workspaces:/workspaces bazel-test-1:latest bash