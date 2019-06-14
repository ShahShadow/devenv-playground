#!/bin/bash -xe

docker container run -it --name=bazel-test --user admin:admin -v ~/workspaces:/workspaces bazel-test-1:latest bash