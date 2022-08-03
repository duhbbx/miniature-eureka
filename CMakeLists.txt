cmake_minimum_required(VERSION 3.22)
project(leetcode)

set(CMAKE_CXX_STANDARD 14)

add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
add_executable(leetcode "宽度优先深度优先/1161. 最大层内元素和.cpp")
