FROM ubuntu:bionic

RUN apt-get update && apt-get install -y -q \
    apt-utils \
    autoconf \
    automake \
    curl \
    g++ \
    gnupg2 \
    libtool \
    make \
    openjdk-8-jdk \
    sudo \
    unzip \
    vim \
    && rm -rf /var/lib/apt/lists/*

RUN echo "deb [arch=amd64] http://storage.googleapis.com/bazel-apt stable jdk1.8" | tee /etc/apt/sources.list.d/bazel.list \
	&& curl https://bazel.build/bazel-release.pub.gpg | apt-key add -

RUN export JAVA_HOME="$(dirname $(dirname $(realpath $(which javac))))"

RUN apt-get update && apt-get install -y -q  \
	bazel \
	&& rm -rf /var/lib/apt/lists/*

RUN groupadd -r admin && useradd -r -m -g admin admin && echo "admin ALL=(ALL) NOPASSWD: ALL" >> /etc/sudoers
