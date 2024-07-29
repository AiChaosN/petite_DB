cmake_minimum_required(VERSION 3.10)
project(sql-parser)

set(CMAKE_CXX_STANDARD 11)

# 生成词法和语法分析器
find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

BISON_TARGET(SqlParser ${CMAKE_CURRENT_SOURCE_DIR}/src/parser/bison_parser.y ${CMAKE_CURRENT_BINARY_DIR}/bison_parser.cpp)
FLEX_TARGET(SqlLexer ${CMAKE_CURRENT_SOURCE_DIR}/src/parser/flex_lexer.l ${CMAKE_CURRENT_BINARY_DIR}/flex_lexer.cpp)
ADD_FLEX_BISON_DEPENDENCY(SqlLexer SqlParser)

# 包含生成的文件
include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/parser)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/sql)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/util)

file(GLOB SQLPARSER_SRC
    "src/*.cpp"
    "src/sql/*.cpp"
    "src/util/*.cpp"
    "${CMAKE_CURRENT_BINARY_DIR}/*.cpp"
    "$src/parser/*.cpp"
)

add_library(hyrise-sql-parser SHARED ${SQLPARSER_SRC})

target_include_directories(hyrise-sql-parser PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_include_directories(hyrise-sql-parser PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/parser)
target_include_directories(hyrise-sql-parser PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
