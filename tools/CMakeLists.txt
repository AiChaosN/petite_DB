# sql_to_ast
add_executable(sql_to_ast ${CMAKE_SOURCE_DIR}/tools/sql_to_ast.cpp)
target_link_libraries(sql_to_ast SQL_AST)

# ast_to_mlir
# add_executable(ast_to_mlir ${CMAKE_SOURCE_DIR}/tools/ast_to_mlir.cpp)
# target_link_libraries(ast_to_mlir SQL_AST)
# target_link_libraries(ast_to_mlir DATA_SRC)


