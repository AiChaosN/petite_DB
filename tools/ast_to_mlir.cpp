#include <iostream>
#include <fstream>
#include <sstream>

#include "SqlToAst/SqlToAst.h"
#include "Database/Database.h"

#include "mlir/IR/AsmState.h"
#include "mlir/IR/BuiltinOps.h"
#include "mlir/IR/MLIRContext.h"
#include "mlir/Parser/Parser.h"

#include "llvm/ADT/StringRef.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/ErrorOr.h"
#include "llvm/Support/MemoryBuffer.h"
#include "llvm/Support/SourceMgr.h"
#include "llvm/Support/raw_ostream.h"

int main(int argc, char* argv[]) {

    //==================== 参数 ====================
    //参数验证
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <path_to_sql_file> <path_to_data> <path_to_output_file>" << std::endl;
        return 1;
    }

    //==================== SQL 转 AST ====================
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
    //==================== AST 转 MLIR ====================

    // 读取数据库
    std::string filename = argv[3];
    std::ifstream istream{filename};
    std::cout << "Reading file: " << filename << std::endl;

    //读取文件内容


    //获取AST
    auto petiteAst = sqlToAst.getResult();
    std::cout << "AST结构获取完毕: " << filename << std::endl;

    //此处需要实现AST 转 MLIR的代码
    // mlir::MLIRContext context;
    // // Load our Dialect in this MLIR Context.
    // context.getOrLoadDialect<mlir::petite::PetiteDialect>();

    // //使用mlirGen函数将AST转换为MLIR
    // mlir::OwningOpRef<mlir::ModuleOp> module = mlirGen(context, *moduleAST);

    // module->dump();
    //返回0表示成功

    //==================== MLIR 转 LLVM IR ====================

    //此处需要实现MLIR 转 LLVM IR的代码

    //返回0表示成功



    return 0;
}
