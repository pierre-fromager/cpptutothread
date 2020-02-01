#!/bin/bash
g++ \
    -std=c++11 -lpthread -Wall -Wextra -march=native -O2 \
    src/main.cpp src/padd.cpp src/psub.cpp src/message.cpp \
    -o build/main
