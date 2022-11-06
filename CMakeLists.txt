cmake_minimum_required(VERSION 3.8)
project(leetcode)

set(CMAKE_CXX_STANDARD 17)

# add_definitions(-DUNICODE -D_UNICODE)    #使用UNICODE字符集

# add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>") #使用utf-8文件编码



add_executable("9e0dea7dab614a4699e79e8b452c5705" "图/1203.项目管理[官方的双拓扑排序].cpp")
add_executable("9ed5fb83cff94937b59bbca54a242a5e" "操作模拟/1678. 设计 Goal 解析器.cpp")
add_executable("90cacf18792f4dfa868f8e67ce03131b" "图/1298. 你能从盒子里获得的最大糖果数.cpp")
add_executable("16524909fa7c4958aa87f886000d4241" "图/1368. 使网格图至少有一条有效路径的最小代价.cpp")
add_executable("a3dfe5ee6f6d47028de3949345ff4236" "比赛/2022-11-06 第 318 场周赛/6229. 对数组执行操作.cpp")
add_executable("a5ea0d69c2604d0692459a60ff70de34" "比赛/2022-11-06 第 318 场周赛/6230. 长度为 K 子数组中的最大和.cpp")
add_executable("63fcbfb2ee2848efa4758e44817a94bf" "图/1377. T 秒后青蛙的位置.cpp")