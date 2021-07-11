cmake_minimum_required(VERSION 3.0)
project(Rational)
set(CMAKE_CXX_STANDARD 11)

include_directories(include)
include_directories(src)
file(GLOB SRC src/*.cpp)
file(GLOB TEST test/*.cpp)

add_executable(${PROJECT_NAME} ${SRC} ${TEST})