cmake_minimum_required(VERSION 2.8)
project(cpp_abc)

add_compile_options(-std=c++11)

set(BINARY_DIR ${PROJECT_SOURCE_DIR}/devel)

include_directories(./src)

add_subdirectory(./src)
