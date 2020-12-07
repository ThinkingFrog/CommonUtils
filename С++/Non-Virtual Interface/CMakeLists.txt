cmake_minimum_required(VERSION 3.10)
project(nvi)

include_directories(include)
file(GLOB SRC src/*.cpp)

add_executable(nvi ${SRC})
