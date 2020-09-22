cmake_minimum_required(VERSION 3.0)
project(AVLTree)

include_directories(include)
file(GLOB SRC src/*.c)

add_executable(Main ${SRC})