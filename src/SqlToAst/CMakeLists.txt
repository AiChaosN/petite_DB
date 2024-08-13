# 1. 执行版本
cmake_minimum_required(VERSION 3.13) 

# 2. 设置项目名称
project(sql_ast)

# 3.参数设置
# 设定c++标准
set(CMAKE_CXX_STANDARD 11)

# 4. 添加源文件
file(GLOB SQL_AST_SRC ${CMAKE_SOURCE_DIR}/src/SqlToAst/*.cpp ${CMAKE_SOURCE_DIR}/third_party/sql-parser/src/sql/*.cpp)

message(STATUS "CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
message(STATUS "SQL_AST: ${SQL_AST_SRC}")

# 6. 生成动态库
add_library(SQL_AST SHARED ${SQL_AST_SRC})
target_link_libraries(SQL_AST sqlparser)