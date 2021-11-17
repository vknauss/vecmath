target_sources(vm PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/vm.hpp)

target_include_directories(vm INTERFACE
    ${CMAKE_CURRENT_LIST_DIR})