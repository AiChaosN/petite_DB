// 该部分参考 MLIR Tutorial Toy 语言 中的Ch2，主要是Dialect的定义，包括Dialect的声明、Operation的声明和Dialect的实现。

//===- Dialect.h - Dialect definition for the PetiteMlir IR ----------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file implements the IR Dialect for the PetiteMlir language.
// See docs/Tutorials/PetiteMlir/Ch-2.md for more information.
//
//===----------------------------------------------------------------------===//

#ifndef PETITE_DIALECT_H
#define PETITE_DIALECT_H

#include "mlir/Bytecode/BytecodeOpInterface.h"
#include "mlir/IR/Dialect.h"
#include "mlir/IR/SymbolTable.h"
#include "mlir/Interfaces/CallInterfaces.h"
#include "mlir/Interfaces/FunctionInterfaces.h"
#include "mlir/Interfaces/SideEffectInterfaces.h"

/// Include the auto-generated header file containing the declaration of the PetiteMlir
/// dialect.
#include "PetiteMlir/Dialect.h.inc"

/// Include the auto-generated header file containing the declarations of the
/// PetiteMlir operations.
#define GET_OP_CLASSES
#include "PetiteMlir/Ops.h.inc"

#endif // PETITE_DIALECT_H
