cmake_minimum_required(VERSION 3.10)
project(PetiteDB)

# 编译设置
set(CMAKE_CXX_STANDARD 11)


# 设置LLVM的路径
set(LLVM_DIR "/home/aichaos/mylab/demodb/llvm-project/build/lib/cmake/llvm")
# 查找LLVM包
find_package(LLVM REQUIRED CONFIG)
# 包含LLVM的头文件
include_directories(${LLVM_INCLUDE_DIRS})
# 链接LLVM库
add_definitions(${LLVM_DEFINITIONS})


# include目录
include_directories(include)

#子目录
add_subdirectory(src)



## 第三方库部分
# 添加sql-parser库
add_subdirectory(third_party/sql-parser)

# 添加 hsql 的头文件路径
include_directories(${CMAKE_SOURCE_DIR}/third_party/sql-parser/src)


# 添加源文件
file(GLOB_RECURSE SOURCES "src/*.cpp")

# 添加可执行文件
add_executable(PetiteDB ${SOURCES})

# 设置链接库路径
link_directories(${CMAKE_SOURCE_DIR}/third_party/sql-parser)

# 链接 hsql 库
target_link_libraries(PetiteDB sqlparser stdc++)
