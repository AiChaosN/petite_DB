module {
  // 声明外部函数
  llvm.func @fopen(!llvm.ptr<i8>, !llvm.ptr<i8>) -> !llvm.ptr<i8>
  llvm.func @fread(!llvm.ptr<i8>, i64, i64, !llvm.ptr<i8>) -> i64
  llvm.func @fclose(!llvm.ptr<i8>) -> i32
  llvm.func @printf(!llvm.ptr<i8>, ...) -> i32

  func.func @main() -> i32 {
    // 定义文件路径和读取模式的字符串常量
    %file_name = llvm.mlir.global constant internal "example.csv" : !llvm.ptr<array<11 x i8>>
    %mode = llvm.mlir.global constant internal "r" : !llvm.ptr<array<2 x i8>>

    // 打开文件
    %file_ptr = llvm.call @fopen(%file_name, %mode) : (!llvm.ptr<i8>, !llvm.ptr<i8>) -> !llvm.ptr<i8>

    // 检查文件是否成功打开
    %is_null = llvm.icmp "eq"(%file_ptr, llvm.mlir.null()) : !llvm.ptr<i8>
    llvm.cond_br %is_null, ^error, ^read_file

  ^read_file:
    // 分配缓冲区
    %buffer = llvm.alloca !llvm.array<256 x i8> : (i64) -> !llvm.ptr<i8>
    %read_size = llvm.call @fread(%buffer, 1, 256, %file_ptr) : (!llvm.ptr<i8>, i64, i64, !llvm.ptr<i8>) -> i64

    // 输出读取的内容
    llvm.call @printf(%buffer) : (!llvm.ptr<i8>) -> i32

    // 关闭文件
    llvm.call @fclose(%file_ptr) : (!llvm.ptr<i8>) -> i32

    // 返回成功状态码
    return llvm.mlir.constant(0 : i32) : i32

  ^error:
    // 输出错误信息并返回错误状态码
    %err_msg = llvm.mlir.global constant internal "Error opening file\n" : !llvm.ptr<array<19 x i8>>
    llvm.call @printf(%err_msg) : (!llvm.ptr<i8>) -> i32
    return llvm.mlir.constant(-1 : i32) : i32
  }
}
