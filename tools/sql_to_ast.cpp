#include <iostream>
#include "SqlToAst/SqlToAst.h"

int main(int argc, char* argv[]) {

    //参数验证
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <path_to_sql_file> <path_to_output_file>" << std::endl;
        return 1;
    }

    //==================== SQL 转 AST ====================
    std::cout << "SQL转换AST阶段开始...." << std::endl;
    //解析SQL文件 --> AST
    std::string sqlFilePath = argv[1];
    std::string outputFilePath = argv[2];
    SqlToAst sqlToAst(sqlFilePath);

    std::cout << "SQL转换AST阶段结束!" << std::endl;
    

    std::cout << "已保存AST...OK"<< std::endl;
    if (sqlToAst.parseSql()) {
        sqlToAst.printAst(outputFilePath);
    } else {
        std::cerr << "Failed to parse SQL file." << std::endl;
        return 1;
    }

    //==================== AST 转 MLIR ====================

    //获取AST

    //此处需要实现AST 转 MLIR的代码

    //使用mlirGen函数将AST转换为MLIR

    //返回0表示成功


    //==================== MLIR 转 LLVM IR ====================

    //此处需要实现MLIR 转 LLVM IR的代码

    //返回0表示成功



    return 0;
}
