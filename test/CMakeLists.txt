target_sources(vvmtest PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

target_include_directories(vvmtest PUBLIC
    ${CMAKE_CURRENT_LIST_DIR})
