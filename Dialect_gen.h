/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Dialect Declarations                                                       *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|* From: Ops.td                                                               *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

namespace mlir {
namespace petite {

class PetiteDialect : public ::mlir::Dialect {
  explicit PetiteDialect(::mlir::MLIRContext *context);

  void initialize();
  friend class ::mlir::MLIRContext;
public:
  ~PetiteDialect() override;
  static constexpr ::llvm::StringLiteral getDialectNamespace() {
    return ::llvm::StringLiteral("petite");
  }
};
} // namespace petite
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::petite::PetiteDialect)
