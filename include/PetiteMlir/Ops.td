//===----------------------------------------------------------------------===//
//
// Defines the operations of the Petite dialect.
//
//===----------------------------------------------------------------------===//


#ifndef PETITE_OPS
#define PETITE_OPS

include "mlir/Interfaces/FunctionInterfaces.td"
include "mlir/IR/SymbolInterfaces.td"
include "mlir/Interfaces/SideEffectInterfaces.td"


include "PetiteMlir/TableTypes.td"
//第一步，定义 petite dialect 在 ODS 框架中的定义 （Operation Definition Specification）
def Petite_Dialect : Dialect {
  let name = "petite";
  let cppNamespace = "::mlir::petite";
}


// 继承 OpBase.td 中的 Op 类，定义了 Petite dialect 的操作的基类
class Petite_Op<string mnemonic, list<Trait> traits = []> :
    Op<Petite_Dialect, mnemonic, traits>;

//===----------------------------------------------------------------------===//
// Petite Operations
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
// ConstantOp
//===----------------------------------------------------------------------===//

// 定义 Petite dialect 中的 constant 操作
// 该操作将一个字面量转换为 SSA 值，数据作为属性附加到操作上

def Petite_DatabaseTableOp : Petite_Op<"database_table", [Pure]> {
  let summary = "Database table operation";
  let description = [{
    Database table operation stores a 2D floating-point tensor in the database. The data is
    attached to the operation as an attribute. For example:

    ```mlir
      %0 = petite.database_table dense<[[1.0, 2.0], [3.0, 4.0]]> : tensor<*xf64>
    ```
  }];

  // The database table operation takes a tensor attribute as the input.
  // let arguments = (ins DenseElementsAttr:$value);

  // The database table operation returns a single value of tensor type.
  let results = (outs F64Tensor:$result);

  // Indicate that the operation has a custom parser and printer method.
  let hasCustomAssemblyFormat = 1;

  // Add custom build methods for the database table operation.
  let builders = [
    // Build a database table operation with a given constant tensor value.
    OpBuilder<(ins "DenseElementsAttr":$value), [{
      build($_builder, $_state, value.getType(), value);
    }]>
  ];

  // Indicate that additional verification for this operation is necessary.
  let hasVerifier = 1;
}




//===----------------------------------------------------------------------===//
// ScanOp
//===----------------------------------------------------------------------===//

def ScanOp : Petite_Op<"scan", [Pure]> {
  let summary = "Scan a table from the database";
  let description = [{
    The "scan" operation retrieves a table from the database by its name.
  }];

  let arguments = (ins StrAttr:$table_name);
  let results = (outs TableType:$result);

  let hasCustomAssemblyFormat = 1;

  let builders = [
    OpBuilder<(ins "StringRef":$table_name), [{
      build($_builder, $_state, TableType::get($_builder.getContext()), $_builder.getStringAttr(table_name));
    }]>
  ];
}


//===----------------------------------------------------------------------===//
// ProjectOp
//===----------------------------------------------------------------------===//

// def ProjectOp : Petite_Op<"project", [Pure]> {
//   let summary = "Project specific columns from a table";
//   let description = [{
//     The "project" operation selects specific columns from a table.
//   }];

//   let arguments = (ins TableType:$table, ArrayAttr:$columns);
//   let results = (outs TableType:$result);

//   let hasCustomAssemblyFormat = 1;

//   let builders = [
//     OpBuilder<(ins "Value":$table, "ArrayRef<Attribute>":$columns), [{
//       build($_builder, $_state, table.getType(), table, $_builder.getArrayAttr(columns));
//     }]>
//   ];
// }


//===----------------------------------------------------------------------===//
// JoinOp
//===----------------------------------------------------------------------===//

// def JoinOp : Petite_Op<"join", [Pure]> {
//   let summary = "Join two tables on specific columns";
//   let description = [{
//     The "join" operation combines two tables based on specific columns.
//   }];

//   let arguments = (ins TableType:$lhs, TableType:$rhs, ArrayAttr:$columns);
//   let results = (outs TableType:$result);

//   let hasCustomAssemblyFormat = 1;

//   let builders = [
//     OpBuilder<(ins "Value":$lhs, "Value":$rhs, "ArrayRef<Attribute>":$columns), [{
//       build($_builder, $_state, lhs.getType(), lhs, rhs, $_builder.getArrayAttr(columns));
//     }]>
//   ];
// }


//===----------------------------------------------------------------------===//
// SelectOp
//===----------------------------------------------------------------------===//

def SelectOp : Petite_Op<"select", [Pure]> {
  let summary = "Select rows from a table based on conditions";
  let description = [{
    The "select" operation retrieves rows from a table that match specific conditions.
  }];

  let arguments = (ins TableType:$table, ArrayAttr:$conditions);
  let results = (outs TableType:$result);

  let hasCustomAssemblyFormat = 1;

  let builders = [
    OpBuilder<(ins "Value":$table, "ArrayRef<Attribute>":$conditions), [{
      build($_builder, $_state, table.getType(), table, $_builder.getArrayAttr(conditions));
    }]>
  ];
}




#endif // PETITE_OPS

