cmake_minimum_required(VERSION 3.10)
project(PetiteDB)

# 指定C++标准
set(CMAKE_CXX_STANDARD 11)

# 添加sql-parser库
add_subdirectory(third_party/sql-parser)

# 包含目录
include_directories(include)
include_directories(third_party/sql-parser/src)
include_directories(third_party/sql-parser/src/parser)
include_directories(third_party/sql-parser)

# 添加源文件
file(GLOB_RECURSE SOURCES "src/*.cpp")

# 添加可执行文件
add_executable(PetiteDB ${SOURCES})

# 链接sql-parser库
target_link_libraries(PetiteDB hyrise-sql-parser)