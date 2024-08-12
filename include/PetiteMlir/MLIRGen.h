// 该部分参考了 MLIR 的官方文档 TOY 语言 的第二章，主要是 Dialect 的定义，包括 Dialect 的声明、Operation 的声明和 Dialect 的实现。

//===- MLIRGen.h - MLIR Generation from a Toy AST -------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file declares a simple interface to perform IR generation targeting MLIR
// from a Module AST for the Toy language.
//
//===----------------------------------------------------------------------===//

#ifndef PETITE__MLIRGEN_H
#define PETITE__MLIRGEN_H

#include <memory>

namespace mlir {
class MLIRContext;
template <typename OpTy>
class OwningOpRef;
class ModuleOp;
} // namespace mlir

namespace petite {
class ModuleAST;

/// Emit IR for the given Petite moduleAST, returns a newly created MLIR module
/// or nullptr on failure.
mlir::OwningOpRef<mlir::ModuleOp> mlirGen(mlir::MLIRContext &context,
                                          ModuleAST &moduleAST);
} // namespace petite

#endif // PETITE__MLIRGEN_H
