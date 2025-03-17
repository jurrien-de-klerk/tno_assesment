FROM debian:12.8

#
# Setup developer user
#
ARG USER_ID=1000
ARG GROUP_ID=1000
RUN groupadd --gid ${GROUP_ID} developer &&\
    useradd --no-log-init --create-home --uid ${USER_ID} --gid ${GROUP_ID} developer

#
# Install tools
#
RUN apt update
RUN apt install -y cmake g++ gdb wget git clang-tidy clang-format

# ENV CC=/usr/bin/clang-18
# ENV CXX=/usr/bin/clang++-18

#
# Install librariers
#
# GTest/GMock
WORKDIR /tmp
RUN git clone https://github.com/google/googletest.git --depth 1
WORKDIR /tmp/googletest
RUN cmake -B ./build -S . &&\
    cmake --build ./build &&\
    cmake --install ./build

USER developer
