#!/bin/bash

# 目录配置
ROOT_DIR=/home/aichaos/mylab/demodb/llvm-project
llvm_build_root=$ROOT_DIR/build
mlir_src_root=$ROOT_DIR/mlir

# 获取当前脚本的目录
SCRIPT_DIR=$(dirname "$0")
# 设置输出目录为运行脚本目录下的src/
OUTPUT_DIR=${SCRIPT_DIR}/src
# 创建输出目录（如果不存在）
mkdir -p $OUTPUT_DIR

# 设置MLIR包含路径
MLIR_INCLUDE_DIR=$ROOT_DIR/mlir/include



# 运行 RUNNING

echo "使用mlir-tblgen"
${llvm_build_root}/bin/mlir-tblgen ${SCRIPT_DIR}
# /home/aichaos/mylab/demodb/llvm-project/build/bin/mlir-tblgen 

echo "生成完成，输出目录：${OUTPUT_DIR}"

