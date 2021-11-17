cmake_minimum_required(VERSION 3.10)

project(vecmath)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_library(vm INTERFACE)
add_executable(vmtest "")

add_subdirectory("include/vm")
add_subdirectory("test")