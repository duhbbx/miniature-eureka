cmake_minimum_required (VERSION 3.8)
project(leetcode)

set(CMAKE_CXX_STANDARD 14)

# add_definitions(-DUNICODE -D_UNICODE)    #使用UNICODE字符集

# add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>") #使用utf-8文件编码


add_executable(leetcode "未分类/9. 回文数.cpp")