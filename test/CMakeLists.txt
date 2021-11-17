target_sources(vmtest PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

target_include_directories(vmtest PUBLIC
    ${CMAKE_CURRENT_LIST_DIR})