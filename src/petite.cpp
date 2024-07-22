#include <iostream>
#include "SqlToAst/SqlToAst.h"

int main(int argc, char* argv[]) {

    //参数验证
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <path_to_sql_file> <path_to_output_file>" << std::endl;
        return 1;
    }

    //解析SQL文件 --> AST
    std::string sqlFilePath = argv[1];
    std::string outputFilePath = argv[2];
    SqlToAst sqlToAst(sqlFilePath);

    
    if (sqlToAst.parseSql()) {
        sqlToAst.printAst(outputFilePath);
    } else {
        std::cerr << "Failed to parse SQL file." << std::endl;
        return 1;
    }

    //AST 转 MLIR

    //此处需要实现AST 转 MLIR的代码

    //返回0表示成功



    //MLIR 转 LLVM IR

    //此处需要实现MLIR 转 LLVM IR的代码

    //返回0表示成功



    

    return 0;
}
