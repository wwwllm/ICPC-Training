# 保留原有的 Ubuntu 24.04 + GCC 15 开发环境，并加入 Go 工具链。
FROM ubuntu:24.04

ARG GO_VERSION=1.26.5
ARG TARGETARCH

ENV DEBIAN_FRONTEND=noninteractive \
    GOPATH=/go \
    PATH=/usr/local/go/bin:/go/bin:${PATH}

# 安装原有 C++ 工具链，以及下载 Go 所需的基础工具。
RUN apt-get update \
    && apt-get install -y software-properties-common ca-certificates curl \
    && add-apt-repository ppa:ubuntu-toolchain-r/test -y \
    && apt-get update \
    && apt-get install -y \
        gcc-15 \
        g++-15 \
        gdb \
        cmake \
        git \
        build-essential \
    && update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-15 100 \
    && update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-15 100 \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# 从 Go 官方发布包安装，并校验不同 CPU 架构对应的 SHA-256。
RUN set -eux; \
    case "${TARGETARCH}" in \
        amd64) GO_SHA256="5c2c3b16caefa1d968a94c1daca04a7ca301a496d9b086e17ad77bb81393f053" ;; \
        arm64) GO_SHA256="fe4789e92b1f33358680864bbe8704289e7bb5fc207d80623c308935bd696d49" ;; \
        *) echo "不支持的 CPU 架构: ${TARGETARCH}" >&2; exit 1 ;; \
    esac; \
    curl --fail --show-error --location --retry 3 \
        --output /tmp/go.tar.gz \
        "https://go.dev/dl/go${GO_VERSION}.linux-${TARGETARCH}.tar.gz"; \
    echo "${GO_SHA256}  /tmp/go.tar.gz" | sha256sum --check -; \
    tar -C /usr/local -xzf /tmp/go.tar.gz; \
    rm /tmp/go.tar.gz; \
    mkdir -p "${GOPATH}/bin"

# 构建阶段即确认两套编译器都可用。
RUN gcc --version \
    && g++ --version \
    && go version
