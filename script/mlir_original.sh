#!/bin/bash

# 设置LLVM项目路径
LLVM_PROJECT_PATH="/home/aichaos/mylab/demodb/llvm-project"
MLIR_PATH="$LLVM_PROJECT_PATH/build/bin"

# 设置测试文件路径
test_file="test/mlir"

echo "当前目录 $(pwd)"
echo "将llvm mlir转为 .ll 文件"

# 使用mlir-opt进行转换
"$MLIR_PATH/mlir-opt" --convert-arith-to-llvm --convert-func-to-llvm "$test_file/original.mlir" -o "$test_file/llvm_original.mlir"
"$MLIR_PATH/mlir-translate" --mlir-to-llvmir "$test_file/llvm_original.mlir" > "$test_file/original.ll"

echo "运行jit"
irir
# 运行生成的LLVM IR文件
lli "$test_file/original.ll"
echo "lli 的退出状态是: $?"

# 尝试文件读取
echo "===================="
echo "读取文件"
"$MLIR_PATH/mlir-opt" --convert-arith-to-llvm --convert-func-to-llvm "$test_file/readfile.mlir" -o "$test_file/llvm_readfile.mlir"
"$MLIR_PATH/mlir-translate" --mlir-to-llvmir "$test_file/llvm_readfile.mlir" > "$test_file/readfile.ll"
lli "$test_file/readfile.ll"
