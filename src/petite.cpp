#include <iostream>
#include "SqlToAst/SqlToAst.h"



// #include "mlir/IR/AsmState.h"
// #include "mlir/IR/BuiltinOps.h"
// #include "mlir/IR/MLIRContext.h"
// #include "mlir/IR/Verifier.h"
// #include "mlir/Parser/Parser.h"
// #include "mlir/Pass/PassManager.h"
// #include "mlir/Transforms/Passes.h"

// #include "llvm/ADT/StringRef.h"
// #include "llvm/Support/CommandLine.h"
// #include "llvm/Support/ErrorOr.h"
// #include "llvm/Support/MemoryBuffer.h"
// #include "llvm/Support/SourceMgr.h"
// #include "llvm/Support/raw_ostream.h"
// #include <memory>
// #include <string>
// #include <system_error>
// #include <utility>

// // 定义inputType枚举
// enum class InputType { MLIR, TOY };

// std::string inputFilename;
// InputType inputType;


// std::unique_ptr<ModuleAST> parseInputFile(const std::string &filename);
// mlir::OwningOpRef<mlir::ModuleOp> mlirGen(mlir::MLIRContext &context, ModuleAST &moduleAST);


// int loadMLIR(llvm::SourceMgr &sourceMgr, mlir::MLIRContext &context,
//              mlir::OwningOpRef<mlir::ModuleOp> &module) {
//     // Handle '.toy' input to the compiler.
//     if (inputType != InputType::MLIR &&
//         !llvm::StringRef(inputFilename).ends_with(".mlir")) {
//         auto moduleAST = parseInputFile(inputFilename);
//         if (!moduleAST)
//         return 6;
//         module = mlirGen(context, *moduleAST);
//         return !module ? 1 : 0;
//     }

//     // Otherwise, the input is '.mlir'.
//     llvm::ErrorOr<std::unique_ptr<llvm::MemoryBuffer>> fileOrErr =
//         llvm::MemoryBuffer::getFileOrSTDIN(inputFilename);
//     if (std::error_code ec = fileOrErr.getError()) {
//         llvm::errs() << "Could not open input file: " << ec.message() << "\n";
//         return -1;
//     }

//     // Parse the input mlir.
//     sourceMgr.AddNewSourceBuffer(std::move(*fileOrErr), llvm::SMLoc());
//     module = mlir::parseSourceFile<mlir::ModuleOp>(sourceMgr, &context);
//     if (!module) {
//         llvm::errs() << "Error can't load file " << inputFilename << "\n";
//         return 3;
//     }
//     return 0;
// }

int main(int argc, char* argv[]) {

    //参数验证
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <path_to_sql_file> <path_to_output_file>" << std::endl;
        return 1;
    }

    std::cout << "SQL 转换 AST 阶段 开始" << std::endl;
    //解析SQL文件 --> AST
    std::string sqlFilePath = argv[1];
    std::string outputFilePath = argv[2];
    SqlToAst sqlToAst(sqlFilePath);

    std::cout << "SQL 转换 AST 阶段 结束" << std::endl;
    

    std::cout << "展示AST"<< std::endl;
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
