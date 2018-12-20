cmake_minimum_required(VERSION 2.8)
project(cpp_abc)

set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -march=native -O3 -pthread" )

set(BINARY_DIR ${PROJECT_SOURCE_DIR}/devel)

include_directories(./src)

add_subdirectory(./src)
