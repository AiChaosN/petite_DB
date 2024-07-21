cmake_minimum_required(VERSION 3.10)
project(Demo)

set(CMAKE_CXX_STANDARD 17)

# 添加 hsql 的头文件路径
include_directories(${CMAKE_SOURCE_DIR}/../third_party/sql-parser/src)

# 添加可执行文件
add_executable(example example.cpp)

# 设置链接库路径
link_directories(${CMAKE_SOURCE_DIR}/../third_party/sql-parser)

# 链接 hsql 库
target_link_libraries(example sqlparser stdc++)

