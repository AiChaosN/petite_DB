// PetiteDialect.td - Define the petite dialect

include "mlir/IR/OpBase.td"
include "mlir/IR/Dialect.td"

// 定义方言
def PetiteDialect : Dialect {
  let name = "petite";
  let cppNamespace = "petite";
}

// 定义类型
def Petite_String : Type<"Petite_String"> {
  let cppNamespace = "::petite";
}

def Petite_Int : Type<"Petite_Int"> {
  let cppNamespace = "::petite";
}

def Petite_Float : Type<"Petite_Float"> {
  let cppNamespace = "::petite";
}

// 定义操作

// Scan 操作
def Petite_ScanOp : Op<"scan", [NoSideEffect]> {
  let summary = "Scan a table";
  let description = [{
    The `scan` operation scans a table.
  }];
  
  let arguments = (ins
    StrAttr:$tableName  // 表名
  );

  let results = (outs Petite_String:$result);
}

// Project 操作
def Petite_ProjectOp : Op<"project", [NoSideEffect]> {
  let summary = "Project specific columns";
  let description = [{
    The `project` operation projects specific columns from a table.
  }];
  
  let arguments = (ins
    Petite_String:$input,          // 输入表
    ArrayAttr<StrAttr>:$columns   // 列名数组
  );

  let results = (outs Petite_String:$result);
}

// Join 操作
def Petite_JoinOp : Op<"join", [NoSideEffect]> {
  let summary = "Join two tables";
  let description = [{
    The `join` operation joins two tables.
  }];
  
  let arguments = (ins
    Petite_String:$left,           // 左表
    Petite_String:$right,          // 右表
    ArrayAttr<StrAttr>:$columns   // 列名数组
  );

  let results = (outs Petite_String:$result);
}

// Select 操作
def Petite_SelectOp : Op<"select", [NoSideEffect]> {
  let summary = "Select rows based on condition";
  let description = [{
    The `select` operation selects rows based on a condition.
  }];
  
  let arguments = (ins
    Petite_String:$input,          // 输入表
    StrAttr:$condition            // 条件
  );

  let results = (outs Petite_String:$result);
}

// Example of an operation using integer and float types

// Add 操作
def Petite_AddOp : Op<"add", [NoSideEffect]> {
  let summary = "Add two numbers";
  let description = [{
    The `add` operation adds two numbers.
  }];
  
  let arguments = (ins
    Petite_Int:$lhs,             // 左操作数
    Petite_Int:$rhs              // 右操作数
  );

  let results = (outs Petite_Int:$result);
}

// Multiply 操作
def Petite_MulOp : Op<"mul", [NoSideEffect]> {
  let summary = "Multiply two numbers";
  let description = [{
    The `mul` operation multiplies two numbers.
  }];
  
  let arguments = (ins
    Petite_Float:$lhs,           // 左操作数
    Petite_Float:$rhs            // 右操作数
  );

  let results = (outs Petite_Float:$result);
}
