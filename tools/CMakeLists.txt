# sql_to_ast
add_executable(sql_to_ast ${CMAKE_SOURCE_DIR}/tools/sql_to_ast.cpp)
target_link_libraries(sql_to_ast SQL_AST)

# # 设置链接库路径
# link_directories(${CMAKE_SOURCE_DIR}/third_party/sql-parser)
# # 链接 hsql 库
# target_link_libraries(sql_to_ast sqlparser stdc++)

