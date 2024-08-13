# 1. 执行版本
cmake_minimum_required(VERSION 3.13) 

# 2. 设置项目名称
project(sql_data)

# 3.参数设置
# 设定c++标准
set(CMAKE_CXX_STANDARD 11)

# 4. 添加源文件
file(GLOB DATA_SRC ${CMAKE_SOURCE_DIR}/src/Database/*.cpp)

message(STATUS "CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
message(STATUS "DATA_SRC: ${DATA_SRC}")

# 6. 生成动态库
add_library(DATA_SRC SHARED ${DATA_SRC})
target_link_libraries(DATA_SRC sqlparser)