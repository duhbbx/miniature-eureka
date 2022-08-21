cmake_minimum_required (VERSION 3.8)
project(leetcode)

set(CMAKE_CXX_STANDARD 14)

# add_definitions(-DUNICODE -D_UNICODE)	#使用UNICODE字符集

# add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>") #使用utf-8文件编码


add_executable(leetcode  "dfs-bfs/intro2-algo.page334.bfs.cpp")