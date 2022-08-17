cmake_minimum_required(VERSION 3.22)
project(leetcode)

set(CMAKE_CXX_STANDARD 14)

add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
add_executable(leetcode "未知题型/奇偶分开排序.cpp")
