cmake_minimum_required(VERSION 3.5)
project(daggr)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)
include_directories(/usr/local/include)
file(GLOB daggr_src src/*.cc include/*)
add_library(daggr OBJECT ${daggr_src})

add_executable(test_graph test.cc $<TARGET_OBJECTS:daggr> )