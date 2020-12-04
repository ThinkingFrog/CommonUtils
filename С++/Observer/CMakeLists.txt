cmake_minimum_required(VERSION 3.10)
project(Observer)

include_directories(include)
file(GLOB SRC src/*.cpp)

add_executable(observer ${SRC})