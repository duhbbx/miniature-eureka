cmake_minimum_required(VERSION 3.22)
project(leetcode)

set(CMAKE_CXX_STANDARD 14)

add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
#add_executable(leetcode "写着玩儿的/按比例求数对.cpp")
add_executable(leetcode "线段树/线段树的实现.cpp")
