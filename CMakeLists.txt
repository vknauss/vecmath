cmake_minimum_required(VERSION 3.10)

project(vecmath)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_library(vvm INTERFACE)
add_executable(vvmtest "")

add_subdirectory("include")
add_subdirectory("test")

target_link_libraries(vvmtest
    vvm)