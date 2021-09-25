cmake_minimum_required(VERSION 2.8)
set(CMAKE_BUILD_TYPE Debug)
# 声明一个 cmake 工程
project(buffer)
add_executable(buffer main.cpp Buffer.cpp)
