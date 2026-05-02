# 使用最新的 Ubuntu 作为基础
FROM ubuntu:24.04

# 避免安装过程中的交互提示
ENV DEBIAN_FRONTEND=noninteractive

# 安装基础工具，并添加 GCC 15 的源
RUN apt-get update && apt-get install -y \
    software-properties-common \
    && add-apt-repository ppa:ubuntu-toolchain-r/test -y \
    && apt-get update && apt-get install -y \
    gcc-15 \
    g++-15 \
    gdb \
    cmake \
    git \
    build-essential \
    && apt-get clean

# 将 g++-15 设置为系统的默认 g++
RUN update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-15 100 \
    && update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-15 100