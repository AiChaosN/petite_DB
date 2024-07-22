//===- TableTypes.td - Definition of Table Types ----------------*- tablegen -*-===//
//
// This file defines the types for the Petite dialect.
//
//===----------------------------------------------------------------------===//

#ifndef PETITE_Types
#define PETITE_Types

//===----------------------------------------------------------------------===//
// Petite Table Types
//===----------------------------------------------------------------------===//

include "mlir/IR/AttrTypeBase.td"

def TableType : AttrOrTypeDef<"Type", "Table", [], "Type::TypeBase<TableType, Type, TypeStorage>"> {
  let description = [{
    This type represents a table in the database.
  }];
}



#endif // PETITE_Types
