------------- Classes -----------------
class 0DTensorOf<list<Type> 0DTensorOf:allowedTypes = ?> {	// Constraint TypeConstraint Type ShapedContainerType RankedTensorOf TensorRankOf
  Pred predicate = And<0: [anonymous_122, Concat<0: "[](::mlir::Type elementType) { return ", 1: SubstLeaves<0: "$_self", 1: "elementType", 2: AnyTypeOf<0: 0DTensorOf:allowedTypes>.predicate>, 2: "; }(::llvm::cast<::mlir::ShapedType>($_self).getElementType())">]>;
  string summary = !strconcat("0D tensor", !strconcat(" of ", !strconcat(AnyTypeOf<0: 0DTensorOf:allowedTypes>.summary, " values")));
  string cppClassName = "::mlir::RankedTensorType";
  string description = "";
  string builderCall = "";
}
class 1DTensorOf<list<Type> 1DTensorOf:allowedTypes = ?> {	// Constraint TypeConstraint Type ShapedContainerType RankedTensorOf TensorRankOf
  Pred predicate = And<0: [anonymous_126, Concat<0: "[](::mlir::Type elementType) { return ", 1: SubstLeaves<0: "$_self", 1: "elementType", 2: AnyTypeOf<0: 1DTensorOf:allowedTypes>.predicate>, 2: "; }(::llvm::cast<::mlir::ShapedType>($_self).getElementType())">]>;
  string summary = !strconcat("1D tensor", !strconcat(" of ", !strconcat(AnyTypeOf<0: 1DTensorOf:allowedTypes>.summary, " values")));
  string cppClassName = "::mlir::RankedTensorType";
  string description = "";
  string builderCall = "";
}
class 2DTensorOf<list<Type> 2DTensorOf:allowedTypes = ?> {	// Constraint TypeConstraint Type ShapedContainerType RankedTensorOf TensorRankOf
  Pred predicate = And<0: [anonymous_130, Concat<0: "[](::mlir::Type elementType) { return ", 1: SubstLeaves<0: "$_self", 1: "elementType", 2: AnyTypeOf<0: 2DTensorOf:allowedTypes>.predicate>, 2: "; }(::llvm::cast<::mlir::ShapedType>($_self).getElementType())">]>;
  string summary = !strconcat("2D tensor", !strconcat(" of ", !strconcat(AnyTypeOf<0: 2DTensorOf:allowedTypes>.summary, " values")));
  string cppClassName = "::mlir::RankedTensorType";
  string description = "";
  string builderCall = "";
}
class 3DTensorOf<list<Type> 3DTensorOf:allowedTypes = ?> {	// Constraint TypeConstraint Type ShapedContainerType RankedTensorOf TensorRankOf
  Pred predicate = And<0: [anonymous_134, Concat<0: "[](::mlir::Type elementType) { return ", 1: SubstLeaves<0: "$_self", 1: "elementType", 2: AnyTypeOf<0: 3DTensorOf:allowedTypes>.predicate>, 2: "; }(::llvm::cast<::mlir::ShapedType>($_self).getElementType())">]>;
  string summary = !strconcat("3D tensor", !strconcat(" of ", !strconcat(AnyTypeOf<0: 3DTensorOf:allowedTypes>.summary, " values")));
  string cppClassName = "::mlir::RankedTensorType";
  string description = "";
  string builderCall = "";
}
class 4DTensorOf<list<Type> 4DTensorOf:allowedTypes = ?> {	// Constraint TypeConstraint Type ShapedContainerType RankedTensorOf TensorRankOf
  Pred predicate = And<0: [anonymous_138, Concat<0: "[](::mlir::Type elementType) { return ", 1: SubstLeaves<0: "$_self", 1: "elementType", 2: AnyTypeOf<0: 4DTensorOf:allowedTypes>.predicate>, 2: "; }(::llvm::cast<::mlir::ShapedType>($_self).getElementType())">]>;
  string summary = !strconcat("4D tensor", !strconcat(" of ", !strconcat(AnyTypeOf<0: 4DTensorOf:allowedTypes>.summary, " values")));
  string cppClassName = "::mlir::RankedTensorType";
  string description = "";
  string builderCall = "";
}
class APFloatParameter<string APFloatParameter:desc = ?> {	// AttrOrTypeParameter
  string allocator = ?;
  string comparator = "$_lhs.bitwiseIsEqual($_rhs)";
  string cppType = "::llvm::APFloat";
  string cppAccessorType = "::llvm::APFloat";
  string cppStorageType = cppType;
  string convertFromStorage = "$_self";
  string summary = APFloatParameter:desc;
  string syntax = ?;
  string parser = ?;
  string printer = ?;
  string defaultValue = "";
}
class AllAttrOf<list<AttrConstraint> AllAttrOf:constraints = ?> {	// Constraint AttrConstraint
  Pred predicate = And<0: !listconcat([!head(AllAttrOf:constraints).predicate], !foreach(pred, !tail(AllAttrOf:constraints), pred.predicate))>;
  string summary = !interleave(!foreach(con, AllAttrOf:constraints, con.summary), " and ");
}
class AllElementCountsMatch<list<string> AllElementCountsMatch:names = ?> {	// Trait PredTrait PredOpTrait AllMatchSameOperatorTrait
  string summary = !strconcat("all of {", !strconcat(!interleave(AllElementCountsMatch:names, ", "), "} have same element count"));
  Pred predicate = AllMatchSameOperatorPred<0: AllElementCountsMatch:names, 1: "llvm::cast<::mlir::ShapedType>($_self.getType()).getNumElements()">;
  list<Trait> dependentTraits = [];
  list<string> values = AllElementCountsMatch:names;
}
class AllElementTypesMatch<list<string> AllElementTypesMatch:names = ?> {	// Trait PredTrait PredOpTrait AllMatchSameOperatorTrait
  string summary = !strconcat("all of {", !strconcat(!interleave(AllElementTypesMatch:names, ", "), "} have same element type"));
  Pred predicate = AllMatchSameOperatorPred<0: AllElementTypesMatch:names, 1: "getElementTypeOrSelf($_self)">;
  list<Trait> dependentTraits = [];
  list<string> values = AllElementTypesMatch:names;
}
class AllMatch<list<string> AllMatch:values = ?, string AllMatch:summary = ?> {	// Trait PredTrait PredOpTrait
  string summary = AllMatch:summary;
  Pred predicate = AllMatchPred<0: AllMatch:values>;
  list<Trait> dependentTraits = [];
}
class AllMatchPred<list<string> AllMatchPred:values = ?> {	// Pred CPred
  string predExpr = !strconcat("(", !strconcat(!if(!lt(!size(AllMatchPred:values), 2), "true", !strconcat(!foldl(!strconcat("(", !strconcat(!head(AllMatchPred:values), ")")), !tail(AllMatchPred:values), acc, v, !strconcat(acc, !strconcat(" == (", !strconcat(v, !strconcat(") && (", !strconcat(v, ")")))))), !strconcat(" == (", !strconcat(!head(AllMatchPred:values), ")")))), ")"));
}
class AllMatchSameOperatorPred<list<string> AllMatchSameOperatorPred:names = ?, string AllMatchSameOperatorPred:operator = ?> {	// Pred CPred AllMatchPred
  string predExpr = !strconcat("(", !strconcat(!if(!lt(!size(!foreach(n, AllMatchSameOperatorPred:names, !subst("$_self", !strconcat("$", n), AllMatchSameOperatorPred:operator))), 2), "true", !strconcat(!foldl(!strconcat("(", !strconcat(!head(!foreach(n, AllMatchSameOperatorPred:names, !subst("$_self", !strconcat("$", n), AllMatchSameOperatorPred:operator))), ")")), !tail(!foreach(n, AllMatchSameOperatorPred:names, !subst("$_self", !strconcat("$", n), AllMatchSameOperatorPred:operator))), acc, v, !strconcat(acc, !strconcat(" == (", !strconcat(v, !strconcat(") && (", !strconcat(v, ")")))))), !strconcat(" == (", !strconcat(!head(!foreach(n, AllMatchSameOperatorPred:names, !subst("$_self", !strconcat("$", n), AllMatchSameOperatorPred:operator))), ")")))), ")"));
}
class AllMatchSameOperatorTrait<list<string> AllMatchSameOperatorTrait:names = ?, string AllMatchSameOperatorTrait:operator = ?, string AllMatchSameOperatorTrait:summary = ?> {	// Trait PredTrait PredOpTrait
  string summary = !strconcat("all of {", !strconcat(!interleave(AllMatchSameOperatorTrait:names, ", "), !strconcat("} have same ", AllMatchSameOperatorTrait:summary)));
  Pred predicate = AllMatchSameOperatorPred<0: AllMatchSameOperatorTrait:names, 1: AllMatchSameOperatorTrait:operator>;
  list<Trait> dependentTraits = [];
  list<string> values = AllMatchSameOperatorTrait:names;
}
class AllOfType<list<Type> AllOfType:allowedTypeList = ?, string AllOfType:summary = "", string AllOfType:cppClassName = "::mlir::Type"> {	// Constraint TypeConstraint Type
  Pred predicate = And<0: !foreach(allowedType, AllOfType:allowedTypeList, allowedType.predicate)>;
  string summary = !if(!eq(AllOfType:summary, ""), !interleave(!foreach(t, AllOfType:allowedTypeList, t.summary), " and "), AllOfType:summary);
  string cppClassName = AllOfType:cppClassName;
  string description = "";
  string builderCall = "";
  list<Type> allowedTypes = AllOfType:allowedTypeList;
}
class AllRanksMatch<list<string> AllRanksMatch:names = ?> {	// Trait PredTrait PredOpTrait AllMatchSameOperatorTrait
  string summary = !strconcat("all of {", !strconcat(!interleave(AllRanksMatch:names, ", "), "} have same rank"));
  Pred predicate = AllMatchSameOperatorPred<0: AllRanksMatch:names, 1: "::llvm::cast<::mlir::ShapedType>($_self.getType()).getRank()">;
  list<Trait> dependentTraits = [];
  list<string> values = AllRanksMatch:names;
}
class AllShapesMatch<list<string> AllShapesMatch:names = ?> {	// Trait PredTrait PredOpTrait AllMatchSameOperatorTrait
  string summary = !strconcat("all of {", !strconcat(!interleave(AllShapesMatch:names, ", "), "} have same shape"));
  Pred predicate = AllMatchSameOperatorPred<0: AllShapesMatch:names, 1: "::llvm::cast<::mlir::ShapedType>($_self.getType()).getShape()">;
  list<Trait> dependentTraits = [];
  list<string> values = AllShapesMatch:names;
}
class AllTypesMatch<list<string> AllTypesMatch:names = ?> {	// Trait PredTrait PredOpTrait AllMatchSameOperatorTrait
  string summary = !strconcat("all of {", !strconcat(!interleave(AllTypesMatch:names, ", "), "} have same type"));
  Pred predicate = AllMatchSameOperatorPred<0: AllTypesMatch:names, 1: "$_self.getType()">;
  list<Trait> dependentTraits = [];
  list<string> values = AllTypesMatch:names;
}
class And<list<Pred> And:children = ?> {	// Pred CombinedPred
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = And:children;
}
class AnyAttrOf<list<Attr> AnyAttrOf:allowedAttrs = ?, string AnyAttrOf:summary = "", string AnyAttrOf:cppClassName = "::mlir::Attribute", string AnyAttrOf:fromStorage = "$_self"> {	// Constraint AttrConstraint Attr
  Pred predicate = Or<0: !foreach(allowedattr, AnyAttrOf:allowedAttrs, allowedattr.predicate)>;
  string summary = !if(!eq(AnyAttrOf:summary, ""), !interleave(!foreach(t, AnyAttrOf:allowedAttrs, t.summary), " or "), AnyAttrOf:summary);
  string storageType = ?;
  string returnType = AnyAttrOf:cppClassName;
  string convertFromStorage = AnyAttrOf:fromStorage;
  string constBuilderCall = ?;
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class AnyI<int AnyI:width = ?> {	// Constraint TypeConstraint Type
  Pred predicate = CPred<0: !strconcat("$_self.isInteger(", !strconcat(!cast<string>(AnyI:width), ")"))>;
  string summary = !strconcat(!cast<string>(AnyI:width), "-bit integer");
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
  int bitwidth = AnyI:width;
}
class AnyIntOfWidths<list<int> AnyIntOfWidths:widths = ?> {	// Constraint TypeConstraint Type AnyTypeOf
  Pred predicate = Or<0: !foreach(allowedtype, !foreach(w, AnyIntOfWidths:widths, AnyI<0: w>), allowedtype.predicate)>;
  string summary = !if(!eq(!strconcat(!interleave(AnyIntOfWidths:widths, "/"), "-bit integer"), ""), !interleave(!foreach(t, !foreach(w, AnyIntOfWidths:widths, AnyI<0: w>), t.summary), " or "), !strconcat(!interleave(AnyIntOfWidths:widths, "/"), "-bit integer"));
  string cppClassName = "::mlir::IntegerType";
  string description = "";
  string builderCall = "";
  list<Type> allowedTypes = !foreach(w, AnyIntOfWidths:widths, AnyI<0: w>);
}
class AnyIntegerAttrBase<AnyI AnyIntegerAttrBase:attrValType = ?, string AnyIntegerAttrBase:descr = ?> {	// Constraint AttrConstraint Attr TypedAttrBase
  Pred predicate = And<0: [anonymous_191, CPred<0: !strconcat("::llvm::cast<::mlir::IntegerAttr>($_self).getType().isInteger(", !strconcat(!cast<string>(AnyIntegerAttrBase:attrValType.bitwidth), ")"))>]>;
  string summary = AnyIntegerAttrBase:descr;
  string storageType = "::mlir::IntegerAttr";
  code returnType = [{ ::llvm::APInt }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = ?;
  string defaultValue = ?;
  Type valueType = AnyIntegerAttrBase:attrValType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class AnyMatchOperatorPred<list<string> AnyMatchOperatorPred:names = ?, string AnyMatchOperatorPred:operator = ?> {	// Pred CPred AnyPred
  string predExpr = !strconcat("(", !strconcat(!if(!lt(!size(!foreach(n, AnyMatchOperatorPred:names, !subst("$_self", !strconcat("$", n), AnyMatchOperatorPred:operator))), 1), "false", !foldl(!strconcat("(", !strconcat(!head(!foreach(n, AnyMatchOperatorPred:names, !subst("$_self", !strconcat("$", n), AnyMatchOperatorPred:operator))), ")")), !tail(!foreach(n, AnyMatchOperatorPred:names, !subst("$_self", !strconcat("$", n), AnyMatchOperatorPred:operator))), acc, v, !strconcat(acc, !strconcat(" || (", !strconcat(v, ")"))))), ")"));
}
class AnyMatchOperatorTrait<list<string> AnyMatchOperatorTrait:names = ?, string AnyMatchOperatorTrait:operator = ?, string AnyMatchOperatorTrait:summary = ?> {	// Trait PredTrait PredOpTrait
  string summary = !strconcat("any of {", !strconcat(!interleave(AnyMatchOperatorTrait:names, ", "), !strconcat("} has ", AnyMatchOperatorTrait:summary)));
  Pred predicate = AnyMatchOperatorPred<0: AnyMatchOperatorTrait:names, 1: AnyMatchOperatorTrait:operator>;
  list<Trait> dependentTraits = [];
  list<string> values = AnyMatchOperatorTrait:names;
}
class AnyPred<list<string> AnyPred:values = ?> {	// Pred CPred
  string predExpr = !strconcat("(", !strconcat(!if(!lt(!size(AnyPred:values), 1), "false", !foldl(!strconcat("(", !strconcat(!head(AnyPred:values), ")")), !tail(AnyPred:values), acc, v, !strconcat(acc, !strconcat(" || (", !strconcat(v, ")"))))), ")"));
}
class AnyStridedMemRefOfRank<int AnyStridedMemRefOfRank:rank = ?> {	// Constraint TypeConstraint Type AllOfType
  Pred predicate = And<0: [anonymous_158, MemRefRankOf<0: [AnyType], 1: [AnyStridedMemRefOfRank:rank]>.predicate]>;
  string summary = !if(!eq(!strconcat("strided memref of any type values", !strconcat(" of rank ", !cast<string>(AnyStridedMemRefOfRank:rank))), ""), !interleave(["strided memref of any type values", MemRefRankOf<0: [AnyType], 1: [AnyStridedMemRefOfRank:rank]>.summary], " and "), !strconcat("strided memref of any type values", !strconcat(" of rank ", !cast<string>(AnyStridedMemRefOfRank:rank))));
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
  list<Type> allowedTypes = [AnyStridedMemRef, MemRefRankOf<0: [AnyType], 1: [AnyStridedMemRefOfRank:rank]>];
}
class AnyTypeOf<list<Type> AnyTypeOf:allowedTypeList = ?, string AnyTypeOf:summary = "", string AnyTypeOf:cppClassName = "::mlir::Type"> {	// Constraint TypeConstraint Type
  Pred predicate = Or<0: !foreach(allowedtype, AnyTypeOf:allowedTypeList, allowedtype.predicate)>;
  string summary = !if(!eq(AnyTypeOf:summary, ""), !interleave(!foreach(t, AnyTypeOf:allowedTypeList, t.summary), " or "), AnyTypeOf:summary);
  string cppClassName = AnyTypeOf:cppClassName;
  string description = "";
  string builderCall = "";
  list<Type> allowedTypes = AnyTypeOf:allowedTypeList;
}
class Arg<Constraint Arg:constraint = ?, string Arg:desc = "", list<OpVariableDecorator> Arg:decorators = []> {	// OpVariable
  Constraint constraint = Arg:constraint;
  string summary = Arg:desc;
  list<OpVariableDecorator> decorators = Arg:decorators;
}
class Arguments<dag Arguments:args = ?> {
  dag arguments = Arguments:args;
}
class ArrayAttrBase<Pred ArrayAttrBase:condition = ?, string ArrayAttrBase:summary = ?> {	// Constraint AttrConstraint Attr
  Pred predicate = ArrayAttrBase:condition;
  string summary = ArrayAttrBase:summary;
  code storageType = [{ ::mlir::ArrayAttr }];
  code returnType = [{ ::mlir::ArrayAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = "$_builder.getArrayAttr($0)";
  string defaultValue = ?;
  Type valueType = NoneType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class ArrayCount<int ArrayCount:n = ?> {	// Constraint AttrConstraint
  Pred predicate = CPred<0: !strconcat("::llvm::cast<::mlir::ArrayAttr>($_self).size() == ", !cast<string>(ArrayCount:n))>;
  string summary = !strconcat("with exactly ", !strconcat(!cast<string>(ArrayCount:n), " elements"));
}
class ArrayMaxCount<int ArrayMaxCount:n = ?> {	// Constraint AttrConstraint
  Pred predicate = CPred<0: !strconcat("::llvm::cast<::mlir::ArrayAttr>($_self).size() <= ", !cast<string>(ArrayMaxCount:n))>;
  string summary = !strconcat("with at most ", !strconcat(!cast<string>(ArrayMaxCount:n), " elements"));
}
class ArrayMinCount<int ArrayMinCount:n = ?> {	// Constraint AttrConstraint
  Pred predicate = CPred<0: !strconcat("::llvm::cast<::mlir::ArrayAttr>($_self).size() >= ", !cast<string>(ArrayMinCount:n))>;
  string summary = !strconcat("with at least ", !strconcat(!cast<string>(ArrayMinCount:n), " elements"));
}
class ArrayOfAttr<Dialect ArrayOfAttr:dialect = ?, string ArrayOfAttr:name = ?, string ArrayOfAttr:attrMnemonic = ?, string ArrayOfAttr:eltName = ?, list<Trait> ArrayOfAttr:traits = []> {	// Constraint AttrConstraint Attr DialectAttr AttrOrTypeDef AttrDef
  Pred predicate = CPred<0: !strconcat("::llvm::isa<", !strconcat(dialect.cppNamespace, !strconcat("::", !strconcat(cppClassName, ">($_self)"))))>;
  string summary = "";
  string storageType = !strconcat(dialect.cppNamespace, !strconcat("::", !strconcat(ArrayOfAttr:name, "Attr")));
  string returnType = !strconcat("::llvm::ArrayRef<", !strconcat(ArrayOfAttr:eltName, ">"));
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = !strconcat("$_builder.getAttr<", !strconcat(ArrayOfAttr:name, "Attr>($0)"));
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = ArrayOfAttr:dialect.cppNamespace;
  string description = "";
  Dialect dialect = ArrayOfAttr:dialect;
  string cppBaseClassName = "::mlir::Attribute";
  string storageClass = !strconcat(ArrayOfAttr:name, "AttrStorage");
  string storageNamespace = "detail";
  bit genStorageClass = 1;
  bit hasStorageCustomConstructor = 0;
  dag parameters = (ins OptionalArrayRefParameter<0: ArrayOfAttr:eltName>:$value);
  list<AttrOrTypeBuilder> builders = ?;
  list<Trait> traits = ArrayOfAttr:traits;
  string mnemonic = ArrayOfAttr:attrMnemonic;
  string assemblyFormat = "`[` (`]`) : ($value^ `]`)?";
  bit hasCustomAssemblyFormat = 0;
  bit genAccessors = 1;
  bit skipDefaultBuilders = 0;
  bit genVerifyDecl = 0;
  string extraClassDeclaration = !strconcat([{
    auto begin() const { return getValue().begin(); }
    auto end() const { return getValue().end(); }
    bool empty() const { return getValue().empty(); }
    size_t size() const { return getValue().size(); }
    auto &front() const { return getValue().front(); }
    auto &back() const { return getValue().back(); }
    auto &operator[](size_t index) { return getValue()[index]; }
    operator }], !strconcat(returnType, [{() const { return getValue(); }
  }]));
  code extraClassDefinition = [{}];
  string cppClassName = !strconcat(ArrayOfAttr:name, "Attr");
  string cppType = !strconcat(dialect.cppNamespace, !strconcat("::", cppClassName));
  string attrName = !strconcat(dialect.name, !strconcat(".", mnemonic));
}
class ArrayProperty<string ArrayProperty:storageTypeParam = "", int ArrayProperty:n = ?, string ArrayProperty:desc = ""> {	// Property
  string summary = ArrayProperty:desc;
  string description = "";
  string storageType = !strconcat(ArrayProperty:storageTypeParam, !strconcat("[", !strconcat(!cast<string>(ArrayProperty:n), "]")));
  string interfaceType = !strconcat("::llvm::ArrayRef<", !strconcat(ArrayProperty:storageTypeParam, ">"));
  string convertFromStorage = "$_storage";
  string assignToStorage = "::llvm::copy($_value, $_storage)";
  code convertToAttribute = [{
    convertToAttribute($_ctxt, $_storage)
  }];
  code convertFromAttribute = [{
    return convertFromAttribute($_storage, $_attr, $_diag);
  }];
  code hashProperty = [{
    llvm::hash_value($_storage);
  }];
  code writeToMlirBytecode = [{
    writeToMlirBytecode($_writer, $_storage)
  }];
  code readFromMlirBytecode = [{
    if (::mlir::failed(readFromMlirBytecode($_reader, $_storage)))
      return ::mlir::failure();
  }];
  string defaultValue = ?;
}
class ArrayRefOfSelfAllocationParameter<string ArrayRefOfSelfAllocationParameter:arrayOf = ?, string ArrayRefOfSelfAllocationParameter:desc = ?> {	// AttrOrTypeParameter
  string allocator = !strconcat([{
    llvm::SmallVector<}], !strconcat(ArrayRefOfSelfAllocationParameter:arrayOf, !strconcat([{, 4> tmpFields;
    for (size_t i = 0, e = $_self.size(); i < e; ++i)
      tmpFields.push_back($_self[i].allocateInto($_allocator));
    $_dst = $_allocator.copyInto(ArrayRef<}], !strconcat(ArrayRefOfSelfAllocationParameter:arrayOf, [{>(tmpFields));
  }]))));
  string comparator = ?;
  string cppType = !strconcat("::llvm::ArrayRef<", !strconcat(ArrayRefOfSelfAllocationParameter:arrayOf, ">"));
  string cppAccessorType = !strconcat("::llvm::ArrayRef<", !strconcat(ArrayRefOfSelfAllocationParameter:arrayOf, ">"));
  string cppStorageType = cppType;
  string convertFromStorage = "$_self";
  string summary = ArrayRefOfSelfAllocationParameter:desc;
  string syntax = ?;
  string parser = ?;
  string printer = ?;
  string defaultValue = "";
}
class ArrayRefParameter<string ArrayRefParameter:arrayOf = ?, string ArrayRefParameter:desc = ""> {	// AttrOrTypeParameter
  code allocator = [{$_dst = $_allocator.copyInto($_self);}];
  string comparator = ?;
  string cppType = !strconcat("::llvm::ArrayRef<", !strconcat(ArrayRefParameter:arrayOf, ">"));
  string cppAccessorType = !strconcat("::llvm::ArrayRef<", !strconcat(ArrayRefParameter:arrayOf, ">"));
  string cppStorageType = !strconcat("::llvm::SmallVector<", !strconcat(ArrayRefParameter:arrayOf, ">"));
  string convertFromStorage = "$_self";
  string summary = ArrayRefParameter:desc;
  string syntax = ?;
  string parser = ?;
  string printer = ?;
  string defaultValue = "";
}
class Attr<Pred Attr:condition = ?, string Attr:summary = ""> {	// Constraint AttrConstraint
  Pred predicate = Attr:condition;
  string summary = Attr:summary;
  string storageType = ?;
  string returnType = ?;
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = ?;
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class AttrBuilder<dag AttrBuilder:parameters = ?, string AttrBuilder:bodyCode = "", string AttrBuilder:returnType = ""> {	// AttrOrTypeBuilder
  dag dagParams = AttrBuilder:parameters;
  string body = AttrBuilder:bodyCode;
  string returnType = AttrBuilder:returnType;
  bit hasInferredContextParam = 0;
}
class AttrBuilderWithInferredContext<dag AttrBuilderWithInferredContext:parameters = ?, string AttrBuilderWithInferredContext:bodyCode = "", string AttrBuilderWithInferredContext:returnType = ""> {	// AttrOrTypeBuilder TypeBuilder AttrOrTypeBuilderWithInferredContext
  dag dagParams = AttrBuilderWithInferredContext:parameters;
  string body = AttrBuilderWithInferredContext:bodyCode;
  string returnType = AttrBuilderWithInferredContext:returnType;
  bit hasInferredContextParam = 1;
}
class AttrConstraint<Pred AttrConstraint:predicate = ?, string AttrConstraint:summary = ""> {	// Constraint
  Pred predicate = AttrConstraint:predicate;
  string summary = AttrConstraint:summary;
}
class AttrDef<Dialect AttrDef:dialect = ?, string AttrDef:name = ?, list<Trait> AttrDef:traits = [], string AttrDef:baseCppClass = "::mlir::Attribute"> {	// Constraint AttrConstraint Attr DialectAttr AttrOrTypeDef
  Pred predicate = CPred<0: !strconcat("::llvm::isa<", !strconcat(dialect.cppNamespace, !strconcat("::", !strconcat(cppClassName, ">($_self)"))))>;
  string summary = "";
  string storageType = !strconcat(dialect.cppNamespace, !strconcat("::", !strconcat(AttrDef:name, "Attr")));
  string returnType = !strconcat(dialect.cppNamespace, !strconcat("::", cppClassName));
  string convertFromStorage = !strconcat("::llvm::cast<", !strconcat(dialect.cppNamespace, !strconcat("::", !strconcat(cppClassName, ">($_self)"))));
  string constBuilderCall = ?;
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = AttrDef:dialect.cppNamespace;
  string description = "";
  Dialect dialect = AttrDef:dialect;
  string cppBaseClassName = AttrDef:baseCppClass;
  string storageClass = !strconcat(AttrDef:name, "AttrStorage");
  string storageNamespace = "detail";
  bit genStorageClass = 1;
  bit hasStorageCustomConstructor = 0;
  dag parameters = (ins);
  list<AttrOrTypeBuilder> builders = ?;
  list<Trait> traits = AttrDef:traits;
  string mnemonic = ?;
  string assemblyFormat = ?;
  bit hasCustomAssemblyFormat = 0;
  bit genAccessors = 1;
  bit skipDefaultBuilders = 0;
  bit genVerifyDecl = 0;
  code extraClassDeclaration = [{}];
  code extraClassDefinition = [{}];
  string cppClassName = !strconcat(AttrDef:name, "Attr");
  string cppType = !strconcat(dialect.cppNamespace, !strconcat("::", cppClassName));
  string attrName = !strconcat(dialect.name, !strconcat(".", mnemonic));
}
class AttrInterface<string AttrInterface:name = ?, list<Interface> AttrInterface:baseInterfaces = []> {	// Interface Trait NativeTrait InterfaceTrait Constraint AttrConstraint Attr
  string description = "";
  string cppInterfaceName = AttrInterface:name;
  string cppNamespace = "";
  list<InterfaceMethod> methods = [];
  string extraClassDeclaration = "";
  string extraSharedClassDeclaration = "";
  string extraClassOf = "";
  list<Interface> baseInterfaces = AttrInterface:baseInterfaces;
  string trait = !strconcat(AttrInterface:name, "::Trait");
  code extraConcreteClassDeclaration = [{}];
  code extraConcreteClassDefinition = [{}];
  string extraTraitClassDeclaration = "";
  Pred predicate = CPred<0: !strconcat("::llvm::isa<", !strconcat(!if(!empty(cppNamespace), "", !strconcat(cppNamespace, "::")), !strconcat(AttrInterface:name, ">($_self)")))>;
  string summary = !strconcat(AttrInterface:name, " instance");
  string storageType = !strconcat(!if(!empty(cppNamespace), "", !strconcat(cppNamespace, "::")), AttrInterface:name);
  string returnType = storageType;
  string convertFromStorage = "$_self";
  string constBuilderCall = ?;
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
}
class AttrOrTypeBuilder<dag AttrOrTypeBuilder:parameters = ?, string AttrOrTypeBuilder:bodyCode = "", string AttrOrTypeBuilder:returnTypeStr = ""> {
  dag dagParams = AttrOrTypeBuilder:parameters;
  string body = AttrOrTypeBuilder:bodyCode;
  string returnType = AttrOrTypeBuilder:returnTypeStr;
  bit hasInferredContextParam = 0;
}
class AttrOrTypeBuilderWithInferredContext<dag AttrOrTypeBuilderWithInferredContext:parameters = ?, string AttrOrTypeBuilderWithInferredContext:bodyCode = "", string AttrOrTypeBuilderWithInferredContext:returnType = ""> {	// AttrOrTypeBuilder TypeBuilder
  dag dagParams = AttrOrTypeBuilderWithInferredContext:parameters;
  string body = AttrOrTypeBuilderWithInferredContext:bodyCode;
  string returnType = AttrOrTypeBuilderWithInferredContext:returnType;
  bit hasInferredContextParam = 1;
}
class AttrOrTypeDef<string AttrOrTypeDef:valueType = ?, string AttrOrTypeDef:name = ?, list<Trait> AttrOrTypeDef:defTraits = ?, string AttrOrTypeDef:baseCppClass = ?> {
  string cppBaseClassName = AttrOrTypeDef:baseCppClass;
  string description = "";
  string storageClass = !strconcat(AttrOrTypeDef:name, !strconcat(AttrOrTypeDef:valueType, "Storage"));
  string storageNamespace = "detail";
  bit genStorageClass = 1;
  bit hasStorageCustomConstructor = 0;
  dag parameters = (ins);
  list<AttrOrTypeBuilder> builders = ?;
  list<Trait> traits = AttrOrTypeDef:defTraits;
  string mnemonic = ?;
  string assemblyFormat = ?;
  bit hasCustomAssemblyFormat = 0;
  bit genAccessors = 1;
  bit skipDefaultBuilders = 0;
  bit genVerifyDecl = 0;
  code extraClassDeclaration = [{}];
  code extraClassDefinition = [{}];
}
class AttrOrTypeParameter<string AttrOrTypeParameter:type = ?, string AttrOrTypeParameter:desc = ?, string AttrOrTypeParameter:accessorType = ""> {
  string allocator = ?;
  string comparator = ?;
  string cppType = AttrOrTypeParameter:type;
  string cppAccessorType = !if(!empty(AttrOrTypeParameter:accessorType), AttrOrTypeParameter:type, AttrOrTypeParameter:accessorType);
  string cppStorageType = cppType;
  string convertFromStorage = "$_self";
  string summary = AttrOrTypeParameter:desc;
  string syntax = ?;
  string parser = ?;
  string printer = ?;
  string defaultValue = "";
}
class AttrParameter<string AttrParameter:type = ?, string AttrParameter:desc = ?, string AttrParameter:accessorType = ""> {	// AttrOrTypeParameter
  string allocator = ?;
  string comparator = ?;
  string cppType = AttrParameter:type;
  string cppAccessorType = !if(!empty(AttrParameter:accessorType), AttrParameter:type, AttrParameter:accessorType);
  string cppStorageType = cppType;
  string convertFromStorage = "$_self";
  string summary = AttrParameter:desc;
  string syntax = ?;
  string parser = ?;
  string printer = ?;
  string defaultValue = "";
}
class AttributeSelfTypeParameter<string AttributeSelfTypeParameter:desc = ?, string AttributeSelfTypeParameter:derivedType = "::mlir::Type", string AttributeSelfTypeParameter:typeBuilder = ""> {	// AttrOrTypeParameter
  string allocator = ?;
  string comparator = ?;
  string cppType = AttributeSelfTypeParameter:derivedType;
  string cppAccessorType = AttributeSelfTypeParameter:derivedType;
  string cppStorageType = cppType;
  string convertFromStorage = "$_self";
  string summary = AttributeSelfTypeParameter:desc;
  string syntax = ?;
  string parser = ?;
  string printer = ?;
  string defaultValue = !if(!and(!empty(AttributeSelfTypeParameter:typeBuilder), !eq(AttributeSelfTypeParameter:derivedType, "::mlir::Type")), "::mlir::NoneType::get($_ctxt)", AttributeSelfTypeParameter:typeBuilder);
}
class BuildableType<string BuildableType:builder = ?> {
  string builderCall = BuildableType:builder;
}
class CArg<string CArg:ty = ?, string CArg:value = ""> {
  string type = CArg:ty;
  string defaultValue = CArg:value;
}
class CPred<string CPred:pred = ?> {	// Pred
  string predExpr = !strconcat("(", !strconcat(CPred:pred, ")"));
}
class CombinedPred<PredCombinerKind CombinedPred:k = ?, list<Pred> CombinedPred:c = ?> {	// Pred
  PredCombinerKind kind = CombinedPred:k;
  list<Pred> children = CombinedPred:c;
}
class Complex<Type Complex:type = ?> {	// Constraint TypeConstraint Type ConfinedType SameBuildabilityAs
  Pred predicate = And<0: [anonymous_47, SubstLeaves<0: "$_self", 1: "::llvm::cast<::mlir::ComplexType>($_self).getElementType()", 2: Complex:type.predicate>]>;
  string summary = !strconcat("complex type with ", !strconcat(Complex:type.summary, " elements"));
  string cppClassName = "::mlir::ComplexType";
  string description = "";
  string builderCall = !if(!empty(Complex:type.builderCall), "", !strconcat("::mlir::ComplexType::get($_builder.get", !strconcat(!cast<string>(Complex:type), "Type())")));
  Type elementType = Complex:type;
}
class Concat<string Concat:pre = ?, Pred Concat:child = ?, string Concat:suf = ?> {	// Pred CombinedPred
  PredCombinerKind kind = PredCombinerConcat;
  list<Pred> children = [Concat:child];
  string prefix = Concat:pre;
  string suffix = Concat:suf;
}
class ConfinedAttr<Attr ConfinedAttr:attr = ?, list<AttrConstraint> ConfinedAttr:constraints = ?> {	// Constraint AttrConstraint Attr
  Pred predicate = And<0: !listconcat([ConfinedAttr:attr.predicate], !foreach(pred, ConfinedAttr:constraints, pred.predicate))>;
  string summary = !foldl(ConfinedAttr:attr.summary, ConfinedAttr:constraints, prev, cur, !strconcat(prev, !strconcat(" ", cur.summary)));
  string storageType = ConfinedAttr:attr.storageType;
  string returnType = ConfinedAttr:attr.returnType;
  string convertFromStorage = ConfinedAttr:attr.convertFromStorage;
  string constBuilderCall = ConfinedAttr:attr.constBuilderCall;
  string defaultValue = ConfinedAttr:attr.defaultValue;
  Type valueType = ConfinedAttr:attr.valueType;
  bit isOptional = ConfinedAttr:attr.isOptional;
  Attr baseAttr = ConfinedAttr:attr;
  string cppNamespace = "";
  string description = "";
}
class ConfinedType<Type ConfinedType:type = ?, list<Pred> ConfinedType:predicates = ?, string ConfinedType:summary = "", string ConfinedType:cppClassName = ConfinedType:type.cppClassName> {	// Constraint TypeConstraint Type
  Pred predicate = And<0: !listconcat([ConfinedType:type.predicate], !foreach(pred, ConfinedType:predicates, pred))>;
  string summary = ConfinedType:summary;
  string cppClassName = ConfinedType:cppClassName;
  string description = "";
  string builderCall = "";
}
class ConstF32Attr<string ConstF32Attr:val = ?> {	// Constraint AttrConstraint ConstantAttr
  Pred predicate = CPred<0: !strconcat("$_self == ", !subst("$0", ConstF32Attr:val, "$_builder.getFloatAttr($_builder.getF32Type(), $0)"))>;
  string summary = !strconcat("constant attribute ", ConstF32Attr:val);
  Attr attr = F32Attr;
  string value = ConstF32Attr:val;
}
class ConstantAttr<Attr ConstantAttr:attribute = ?, string ConstantAttr:val = ?> {	// Constraint AttrConstraint
  Pred predicate = CPred<0: !strconcat("$_self == ", !subst("$0", ConstantAttr:val, ConstantAttr:attribute.constBuilderCall))>;
  string summary = !strconcat("constant attribute ", ConstantAttr:val);
  Attr attr = ConstantAttr:attribute;
  string value = ConstantAttr:val;
}
class ConstantStrAttr<Attr ConstantStrAttr:attribute = ?, string ConstantStrAttr:val = ?> {	// Constraint AttrConstraint ConstantAttr
  Pred predicate = CPred<0: !strconcat("$_self == ", !subst("$0", !strconcat(""", !strconcat(ConstantStrAttr:val, """)), ConstantStrAttr:attribute.constBuilderCall))>;
  string summary = !strconcat("constant attribute ", !strconcat(""", !strconcat(ConstantStrAttr:val, """)));
  Attr attr = ConstantStrAttr:attribute;
  string value = !strconcat(""", !strconcat(ConstantStrAttr:val, """));
}
class Constraint<Pred Constraint:pred = ?, string Constraint:desc = ""> {
  Pred predicate = Constraint:pred;
  string summary = Constraint:desc;
}
class ContainerType<Type ContainerType:etype = ?, Pred ContainerType:containerPred = ?, string ContainerType:elementTypeCall = ?, string ContainerType:descr = ?, string ContainerType:cppClassName = "::mlir::Type"> {	// Constraint TypeConstraint Type
  Pred predicate = And<0: [ContainerType:containerPred, SubstLeaves<0: "$_self", 1: ContainerType:elementTypeCall, 2: ContainerType:etype.predicate>]>;
  string summary = !strconcat(ContainerType:descr, !strconcat(" of ", !strconcat(ContainerType:etype.summary, " values")));
  string cppClassName = ContainerType:cppClassName;
  string description = "";
  string builderCall = "";
}
class CppDeprecated<string CppDeprecated:reason = ?> {
  string odsCppDeprecated = CppDeprecated:reason;
}
class DeclareAttrInterfaceMethods<AttrInterface DeclareAttrInterfaceMethods:interface = ?, list<string> DeclareAttrInterfaceMethods:overridenMethods = []> {	// DeclareInterfaceMethods Interface Trait NativeTrait InterfaceTrait Constraint AttrConstraint Attr AttrInterface
  list<string> alwaysOverriddenMethods = DeclareAttrInterfaceMethods:overridenMethods;
  string description = DeclareAttrInterfaceMethods:interface.description;
  string cppInterfaceName = DeclareAttrInterfaceMethods:interface.cppInterfaceName;
  string cppNamespace = DeclareAttrInterfaceMethods:interface.cppNamespace;
  list<InterfaceMethod> methods = DeclareAttrInterfaceMethods:interface.methods;
  string extraClassDeclaration = "";
  string extraSharedClassDeclaration = "";
  string extraClassOf = "";
  list<Interface> baseInterfaces = DeclareAttrInterfaceMethods:interface.baseInterfaces;
  string trait = !strconcat(DeclareAttrInterfaceMethods:interface.cppInterfaceName, "::Trait");
  code extraConcreteClassDeclaration = [{}];
  code extraConcreteClassDefinition = [{}];
  string extraTraitClassDeclaration = "";
  Pred predicate = CPred<0: !strconcat("::llvm::isa<", !strconcat(!if(!empty(cppNamespace), "", !strconcat(cppNamespace, "::")), !strconcat(DeclareAttrInterfaceMethods:interface.cppInterfaceName, ">($_self)")))>;
  string summary = !strconcat(DeclareAttrInterfaceMethods:interface.cppInterfaceName, " instance");
  string storageType = !strconcat(!if(!empty(cppNamespace), "", !strconcat(cppNamespace, "::")), DeclareAttrInterfaceMethods:interface.cppInterfaceName);
  string returnType = storageType;
  string convertFromStorage = "$_self";
  string constBuilderCall = ?;
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
}
class DeclareInterfaceMethods<list<string> DeclareInterfaceMethods:overridenMethods = []> {
  list<string> alwaysOverriddenMethods = DeclareInterfaceMethods:overridenMethods;
}
class DeclareOpInterfaceMethods<OpInterface DeclareOpInterfaceMethods:interface = ?, list<string> DeclareOpInterfaceMethods:overridenMethods = []> {	// DeclareInterfaceMethods Interface Trait NativeTrait InterfaceTrait OpInterfaceTrait OpInterface
  list<string> alwaysOverriddenMethods = DeclareOpInterfaceMethods:overridenMethods;
  string description = DeclareOpInterfaceMethods:interface.description;
  string cppInterfaceName = DeclareOpInterfaceMethods:interface.cppInterfaceName;
  string cppNamespace = DeclareOpInterfaceMethods:interface.cppNamespace;
  list<InterfaceMethod> methods = DeclareOpInterfaceMethods:interface.methods;
  string extraClassDeclaration = "";
  string extraSharedClassDeclaration = "";
  string extraClassOf = "";
  list<Interface> baseInterfaces = DeclareOpInterfaceMethods:interface.baseInterfaces;
  string trait = !strconcat(DeclareOpInterfaceMethods:interface.cppInterfaceName, "::Trait");
  code extraConcreteClassDeclaration = [{}];
  code extraConcreteClassDefinition = [{}];
  string extraTraitClassDeclaration = "";
  code verify = [{}];
  bit verifyWithRegions = 0;
  list<Trait> dependentTraits = [];
}
class DeclareTypeInterfaceMethods<TypeInterface DeclareTypeInterfaceMethods:interface = ?, list<string> DeclareTypeInterfaceMethods:overridenMethods = []> {	// DeclareInterfaceMethods Interface Trait NativeTrait InterfaceTrait Constraint TypeConstraint Type TypeInterface
  list<string> alwaysOverriddenMethods = DeclareTypeInterfaceMethods:overridenMethods;
  string description = DeclareTypeInterfaceMethods:interface.description;
  string cppInterfaceName = DeclareTypeInterfaceMethods:interface.cppInterfaceName;
  string cppNamespace = DeclareTypeInterfaceMethods:interface.cppNamespace;
  list<InterfaceMethod> methods = DeclareTypeInterfaceMethods:interface.methods;
  string extraClassDeclaration = "";
  string extraSharedClassDeclaration = "";
  string extraClassOf = "";
  list<Interface> baseInterfaces = DeclareTypeInterfaceMethods:interface.baseInterfaces;
  string trait = !strconcat(DeclareTypeInterfaceMethods:interface.cppInterfaceName, "::Trait");
  code extraConcreteClassDeclaration = [{}];
  code extraConcreteClassDefinition = [{}];
  string extraTraitClassDeclaration = "";
  Pred predicate = CPred<0: !strconcat("::llvm::isa<", !strconcat(!if(!empty(cppNamespace), "", !strconcat(cppNamespace, "::")), !strconcat(DeclareTypeInterfaceMethods:interface.cppInterfaceName, ">($_self)")))>;
  string summary = !strconcat(DeclareTypeInterfaceMethods:interface.cppInterfaceName, " instance");
  string cppClassName = !strconcat(!if(!empty(cppNamespace), "", !strconcat(cppNamespace, "::")), DeclareTypeInterfaceMethods:interface.cppInterfaceName);
  string builderCall = "";
}
class DefaultValuedAttr<Attr DefaultValuedAttr:attr = ?, string DefaultValuedAttr:val = ?> {	// Constraint AttrConstraint Attr
  Pred predicate = DefaultValuedAttr:attr.predicate;
  string summary = DefaultValuedAttr:attr.summary;
  string storageType = DefaultValuedAttr:attr.storageType;
  string returnType = DefaultValuedAttr:attr.returnType;
  string convertFromStorage = DefaultValuedAttr:attr.convertFromStorage;
  string constBuilderCall = DefaultValuedAttr:attr.constBuilderCall;
  string defaultValue = DefaultValuedAttr:val;
  Type valueType = DefaultValuedAttr:attr.valueType;
  bit isOptional = 0;
  Attr baseAttr = DefaultValuedAttr:attr;
  string cppNamespace = "";
  string description = "";
}
class DefaultValuedOptionalAttr<Attr DefaultValuedOptionalAttr:attr = ?, string DefaultValuedOptionalAttr:val = ?> {	// Constraint AttrConstraint Attr
  Pred predicate = DefaultValuedOptionalAttr:attr.predicate;
  string summary = DefaultValuedOptionalAttr:attr.summary;
  string storageType = DefaultValuedOptionalAttr:attr.storageType;
  string returnType = DefaultValuedOptionalAttr:attr.returnType;
  string convertFromStorage = DefaultValuedOptionalAttr:attr.convertFromStorage;
  string constBuilderCall = DefaultValuedOptionalAttr:attr.constBuilderCall;
  string defaultValue = DefaultValuedOptionalAttr:val;
  Type valueType = DefaultValuedOptionalAttr:attr.valueType;
  bit isOptional = 1;
  Attr baseAttr = DefaultValuedOptionalAttr:attr;
  string cppNamespace = "";
  string description = "";
}
class DefaultValuedOptionalStrAttr<Attr DefaultValuedOptionalStrAttr:attr = ?, string DefaultValuedOptionalStrAttr:val = ?> {	// Constraint AttrConstraint Attr DefaultValuedOptionalAttr
  Pred predicate = DefaultValuedOptionalStrAttr:attr.predicate;
  string summary = DefaultValuedOptionalStrAttr:attr.summary;
  string storageType = DefaultValuedOptionalStrAttr:attr.storageType;
  string returnType = DefaultValuedOptionalStrAttr:attr.returnType;
  string convertFromStorage = DefaultValuedOptionalStrAttr:attr.convertFromStorage;
  string constBuilderCall = DefaultValuedOptionalStrAttr:attr.constBuilderCall;
  string defaultValue = !strconcat(""", !strconcat(DefaultValuedOptionalStrAttr:val, """));
  Type valueType = DefaultValuedOptionalStrAttr:attr.valueType;
  bit isOptional = 1;
  Attr baseAttr = DefaultValuedOptionalStrAttr:attr;
  string cppNamespace = "";
  string description = "";
}
class DefaultValuedParameter<string DefaultValuedParameter:type = ?, string DefaultValuedParameter:value = ?, string DefaultValuedParameter:desc = ""> {	// AttrOrTypeParameter
  string allocator = ?;
  string comparator = ?;
  string cppType = DefaultValuedParameter:type;
  string cppAccessorType = DefaultValuedParameter:type;
  string cppStorageType = cppType;
  string convertFromStorage = "$_self";
  string summary = DefaultValuedParameter:desc;
  string syntax = ?;
  string parser = ?;
  string printer = ?;
  string defaultValue = DefaultValuedParameter:value;
}
class DefaultValuedStrAttr<Attr DefaultValuedStrAttr:attr = ?, string DefaultValuedStrAttr:val = ?> {	// Constraint AttrConstraint Attr DefaultValuedAttr
  Pred predicate = DefaultValuedStrAttr:attr.predicate;
  string summary = DefaultValuedStrAttr:attr.summary;
  string storageType = DefaultValuedStrAttr:attr.storageType;
  string returnType = DefaultValuedStrAttr:attr.returnType;
  string convertFromStorage = DefaultValuedStrAttr:attr.convertFromStorage;
  string constBuilderCall = DefaultValuedStrAttr:attr.constBuilderCall;
  string defaultValue = !strconcat(""", !strconcat(DefaultValuedStrAttr:val, """));
  Type valueType = DefaultValuedStrAttr:attr.valueType;
  bit isOptional = 0;
  Attr baseAttr = DefaultValuedStrAttr:attr;
  string cppNamespace = "";
  string description = "";
}
class DenseArrayAttrBase<string DenseArrayAttrBase:denseAttrName = ?, string DenseArrayAttrBase:cppType = ?, string DenseArrayAttrBase:summaryName = ?> {	// Constraint AttrConstraint Attr ElementsAttrBase
  Pred predicate = CPred<0: !strconcat("::llvm::isa<::mlir::", !strconcat(DenseArrayAttrBase:denseAttrName, ">($_self)"))>;
  string summary = !strconcat(DenseArrayAttrBase:summaryName, " dense array attribute");
  string storageType = !strconcat("::mlir::", DenseArrayAttrBase:denseAttrName);
  string returnType = !strconcat("::llvm::ArrayRef<", !strconcat(DenseArrayAttrBase:cppType, ">"));
  string convertFromStorage = "$_self";
  string constBuilderCall = !strconcat("$_builder.get", !strconcat(DenseArrayAttrBase:denseAttrName, "($0)"));
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class DenseArrayCount<int DenseArrayCount:n = ?> {	// Constraint AttrConstraint
  Pred predicate = CPred<0: !strconcat("::llvm::cast<::mlir::DenseArrayAttr>($_self).size() == ", !cast<string>(DenseArrayCount:n))>;
  string summary = !strconcat("with exactly ", !strconcat(!cast<string>(DenseArrayCount:n), " elements"));
}
class DenseArrayNonNegative<DenseArrayAttrBase DenseArrayNonNegative:arrayType = ?> {	// Constraint AttrConstraint
  Pred predicate = CPred<0: !strconcat("::llvm::all_of(::llvm::cast<", !strconcat(!cast<string>(DenseArrayNonNegative:arrayType), ">($_self).asArrayRef(), [&](auto v) { return v >= 0; })"))>;
  string summary = "whose value is non-negative";
}
class DenseArraySorted<DenseArrayAttrBase DenseArraySorted:arrayType = ?> {	// Constraint AttrConstraint
  Pred predicate = CPred<0: !strconcat("llvm::is_sorted(::llvm::cast<", !strconcat(!cast<string>(DenseArraySorted:arrayType), ">($_self).asArrayRef())"))>;
  string summary = "should be in non-decreasing order";
}
class DenseArrayStrictlyPositive<DenseArrayAttrBase DenseArrayStrictlyPositive:arrayType = ?> {	// Constraint AttrConstraint
  Pred predicate = CPred<0: !strconcat("::llvm::all_of(::llvm::cast<", !strconcat(!cast<string>(DenseArrayStrictlyPositive:arrayType), ">($_self).asArrayRef(), [&](auto v) { return v > 0; })"))>;
  string summary = "whose value is positive";
}
class DenseArrayStrictlySorted<DenseArrayAttrBase DenseArrayStrictlySorted:arrayType = ?> {	// Constraint AttrConstraint
  Pred predicate = And<0: [CPred<0: !strconcat("llvm::is_sorted(::llvm::cast<", !strconcat(!cast<string>(DenseArrayStrictlySorted:arrayType), ">($_self).asArrayRef())"))>, CPred<0: !strconcat("[](", !strconcat(DenseArrayStrictlySorted:arrayType.returnType, !strconcat(" a) {
return std::adjacent_find(std::begin(a), std::end(a)) == std::end(a);
}(::llvm::cast<", !strconcat(!cast<string>(DenseArrayStrictlySorted:arrayType), ">($_self).asArrayRef())"))))>]>;
  string summary = "should be in increasing order";
}
class Deprecated<string Deprecated:reason = ?> {
  string odsDeprecated = Deprecated:reason;
}
class DeprecatedOpBuilder<string DeprecatedOpBuilder:reason = ?, dag DeprecatedOpBuilder:p = ?, string DeprecatedOpBuilder:b = ""> {	// OpBuilder CppDeprecated
  dag dagParams = DeprecatedOpBuilder:p;
  string body = DeprecatedOpBuilder:b;
  string odsCppDeprecated = DeprecatedOpBuilder:reason;
}
class DerivedAttr<string DerivedAttr:ret = ?, string DerivedAttr:b = ?, string DerivedAttr:convert = ""> {	// Constraint AttrConstraint Attr
  Pred predicate = anonymous_5;
  string summary = "derived attribute";
  string storageType = ?;
  string returnType = DerivedAttr:ret;
  string convertFromStorage = DerivedAttr:convert;
  string constBuilderCall = ?;
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
  string body = DerivedAttr:b;
}
class DerivedTypeAttr<string DerivedTypeAttr:body = ?> {	// Constraint AttrConstraint Attr DerivedAttr
  Pred predicate = anonymous_5;
  string summary = "derived attribute";
  string storageType = ?;
  string returnType = "::mlir::Type";
  string convertFromStorage = "::mlir::TypeAttr::get($_self)";
  string constBuilderCall = ?;
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
  string body = DerivedTypeAttr:body;
}
class Dialect {
  string name = ?;
  string summary = ?;
  string description = ?;
  list<string> dependentDialects = [];
  dag discardableAttrs = (ins);
  string cppNamespace = name;
  string extraClassDeclaration = "";
  bit hasConstantMaterializer = 0;
  bit hasNonDefaultDestructor = 0;
  bit hasOperationAttrVerify = 0;
  bit hasRegionArgAttrVerify = 0;
  bit hasRegionResultAttrVerify = 0;
  bit hasOperationInterfaceFallback = 0;
  bit useDefaultAttributePrinterParser = 0;
  bit useDefaultTypePrinterParser = 0;
  bit hasCanonicalizer = 0;
  bit isExtensible = 0;
  bit usePropertiesForAttributes = 1;
}
class DialectAttr<Dialect DialectAttr:d = ?, Pred DialectAttr:condition = ?, string DialectAttr:summary = ""> {	// Constraint AttrConstraint Attr
  Pred predicate = DialectAttr:condition;
  string summary = DialectAttr:summary;
  string storageType = ?;
  string returnType = ?;
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = ?;
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = DialectAttr:d.cppNamespace;
  string description = "";
  Dialect dialect = DialectAttr:d;
}
class DialectType<Dialect DialectType:d = ?, Pred DialectType:condition = ?, string DialectType:descr = "", string DialectType:cppClassName = "::mlir::Type"> {	// Constraint TypeConstraint Type
  Pred predicate = DialectType:condition;
  string summary = DialectType:descr;
  string cppClassName = DialectType:cppClassName;
  string description = "";
  string builderCall = "";
  Dialect dialect = DialectType:d;
}
class DictionaryAttrBase<Pred DictionaryAttrBase:condition = ?, string DictionaryAttrBase:summary = ?> {	// Constraint AttrConstraint Attr
  Pred predicate = DictionaryAttrBase:condition;
  string summary = DictionaryAttrBase:summary;
  code storageType = [{ ::mlir::DictionaryAttr }];
  code returnType = [{ ::mlir::DictionaryAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = "$_builder.getDictionaryAttr($0)";
  string defaultValue = ?;
  Type valueType = NoneType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class EffectOpInterfaceBase<string EffectOpInterfaceBase:name = ?, string EffectOpInterfaceBase:baseEffect = ?> {	// Interface Trait NativeTrait InterfaceTrait OpInterfaceTrait OpInterface
  string description = "";
  string cppInterfaceName = EffectOpInterfaceBase:name;
  string cppNamespace = "";
  list<InterfaceMethod> methods = [InterfaceMethod<0: [{
        Collects all of the operation's effects into `effects`.
      }], 1: "void", 2: "getEffects", 3: (ins !strconcat("::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<", !strconcat(EffectOpInterfaceBase:baseEffect, ">> &")):$effects)>];
  string extraClassDeclaration = !strconcat([{
    /// Collect all of the effect instances that correspond to the given
    /// `Effect` and place them in 'effects'.
    template <typename Effect> void getEffects(
      ::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<
                                              }], !strconcat(EffectOpInterfaceBase:baseEffect, !strconcat([{>> &effects) {
      getEffects(effects);
      ::llvm::erase_if(effects, [&](auto &it) {
        return !::llvm::isa<Effect>(it.getEffect());
      });
    }

    /// Returns true if this operation exhibits the given effect.
    template <typename Effect> bool hasEffect() {
      ::llvm::SmallVector<::mlir::SideEffects::EffectInstance<
                                            }], !strconcat(EffectOpInterfaceBase:baseEffect, !strconcat([{>, 4> effects;
      getEffects(effects);
      return ::llvm::any_of(effects, [](const auto &it) {
        return ::llvm::isa<Effect>(it.getEffect());
      });
    }

    /// Returns true if this operation only has the given effect.
    template <typename Effect> bool onlyHasEffect() {
      ::llvm::SmallVector<::mlir::SideEffects::EffectInstance<
                                            }], !strconcat(EffectOpInterfaceBase:baseEffect, !strconcat([{>, 4> effects;
      getEffects(effects);
      return !effects.empty() && ::llvm::all_of(effects, [](const auto &it) {
        return ::llvm::isa<Effect>(it.getEffect());
      });
    }

    /// Returns true if this operation has no effects.
    bool hasNoEffect() {
      ::llvm::SmallVector<::mlir::SideEffects::EffectInstance<
                                            }], !strconcat(EffectOpInterfaceBase:baseEffect, !strconcat([{>, 4> effects;
      getEffects(effects);
      return effects.empty();
    }

    /// Collect all of the effect instances that operate on the provided value
    /// and place them in 'effects'.
    void getEffectsOnValue(::mlir::Value value,
              ::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<
              }], !strconcat(EffectOpInterfaceBase:baseEffect, !strconcat([{>> & effects) {
      getEffects(effects);
      ::llvm::erase_if(effects, [&](auto &it) { return it.getValue() != value; });
    }

    /// Return the effect of the given type `Effect` that is applied to the
    /// given value, or std::nullopt if no effect exists.
    template <typename Effect>
    ::std::optional<::mlir::SideEffects::EffectInstance<}], !strconcat(EffectOpInterfaceBase:baseEffect, !strconcat([{>>
    getEffectOnValue(::mlir::Value value) {
      ::llvm::SmallVector<::mlir::SideEffects::EffectInstance<
              }], !strconcat(EffectOpInterfaceBase:baseEffect, !strconcat([{>, 4> effects;
      getEffects(effects);
      auto it = ::llvm::find_if(effects, [&](auto &it) {
        return ::llvm::isa<Effect>(it.getEffect()) && it.getValue() == value;
      });
      if (it == effects.end())
        return std::nullopt;
      return *it;
    }

    /// Collect all of the effect instances that operate on the provided symbol
    /// reference and place them in 'effects'.
    void getEffectsOnSymbol(::mlir::SymbolRefAttr value,
              ::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<
              }], !strconcat(EffectOpInterfaceBase:baseEffect, !strconcat([{>> & effects) {
      getEffects(effects);
      ::llvm::erase_if(effects, [&](auto &it) {
        return it.getSymbolRef() != value;
      });
    }

    /// Collect all of the effect instances that operate on the provided
    /// resource and place them in 'effects'.
    void getEffectsOnResource(::mlir::SideEffects::Resource *resource,
              ::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<
              }], !strconcat(EffectOpInterfaceBase:baseEffect, [{>> & effects) {
      getEffects(effects);
      ::llvm::erase_if(effects, [&](auto &it) {
        return it.getResource() != resource;
      });
    }
  }]))))))))))))))))));
  string extraSharedClassDeclaration = "";
  string extraClassOf = "";
  list<Interface> baseInterfaces = [];
  string trait = !strconcat(EffectOpInterfaceBase:name, "::Trait");
  code extraConcreteClassDeclaration = [{}];
  code extraConcreteClassDefinition = [{}];
  string extraTraitClassDeclaration = "";
  code verify = [{}];
  bit verifyWithRegions = 0;
  list<Trait> dependentTraits = [];
  string baseEffectName = EffectOpInterfaceBase:baseEffect;
}
class EffectRange<bits<1> EffectRange:val = { ? }> {
  bits<1> Value = { EffectRange:val{0} };
}
class ElementCount<string ElementCount:name = ?> {	// StrFunc
  string result = !strconcat("llvm::cast<::mlir::ShapedType>($", !strconcat(ElementCount:name, ".getType()).getNumElements()"));
}
class ElementType<string ElementType:name = ?> {	// StrFunc
  string result = !strconcat("getElementTypeOrSelf($", !strconcat(ElementType:name, ")"));
}
class ElementTypeIs<string ElementTypeIs:name = ?, Type ElementTypeIs:type = ?> {	// Trait PredTrait PredOpTrait
  string summary = !strconcat("'", !strconcat(ElementTypeIs:name, !strconcat("' is ", ElementTypeIs:type.summary)));
  Pred predicate = ElementTypeIsPred<0: ElementTypeIs:name, 1: ElementTypeIs:type>;
  list<Trait> dependentTraits = [];
}
class ElementTypeIsPred<string ElementTypeIsPred:name = ?, Type ElementTypeIsPred:type = ?> {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [SubstLeaves<0: "$_self", 1: !strconcat("$", !strconcat(ElementTypeIsPred:name, ".getType()")), 2: IsShapedTypePred>, SubstLeaves<0: "$_self", 1: !strconcat("getElementTypeOrSelf($", !strconcat(ElementTypeIsPred:name, ")")), 2: ElementTypeIsPred:type.predicate>];
}
class ElementsAttrBase<Pred ElementsAttrBase:condition = ?, string ElementsAttrBase:summary = ?> {	// Constraint AttrConstraint Attr
  Pred predicate = ElementsAttrBase:condition;
  string summary = ElementsAttrBase:summary;
  code storageType = [{ ::mlir::ElementsAttr }];
  code returnType = [{ ::mlir::ElementsAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = ?;
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class EnumProperty<string EnumProperty:storageTypeParam = ?, string EnumProperty:desc = ""> {	// Property
  string summary = EnumProperty:desc;
  string description = "";
  string storageType = EnumProperty:storageTypeParam;
  string interfaceType = EnumProperty:storageTypeParam;
  string convertFromStorage = "$_storage";
  string assignToStorage = "$_storage = $_value";
  code convertToAttribute = [{
    convertToAttribute($_ctxt, $_storage)
  }];
  code convertFromAttribute = [{
    return convertFromAttribute($_storage, $_attr, $_diag);
  }];
  code hashProperty = [{
    llvm::hash_value($_storage);
  }];
  code writeToMlirBytecode = [{
    $_writer.writeVarInt(static_cast<uint64_t>($_storage));
  }];
  string readFromMlirBytecode = !strconcat([{
    uint64_t val;
    if (failed($_reader.readVarInt(val)))
      return ::mlir::failure();
    $_storage = static_cast<}], !strconcat(EnumProperty:storageTypeParam, [{>(val);
  }]));
  string defaultValue = ?;
}
class F<int F:width = ?> {	// Constraint TypeConstraint Type BuildableType
  Pred predicate = CPred<0: !strconcat("$_self.isF", !strconcat(!cast<string>(F:width), "()"))>;
  string summary = !strconcat(!cast<string>(F:width), "-bit float");
  string cppClassName = "::mlir::FloatType";
  string description = "";
  string builderCall = !strconcat("$_builder.getF", !strconcat(!cast<string>(F:width), "Type()"));
  int bitwidth = F:width;
}
class FixedVectorOf<list<Type> FixedVectorOf:allowedTypes = ?> {	// Constraint TypeConstraint Type ShapedContainerType
  Pred predicate = And<0: [IsFixedVectorTypePred, Concat<0: "[](::mlir::Type elementType) { return ", 1: SubstLeaves<0: "$_self", 1: "elementType", 2: AnyTypeOf<0: FixedVectorOf:allowedTypes>.predicate>, 2: "; }(::llvm::cast<::mlir::ShapedType>($_self).getElementType())">]>;
  string summary = !strconcat("fixed-length vector", !strconcat(" of ", !strconcat(AnyTypeOf<0: FixedVectorOf:allowedTypes>.summary, " values")));
  string cppClassName = "::mlir::VectorType";
  string description = "";
  string builderCall = "";
}
class FixedVectorOfLength<list<int> FixedVectorOfLength:allowedLengths = ?> {	// Constraint TypeConstraint Type
  Pred predicate = IsFixedVectorOfLengthPred<0: FixedVectorOfLength:allowedLengths>;
  string summary = !strconcat(" of length ", !interleave(FixedVectorOfLength:allowedLengths, "/"));
  string cppClassName = "::mlir::VectorType";
  string description = "";
  string builderCall = "";
}
class FixedVectorOfLengthAndType<list<int> FixedVectorOfLengthAndType:allowedLengths = ?, list<Type> FixedVectorOfLengthAndType:allowedTypes = ?> {	// Constraint TypeConstraint Type AllOfType
  Pred predicate = And<0: [FixedVectorOf<0: FixedVectorOfLengthAndType:allowedTypes>.predicate, FixedVectorOfLength<0: FixedVectorOfLengthAndType:allowedLengths>.predicate]>;
  string summary = !if(!eq(!strconcat(FixedVectorOf<0: FixedVectorOfLengthAndType:allowedTypes>.summary, FixedVectorOfLength<0: FixedVectorOfLengthAndType:allowedLengths>.summary), ""), !interleave([FixedVectorOf<0: FixedVectorOfLengthAndType:allowedTypes>.summary, FixedVectorOfLength<0: FixedVectorOfLengthAndType:allowedLengths>.summary], " and "), !strconcat(FixedVectorOf<0: FixedVectorOfLengthAndType:allowedTypes>.summary, FixedVectorOfLength<0: FixedVectorOfLengthAndType:allowedLengths>.summary));
  string cppClassName = "::mlir::VectorType";
  string description = "";
  string builderCall = "";
  list<Type> allowedTypes = [FixedVectorOf<0: FixedVectorOfLengthAndType:allowedTypes>, FixedVectorOfLength<0: FixedVectorOfLengthAndType:allowedLengths>];
}
class FixedVectorOfRank<list<int> FixedVectorOfRank:allowedRanks = ?> {	// Constraint TypeConstraint Type
  Pred predicate = IsFixedVectorOfRankPred<0: FixedVectorOfRank:allowedRanks>;
  string summary = !strconcat(" of ranks ", !interleave(FixedVectorOfRank:allowedRanks, "/"));
  string cppClassName = "::mlir::VectorType";
  string description = "";
  string builderCall = "";
}
class FloatAttrBase<F FloatAttrBase:attrValType = ?, string FloatAttrBase:descr = ?> {	// Constraint AttrConstraint Attr TypedAttrBase
  Pred predicate = And<0: [anonymous_234, CPred<0: !strconcat("::llvm::cast<::mlir::FloatAttr>($_self).getType().isF", !strconcat(!cast<string>(FloatAttrBase:attrValType.bitwidth), "()"))>]>;
  string summary = FloatAttrBase:descr;
  string storageType = "::mlir::FloatAttr";
  code returnType = [{ ::llvm::APFloat }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = !strconcat("$_builder.get", !strconcat("FloatAttr", !strconcat("(", !strconcat(FloatAttrBase:attrValType.builderCall, ", $0)"))));
  string defaultValue = ?;
  Type valueType = FloatAttrBase:attrValType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class FloatElementsAttr<int FloatElementsAttr:width = ?> {	// Constraint AttrConstraint Attr ElementsAttrBase
  Pred predicate = CPred<0: !strconcat("::llvm::isa<::mlir::DenseFPElementsAttr>($_self) &&::llvm::cast<::mlir::DenseElementsAttr>($_self).getType().getElementType().isF", !strconcat(!cast<string>(FloatElementsAttr:width), "()"))>;
  string summary = !strconcat(!cast<string>(FloatElementsAttr:width), "-bit float elements attribute");
  code storageType = [{ ::mlir::DenseElementsAttr }];
  code returnType = [{ ::mlir::DenseElementsAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = !strconcat("::mlir::DenseElementsAttr::get(::mlir::RankedTensorType::get({}, $_builder.getF", !strconcat(!cast<string>(FloatElementsAttr:width), "Type()),::llvm::ArrayRef($0))"));
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class FloatOfWidths<list<int> FloatOfWidths:widths = ?> {	// Constraint TypeConstraint Type AnyTypeOf
  Pred predicate = Or<0: !foreach(allowedtype, !foreach(w, FloatOfWidths:widths, F<0: w>), allowedtype.predicate)>;
  string summary = !if(!eq(!strconcat(!interleave(FloatOfWidths:widths, "/"), "-bit float"), ""), !interleave(!foreach(t, !foreach(w, FloatOfWidths:widths, F<0: w>), t.summary), " or "), !strconcat(!interleave(FloatOfWidths:widths, "/"), "-bit float"));
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
  list<Type> allowedTypes = !foreach(w, FloatOfWidths:widths, F<0: w>);
}
class GenInternalAttrTrait<string GenInternalAttrTrait:prop = ?> {	// Trait GenInternalTrait
  string trait = !strconcat("::mlir::", !strconcat("Attribute", !strconcat("Trait::", GenInternalAttrTrait:prop)));
}
class GenInternalOpTrait<string GenInternalOpTrait:prop = ?, list<Trait> GenInternalOpTrait:traits = []> {	// Trait GenInternalTrait
  string trait = !strconcat("::mlir::", !strconcat("Op", !strconcat("Trait::", GenInternalOpTrait:prop)));
  list<Trait> dependentTraits = GenInternalOpTrait:traits;
}
class GenInternalTrait<string GenInternalTrait:prop = ?, string GenInternalTrait:entityType = ?> {	// Trait
  string trait = !strconcat("::mlir::", !strconcat(GenInternalTrait:entityType, !strconcat("Trait::", GenInternalTrait:prop)));
}
class GenInternalTypeTrait<string GenInternalTypeTrait:prop = ?> {	// Trait GenInternalTrait
  string trait = !strconcat("::mlir::", !strconcat("Type", !strconcat("Trait::", GenInternalTypeTrait:prop)));
}
class HasAnyRankOfPred<list<int> HasAnyRankOfPred:ranks = ?> {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [HasRankPred, Or<0: !foreach(rank, HasAnyRankOfPred:ranks, CPred<0: !strconcat([{::llvm::cast<::mlir::ShapedType>($_self).getRank()
                         == }], !cast<string>(rank))>)>];
}
class HasParent<string HasParent:op = ?> {	// Trait NativeTrait ParamNativeTrait ParamNativeOpTrait StructuralOpTrait
  string trait = !strconcat("HasParent", !strconcat("<", !strconcat(HasParent:op, ">::Impl")));
  string cppNamespace = "::mlir::OpTrait";
  code extraConcreteClassDeclaration = [{}];
  code extraConcreteClassDefinition = [{}];
  list<Trait> dependentTraits = [];
}
class HasPromiseOrImplementsTypeInterface<TypeInterface HasPromiseOrImplementsTypeInterface:interface = ?> {	// Pred CPred
  string predExpr = !strconcat("(", !strconcat(!strconcat("$_self.hasPromiseOrImplementsInterface<", !strconcat(!if(!empty(HasPromiseOrImplementsTypeInterface:interface.cppNamespace), "", !strconcat(HasPromiseOrImplementsTypeInterface:interface.cppNamespace, "::")), !strconcat(HasPromiseOrImplementsTypeInterface:interface.cppInterfaceName, ">()"))), ")"));
}
class HasRankGreaterOrEqualPred<int HasRankGreaterOrEqualPred:rank = ?> {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [HasRankPred, CPred<0: !strconcat([{::llvm::cast<::mlir::ShapedType>($_self).getRank() >= }], !cast<string>(HasRankGreaterOrEqualPred:rank))>];
}
class I<int I:width = ?> {	// Constraint TypeConstraint Type BuildableType
  Pred predicate = CPred<0: !strconcat("$_self.isSignlessInteger(", !strconcat(!cast<string>(I:width), ")"))>;
  string summary = !strconcat(!cast<string>(I:width), "-bit signless integer");
  string cppClassName = "::mlir::IntegerType";
  string description = "";
  string builderCall = !strconcat("$_builder.getIntegerType(", !strconcat(!cast<string>(I:width), ")"));
  int bitwidth = I:width;
}
class IntArrayNthElemEq<int IntArrayNthElemEq:index = ?, int IntArrayNthElemEq:value = ?> {	// Constraint AttrConstraint
  Pred predicate = And<0: [CPred<0: !strconcat("::llvm::cast<::mlir::ArrayAttr>($_self).size() > ", !cast<string>(IntArrayNthElemEq:index))>, CPred<0: !strconcat("::llvm::cast<::mlir::IntegerAttr>(::llvm::cast<::mlir::ArrayAttr>($_self)[", !strconcat(!cast<string>(IntArrayNthElemEq:index), !strconcat("]).getInt() == ", !cast<string>(IntArrayNthElemEq:value))))>]>;
  string summary = !strconcat("whose ", !strconcat(!cast<string>(IntArrayNthElemEq:index), !strconcat("-th element must be ", !cast<string>(IntArrayNthElemEq:value))));
}
class IntArrayNthElemInRange<int IntArrayNthElemInRange:index = ?, int IntArrayNthElemInRange:min = ?, int IntArrayNthElemInRange:max = ?> {	// Constraint AttrConstraint
  Pred predicate = And<0: [CPred<0: !strconcat("::llvm::cast<::mlir::ArrayAttr>($_self).size() > ", !cast<string>(IntArrayNthElemInRange:index))>, CPred<0: !strconcat("::llvm::cast<::mlir::IntegerAttr>(::llvm::cast<::mlir::ArrayAttr>($_self)[", !strconcat(!cast<string>(IntArrayNthElemInRange:index), !strconcat("]).getInt() >= ", !cast<string>(IntArrayNthElemInRange:min))))>, CPred<0: !strconcat("::llvm::cast<::mlir::IntegerAttr>(::llvm::cast<::mlir::ArrayAttr>($_self)[", !strconcat(!cast<string>(IntArrayNthElemInRange:index), !strconcat("]).getInt() <= ", !cast<string>(IntArrayNthElemInRange:max))))>]>;
  string summary = !strconcat("whose ", !strconcat(!cast<string>(IntArrayNthElemInRange:index), !strconcat("-th element must be at least ", !strconcat(!cast<string>(IntArrayNthElemInRange:min), !strconcat(" and at most ", !cast<string>(IntArrayNthElemInRange:max))))));
}
class IntArrayNthElemMaxValue<int IntArrayNthElemMaxValue:index = ?, int IntArrayNthElemMaxValue:max = ?> {	// Constraint AttrConstraint
  Pred predicate = And<0: [CPred<0: !strconcat("::llvm::cast<::mlir::ArrayAttr>($_self).size() > ", !cast<string>(IntArrayNthElemMaxValue:index))>, CPred<0: !strconcat("::llvm::cast<::mlir::IntegerAttr>(::llvm::cast<::mlir::ArrayAttr>($_self)[", !strconcat(!cast<string>(IntArrayNthElemMaxValue:index), !strconcat("]).getInt() <= ", !cast<string>(IntArrayNthElemMaxValue:max))))>]>;
  string summary = !strconcat("whose ", !strconcat(!cast<string>(IntArrayNthElemMaxValue:index), !strconcat("-th element must be at most ", !cast<string>(IntArrayNthElemMaxValue:max))));
}
class IntArrayNthElemMinValue<int IntArrayNthElemMinValue:index = ?, int IntArrayNthElemMinValue:min = ?> {	// Constraint AttrConstraint
  Pred predicate = And<0: [CPred<0: !strconcat("::llvm::cast<::mlir::ArrayAttr>($_self).size() > ", !cast<string>(IntArrayNthElemMinValue:index))>, CPred<0: !strconcat("::llvm::cast<::mlir::IntegerAttr>(::llvm::cast<::mlir::ArrayAttr>($_self)[", !strconcat(!cast<string>(IntArrayNthElemMinValue:index), !strconcat("]).getInt() >= ", !cast<string>(IntArrayNthElemMinValue:min))))>]>;
  string summary = !strconcat("whose ", !strconcat(!cast<string>(IntArrayNthElemMinValue:index), !strconcat("-th element must be at least ", !cast<string>(IntArrayNthElemMinValue:min))));
}
class IntElementsAttrBase<Pred IntElementsAttrBase:condition = ?, string IntElementsAttrBase:summary = ?> {	// Constraint AttrConstraint Attr ElementsAttrBase
  Pred predicate = And<0: [anonymous_247, IntElementsAttrBase:condition]>;
  string summary = IntElementsAttrBase:summary;
  code storageType = [{ ::mlir::DenseIntElementsAttr }];
  code returnType = [{ ::mlir::DenseIntElementsAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = ?;
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class IntElementsAttrOf<int IntElementsAttrOf:width = ?> {	// Constraint AttrConstraint Attr ElementsAttrBase IntElementsAttrBase
  Pred predicate = And<0: [anonymous_247, CPred<0: !strconcat("::llvm::cast<::mlir::DenseIntElementsAttr>($_self).getType().getElementType().isInteger(", !strconcat(!cast<string>(IntElementsAttrOf:width), ")"))>]>;
  string summary = !strconcat(!cast<string>(IntElementsAttrOf:width), "-bit integer elements attribute");
  code storageType = [{ ::mlir::DenseIntElementsAttr }];
  code returnType = [{ ::mlir::DenseIntElementsAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = ?;
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class IntMaxValue<int IntMaxValue:n = ?> {	// Constraint AttrConstraint
  Pred predicate = CPred<0: !strconcat("::llvm::cast<::mlir::IntegerAttr>($_self).getInt() <= ", !cast<string>(IntMaxValue:n))>;
  string summary = !strconcat("whose maximum value is ", !cast<string>(IntMaxValue:n));
}
class IntMinValue<int IntMinValue:n = ?> {	// Constraint AttrConstraint
  Pred predicate = CPred<0: !strconcat("::llvm::cast<::mlir::IntegerAttr>($_self).getInt() >= ", !cast<string>(IntMinValue:n))>;
  string summary = !strconcat("whose minimum value is ", !cast<string>(IntMinValue:n));
}
class IntNEQValue<int IntNEQValue:n = ?> {	// Constraint AttrConstraint
  Pred predicate = CPred<0: !strconcat("::llvm::cast<::mlir::IntegerAttr>($_self).getInt() != ", !cast<string>(IntNEQValue:n))>;
  string summary = !strconcat("whose value is not ", !cast<string>(IntNEQValue:n));
}
class IntProperty<string IntProperty:storageTypeParam = "", string IntProperty:desc = ""> {	// Property
  string summary = IntProperty:desc;
  string description = "";
  string storageType = IntProperty:storageTypeParam;
  string interfaceType = IntProperty:storageTypeParam;
  string convertFromStorage = "$_storage";
  string assignToStorage = "$_storage = $_value";
  code convertToAttribute = [{
    convertToAttribute($_ctxt, $_storage)
  }];
  code convertFromAttribute = [{
    return convertFromAttribute($_storage, $_attr, $_diag);
  }];
  code hashProperty = [{
    llvm::hash_value($_storage);
  }];
  code writeToMlirBytecode = [{
    $_writer.writeVarInt($_storage);
  }];
  code readFromMlirBytecode = [{
    uint64_t val;
    if (failed($_reader.readVarInt(val)))
      return ::mlir::failure();
    $_storage = val;
  }];
  string defaultValue = ?;
}
class Interface<string Interface:name = ?, list<Interface> Interface:baseInterfacesArg = []> {
  string description = "";
  string cppInterfaceName = Interface:name;
  string cppNamespace = "";
  list<InterfaceMethod> methods = [];
  string extraClassDeclaration = "";
  string extraSharedClassDeclaration = "";
  string extraClassOf = "";
  list<Interface> baseInterfaces = Interface:baseInterfacesArg;
}
class InterfaceMethod<string InterfaceMethod:desc = ?, string InterfaceMethod:retTy = ?, string InterfaceMethod:methodName = ?, dag InterfaceMethod:args = (ins), code InterfaceMethod:methodBody = [{}], code InterfaceMethod:defaultImplementation = [{}]> {
  string description = InterfaceMethod:desc;
  string name = InterfaceMethod:methodName;
  string returnType = InterfaceMethod:retTy;
  dag arguments = InterfaceMethod:args;
  string body = InterfaceMethod:methodBody;
  string defaultBody = InterfaceMethod:defaultImplementation;
}
class InterfaceTrait<string InterfaceTrait:name = ?> {	// Trait NativeTrait
  string trait = !strconcat(InterfaceTrait:name, "::Trait");
  string cppNamespace = "";
  code extraConcreteClassDeclaration = [{}];
  code extraConcreteClassDefinition = [{}];
  string extraTraitClassDeclaration = "";
}
class IntrinsicResource<string IntrinsicResource:resourceName = ?> {	// Resource
  string name = !strconcat("::mlir::SideEffects::", IntrinsicResource:resourceName);
}
class IsFixedVectorOfLengthPred<list<int> IsFixedVectorOfLengthPred:allowedLengths = ?> {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsFixedVectorTypePred, Or<0: !foreach(allowedlength, IsFixedVectorOfLengthPred:allowedLengths, CPred<0: !strconcat([{::llvm::cast<::mlir::VectorType>($_self).getNumElements()
                           == }], !cast<string>(allowedlength))>)>];
}
class IsFixedVectorOfRankPred<list<int> IsFixedVectorOfRankPred:allowedRanks = ?> {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsFixedVectorTypePred, Or<0: !foreach(allowedlength, IsFixedVectorOfRankPred:allowedRanks, CPred<0: !strconcat([{::llvm::cast<::mlir::VectorType>($_self).getRank()
                           == }], !cast<string>(allowedlength))>)>];
}
class IsNthDimSizeIsOneOfPred<int IsNthDimSizeIsOneOfPred:n = ?, list<int> IsNthDimSizeIsOneOfPred:allowedSizes = ?> {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [CPred<0: !strconcat("::llvm::cast<::mlir::ShapedType>($_self).getRank() >= ", !cast<string>(NormalizeIndex<0: IsNthDimSizeIsOneOfPred:n>.ret))>, CPred<0: !strconcat("::llvm::is_contained(ArrayRef<int64_t>({", !strconcat(!interleave(IsNthDimSizeIsOneOfPred:allowedSizes, ", "), !strconcat("}), ", !strconcat("::llvm::cast<::mlir::ShapedType>($_self).getDimSize(", !strconcat(!if(!lt(IsNthDimSizeIsOneOfPred:n, 0), !strconcat("::llvm::cast<::mlir::ShapedType>($_self).getRank() + ", !cast<string>(IsNthDimSizeIsOneOfPred:n)), !strconcat("", !cast<string>(IsNthDimSizeIsOneOfPred:n))), "))")))))>];
}
class IsScalableVectorOfLengthPred<list<int> IsScalableVectorOfLengthPred:allowedLengths = ?> {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsVectorTypeWithAnyDimScalablePred, Or<0: !foreach(allowedlength, IsScalableVectorOfLengthPred:allowedLengths, CPred<0: !strconcat([{::llvm::cast<::mlir::VectorType>($_self).getNumElements()
                           == }], !cast<string>(allowedlength))>)>];
}
class IsScalableVectorOfRankPred<list<int> IsScalableVectorOfRankPred:allowedRanks = ?> {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsVectorTypeWithAnyDimScalablePred, Or<0: !foreach(allowedlength, IsScalableVectorOfRankPred:allowedRanks, CPred<0: !strconcat([{::llvm::cast<::mlir::VectorType>($_self).getRank()
                           == }], !cast<string>(allowedlength))>)>];
}
class IsVectorOfLengthPred<list<int> IsVectorOfLengthPred:allowedLengths = ?> {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsVectorTypePred, Or<0: !foreach(allowedlength, IsVectorOfLengthPred:allowedLengths, CPred<0: !strconcat([{::llvm::cast<::mlir::VectorType>($_self).getNumElements()
                           == }], !cast<string>(allowedlength))>)>];
}
class IsVectorOfRankPred<list<int> IsVectorOfRankPred:allowedRanks = ?> {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsVectorTypePred, Or<0: !foreach(allowedlength, IsVectorOfRankPred:allowedRanks, CPred<0: !strconcat([{::llvm::cast<::mlir::VectorType>($_self).getRank()
                           == }], !cast<string>(allowedlength))>)>];
}
class IsVectorOfShape<list<int> IsVectorOfShape:shape = ?> {	// Pred CPred
  string predExpr = !strconcat("(", !strconcat(!strconcat("::llvm::cast<::mlir::VectorType>($_self).getShape() == ArrayRef<int64_t>({", !strconcat(!interleave(IsVectorOfShape:shape, ", "), "})")), ")"));
}
class MaxSizedRegion<int MaxSizedRegion:numBlocks = ?> {	// Constraint RegionConstraint Region
  Pred predicate = CPred<0: !strconcat("::llvm::hasNItemsOrLess($_self, ", !strconcat(!cast<string>(MaxSizedRegion:numBlocks), ")"))>;
  string summary = !strconcat("region with at most ", !strconcat(!cast<string>(MaxSizedRegion:numBlocks), " blocks"));
}
class MemAlloc<Resource MemAlloc:resource = ?, int MemAlloc:stage = 0, EffectRange MemAlloc:range = PartialEffect> {	// OpVariableDecorator SideEffect MemoryEffect
  string baseEffectName = "::mlir::MemoryEffects::Effect";
  string interfaceTrait = "MemoryEffectOpInterface::Trait";
  string cppNamespace = "::mlir";
  string effect = "::mlir::MemoryEffects::Allocate";
  string resource = MemAlloc:resource.name;
  int stage = MemAlloc:stage;
  bit effectOnFullRegion = !cast<bit>(MemAlloc:range.Value);
}
class MemAllocAt<int MemAllocAt:stage = ?, EffectRange MemAllocAt:range = PartialEffect> {	// OpVariableDecorator SideEffect MemoryEffect MemAlloc
  string baseEffectName = "::mlir::MemoryEffects::Effect";
  string interfaceTrait = "MemoryEffectOpInterface::Trait";
  string cppNamespace = "::mlir";
  string effect = "::mlir::MemoryEffects::Allocate";
  string resource = "::mlir::SideEffects::DefaultResource";
  int stage = MemAllocAt:stage;
  bit effectOnFullRegion = !cast<bit>(MemAllocAt:range.Value);
}
class MemFree<Resource MemFree:resource = ?, int MemFree:stage = 0, EffectRange MemFree:range = PartialEffect> {	// OpVariableDecorator SideEffect MemoryEffect
  string baseEffectName = "::mlir::MemoryEffects::Effect";
  string interfaceTrait = "MemoryEffectOpInterface::Trait";
  string cppNamespace = "::mlir";
  string effect = "::mlir::MemoryEffects::Free";
  string resource = MemFree:resource.name;
  int stage = MemFree:stage;
  bit effectOnFullRegion = !cast<bit>(MemFree:range.Value);
}
class MemFreeAt<int MemFreeAt:stage = ?, EffectRange MemFreeAt:range = PartialEffect> {	// OpVariableDecorator SideEffect MemoryEffect MemFree
  string baseEffectName = "::mlir::MemoryEffects::Effect";
  string interfaceTrait = "MemoryEffectOpInterface::Trait";
  string cppNamespace = "::mlir";
  string effect = "::mlir::MemoryEffects::Free";
  string resource = "::mlir::SideEffects::DefaultResource";
  int stage = MemFreeAt:stage;
  bit effectOnFullRegion = !cast<bit>(MemFreeAt:range.Value);
}
class MemRead<Resource MemRead:resource = ?, int MemRead:stage = 0, EffectRange MemRead:range = PartialEffect> {	// OpVariableDecorator SideEffect MemoryEffect
  string baseEffectName = "::mlir::MemoryEffects::Effect";
  string interfaceTrait = "MemoryEffectOpInterface::Trait";
  string cppNamespace = "::mlir";
  string effect = "::mlir::MemoryEffects::Read";
  string resource = MemRead:resource.name;
  int stage = MemRead:stage;
  bit effectOnFullRegion = !cast<bit>(MemRead:range.Value);
}
class MemReadAt<int MemReadAt:stage = ?, EffectRange MemReadAt:range = PartialEffect> {	// OpVariableDecorator SideEffect MemoryEffect MemRead
  string baseEffectName = "::mlir::MemoryEffects::Effect";
  string interfaceTrait = "MemoryEffectOpInterface::Trait";
  string cppNamespace = "::mlir";
  string effect = "::mlir::MemoryEffects::Read";
  string resource = "::mlir::SideEffects::DefaultResource";
  int stage = MemReadAt:stage;
  bit effectOnFullRegion = !cast<bit>(MemReadAt:range.Value);
}
class MemRefOf<list<Type> MemRefOf:allowedTypes = ?> {	// Constraint TypeConstraint Type ShapedContainerType
  Pred predicate = And<0: [IsMemRefTypePred, Concat<0: "[](::mlir::Type elementType) { return ", 1: SubstLeaves<0: "$_self", 1: "elementType", 2: AnyTypeOf<0: MemRefOf:allowedTypes>.predicate>, 2: "; }(::llvm::cast<::mlir::ShapedType>($_self).getElementType())">]>;
  string summary = !strconcat("memref", !strconcat(" of ", !strconcat(AnyTypeOf<0: MemRefOf:allowedTypes>.summary, " values")));
  string cppClassName = "::mlir::MemRefType";
  string description = "";
  string builderCall = "";
}
class MemRefRankOf<list<Type> MemRefRankOf:allowedTypes = ?, list<int> MemRefRankOf:ranks = ?> {	// Constraint TypeConstraint Type ConfinedType
  Pred predicate = And<0: [MemRefOf<0: MemRefRankOf:allowedTypes>.predicate, HasAnyRankOfPred<0: MemRefRankOf:ranks>]>;
  string summary = !strconcat(!interleave(!foreach(rank, MemRefRankOf:ranks, !strconcat(!cast<string>(rank), "D")), "/"), !strconcat(" ", MemRefOf<0: MemRefRankOf:allowedTypes>.summary));
  string cppClassName = "::mlir::MemRefType";
  string description = "";
  string builderCall = "";
}
class MemWrite<Resource MemWrite:resource = ?, int MemWrite:stage = 0, EffectRange MemWrite:range = PartialEffect> {	// OpVariableDecorator SideEffect MemoryEffect
  string baseEffectName = "::mlir::MemoryEffects::Effect";
  string interfaceTrait = "MemoryEffectOpInterface::Trait";
  string cppNamespace = "::mlir";
  string effect = "::mlir::MemoryEffects::Write";
  string resource = MemWrite:resource.name;
  int stage = MemWrite:stage;
  bit effectOnFullRegion = !cast<bit>(MemWrite:range.Value);
}
class MemWriteAt<int MemWriteAt:stage = ?, EffectRange MemWriteAt:range = PartialEffect> {	// OpVariableDecorator SideEffect MemoryEffect MemWrite
  string baseEffectName = "::mlir::MemoryEffects::Effect";
  string interfaceTrait = "MemoryEffectOpInterface::Trait";
  string cppNamespace = "::mlir";
  string effect = "::mlir::MemoryEffects::Write";
  string resource = "::mlir::SideEffects::DefaultResource";
  int stage = MemWriteAt:stage;
  bit effectOnFullRegion = !cast<bit>(MemWriteAt:range.Value);
}
class MemoryEffect<string MemoryEffect:effectName = ?, Resource MemoryEffect:resource = ?, int MemoryEffect:stage = ?, EffectRange MemoryEffect:range = ?> {	// OpVariableDecorator SideEffect
  string baseEffectName = "::mlir::MemoryEffects::Effect";
  string interfaceTrait = "MemoryEffectOpInterface::Trait";
  string cppNamespace = "::mlir";
  string effect = MemoryEffect:effectName;
  string resource = MemoryEffect:resource.name;
  int stage = MemoryEffect:stage;
  bit effectOnFullRegion = !cast<bit>(MemoryEffect:range.Value);
}
class MemoryEffects<list<MemoryEffect> MemoryEffects:effects = []> {	// Trait NativeTrait InterfaceTrait OpInterfaceTrait SideEffectsTraitBase
  string trait = "MemoryEffectOpInterface::Trait";
  string cppNamespace = "::mlir";
  code extraConcreteClassDeclaration = [{}];
  code extraConcreteClassDefinition = [{}];
  string extraTraitClassDeclaration = "";
  code verify = [{}];
  bit verifyWithRegions = 0;
  list<Trait> dependentTraits = [];
  string baseEffectName = "::mlir::MemoryEffects::Effect";
  list<SideEffect> effects = MemoryEffects:effects;
}
class MinSizedRegion<int MinSizedRegion:numBlocks = ?> {	// Constraint RegionConstraint Region
  Pred predicate = CPred<0: !strconcat("::llvm::hasNItemsOrMore($_self, ", !strconcat(!cast<string>(MinSizedRegion:numBlocks), ")"))>;
  string summary = !strconcat("region with at least ", !strconcat(!cast<string>(MinSizedRegion:numBlocks), " blocks"));
}
class MixedContainerType<Type MixedContainerType:etype = ?, Pred MixedContainerType:containerPred = ?, string MixedContainerType:elementTypesCall = ?, string MixedContainerType:descr = ?> {	// Constraint TypeConstraint Type
  Pred predicate = And<0: [MixedContainerType:containerPred, Concat<0: !strconcat("::llvm::all_of(", !strconcat(MixedContainerType:elementTypesCall, ", [](::mlir::Type t) { return t && (")), 1: SubstLeaves<0: "$_self", 1: "t", 2: MixedContainerType:etype.predicate>, 2: "); })">]>;
  string summary = !strconcat(MixedContainerType:descr, !strconcat(" with any combination of ", !strconcat(MixedContainerType:etype.summary, " values")));
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
  Type elementType = MixedContainerType:etype;
  string getElementTypesCall = MixedContainerType:elementTypesCall;
}
class NativeAttrTrait<string NativeAttrTrait:name = ?, code NativeAttrTrait:extraAttrDeclaration = [{}], code NativeAttrTrait:extraAttrDefinition = [{}]> {	// Trait NativeTrait
  string trait = NativeAttrTrait:name;
  string cppNamespace = "::mlir::AttributeTrait";
  string extraConcreteClassDeclaration = NativeAttrTrait:extraAttrDeclaration;
  string extraConcreteClassDefinition = NativeAttrTrait:extraAttrDefinition;
}
class NativeOpTrait<string NativeOpTrait:name = ?, list<Trait> NativeOpTrait:traits = [], code NativeOpTrait:extraOpDeclaration = [{}], code NativeOpTrait:extraOpDefinition = [{}]> {	// Trait NativeTrait
  string trait = NativeOpTrait:name;
  string cppNamespace = "::mlir::OpTrait";
  string extraConcreteClassDeclaration = NativeOpTrait:extraOpDeclaration;
  string extraConcreteClassDefinition = NativeOpTrait:extraOpDefinition;
  list<Trait> dependentTraits = NativeOpTrait:traits;
}
class NativeTrait<string NativeTrait:name = ?, string NativeTrait:entityType = ?, code NativeTrait:extraClassDeclaration = [{}], code NativeTrait:extraClassDefinition = [{}]> {	// Trait
  string trait = NativeTrait:name;
  string cppNamespace = !strconcat("::mlir::", !strconcat(NativeTrait:entityType, "Trait"));
  string extraConcreteClassDeclaration = NativeTrait:extraClassDeclaration;
  string extraConcreteClassDefinition = NativeTrait:extraClassDefinition;
}
class NativeTypeTrait<string NativeTypeTrait:name = ?, code NativeTypeTrait:extraTypeDeclaration = [{}], code NativeTypeTrait:extraTypeDefinition = [{}]> {	// Trait NativeTrait
  string trait = NativeTypeTrait:name;
  string cppNamespace = "::mlir::TypeTrait";
  string extraConcreteClassDeclaration = NativeTypeTrait:extraTypeDeclaration;
  string extraConcreteClassDefinition = NativeTypeTrait:extraTypeDefinition;
}
class Neg<Pred Neg:child = ?> {	// Pred CombinedPred
  PredCombinerKind kind = PredCombinerNot;
  list<Pred> children = [Neg:child];
}
class NestedTupleOf<list<Type> NestedTupleOf:allowedTypes = ?> {	// Constraint TypeConstraint Type MixedContainerType
  Pred predicate = And<0: [IsTupleTypePred, Concat<0: "::llvm::all_of(getFlattenedTypes(::llvm::cast<::mlir::TupleType>($_self)), [](::mlir::Type t) { return t && (", 1: SubstLeaves<0: "$_self", 1: "t", 2: AnyTypeOf<0: NestedTupleOf:allowedTypes>.predicate>, 2: "); })">]>;
  string summary = !strconcat("nested tuple", !strconcat(" with any combination of ", !strconcat(AnyTypeOf<0: NestedTupleOf:allowedTypes>.summary, " values")));
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
  Type elementType = AnyTypeOf<0: NestedTupleOf:allowedTypes>;
  string getElementTypesCall = "getFlattenedTypes(::llvm::cast<::mlir::TupleType>($_self))";
}
class Non0RankedMemRefOf<list<Type> Non0RankedMemRefOf:allowedTypes = ?> {	// Constraint TypeConstraint Type ConfinedType
  Pred predicate = And<0: [MemRefOf<0: Non0RankedMemRefOf:allowedTypes>.predicate, anonymous_110]>;
  string summary = !strconcat("non-0-ranked.", MemRefOf<0: Non0RankedMemRefOf:allowedTypes>.summary);
  string cppClassName = "::mlir::MemRefType";
  string description = "";
  string builderCall = "";
}
class Non0RankedTensorOf<list<Type> Non0RankedTensorOf:allowedTypes = ?> {	// Constraint TypeConstraint Type ShapedContainerType TensorOf
  Pred predicate = And<0: [anonymous_112, Concat<0: "[](::mlir::Type elementType) { return ", 1: SubstLeaves<0: "$_self", 1: "elementType", 2: AnyTypeOf<0: Non0RankedTensorOf:allowedTypes>.predicate>, 2: "; }(::llvm::cast<::mlir::ShapedType>($_self).getElementType())">]>;
  string summary = !strconcat("non-0-ranked.tensor", !strconcat(" of ", !strconcat(AnyTypeOf<0: Non0RankedTensorOf:allowedTypes>.summary, " values")));
  string cppClassName = "::mlir::TensorType";
  string description = "";
  string builderCall = "";
}
class NormalizeIndex<int NormalizeIndex:value = ?> {
  int ret = !if(!lt(NormalizeIndex:value, 0), !sub(0, NormalizeIndex:value), !add(NormalizeIndex:value, 1));
}
class Op<Dialect Op:dialect = ?, string Op:mnemonic = ?, list<Trait> Op:props = []> {
  Dialect opDialect = Op:dialect;
  string opName = Op:mnemonic;
  string cppNamespace = Op:dialect.cppNamespace;
  string summary = "";
  string description = "";
  OpDocGroup opDocGroup = ?;
  dag arguments = (ins);
  dag results = (outs);
  dag regions = (region);
  dag successors = (successor);
  list<OpBuilder> builders = ?;
  bit skipDefaultBuilders = 0;
  string assemblyFormat = ?;
  bit hasCustomAssemblyFormat = 0;
  bit hasVerifier = 0;
  bit hasRegionVerifier = 0;
  bit hasCanonicalizer = 0;
  bit hasCanonicalizeMethod = 0;
  bit hasFolder = 0;
  bit useCustomPropertiesEncoding = 0;
  list<Trait> traits = Op:props;
  string extraClassDeclaration = ?;
  string extraClassDefinition = ?;
}
class OpBuilder<dag OpBuilder:p = ?, string OpBuilder:b = ""> {
  dag dagParams = OpBuilder:p;
  string body = OpBuilder:b;
}
class OpDocGroup {
  string summary = ?;
  string description = ?;
}
class OpInterface<string OpInterface:name = ?, list<Interface> OpInterface:baseInterfaces = []> {	// Interface Trait NativeTrait InterfaceTrait OpInterfaceTrait
  string description = "";
  string cppInterfaceName = OpInterface:name;
  string cppNamespace = "";
  list<InterfaceMethod> methods = [];
  string extraClassDeclaration = "";
  string extraSharedClassDeclaration = "";
  string extraClassOf = "";
  list<Interface> baseInterfaces = OpInterface:baseInterfaces;
  string trait = !strconcat(OpInterface:name, "::Trait");
  code extraConcreteClassDeclaration = [{}];
  code extraConcreteClassDefinition = [{}];
  string extraTraitClassDeclaration = "";
  code verify = [{}];
  bit verifyWithRegions = 0;
  list<Trait> dependentTraits = [];
}
class OpInterfaceTrait<string OpInterfaceTrait:name = ?, code OpInterfaceTrait:verifyBody = [{}], list<Trait> OpInterfaceTrait:traits = []> {	// Trait NativeTrait InterfaceTrait
  string trait = !strconcat(OpInterfaceTrait:name, "::Trait");
  string cppNamespace = "";
  code extraConcreteClassDeclaration = [{}];
  code extraConcreteClassDefinition = [{}];
  string extraTraitClassDeclaration = "";
  string verify = OpInterfaceTrait:verifyBody;
  bit verifyWithRegions = 0;
  list<Trait> dependentTraits = OpInterfaceTrait:traits;
}
class OpVariable<Constraint OpVariable:varConstraint = ?, string OpVariable:desc = "", list<OpVariableDecorator> OpVariable:varDecorators = []> {
  Constraint constraint = OpVariable:varConstraint;
  string summary = OpVariable:desc;
  list<OpVariableDecorator> decorators = OpVariable:varDecorators;
}
class OpVariableDecorator {
}
class OpaqueType<string OpaqueType:dialect = ?, string OpaqueType:name = ?, string OpaqueType:summary = ?> {	// Constraint TypeConstraint Type BuildableType
  Pred predicate = CPred<0: !strconcat("isOpaqueTypeWithName($_self, "", !strconcat(OpaqueType:dialect, !strconcat("", "", !strconcat(OpaqueType:name, "")"))))>;
  string summary = OpaqueType:summary;
  string cppClassName = "::mlir::OpaqueType";
  string description = "";
  string builderCall = !strconcat("::mlir::OpaqueType::get($_builder.getStringAttr("", !strconcat(OpaqueType:dialect, !strconcat(""), "", !strconcat(OpaqueType:name, "")"))));
}
class Optional<Type Optional:type = ?> {	// Constraint TypeConstraint
  Pred predicate = Optional:type.predicate;
  string summary = Optional:type.summary;
  string cppClassName = Optional:type.cppClassName;
  Type baseType = Optional:type;
}
class OptionalArrayRefParameter<string OptionalArrayRefParameter:arrayOf = ?, string OptionalArrayRefParameter:desc = ""> {	// AttrOrTypeParameter OptionalParameter
  code allocator = [{$_dst = $_allocator.copyInto($_self);}];
  string comparator = !strconcat(cppType, !strconcat("($_lhs) == ", !strconcat(cppType, "($_rhs)")));
  string cppType = !strconcat("::llvm::ArrayRef<", !strconcat(OptionalArrayRefParameter:arrayOf, ">"));
  string cppAccessorType = !strconcat("::llvm::ArrayRef<", !strconcat(OptionalArrayRefParameter:arrayOf, ">"));
  string cppStorageType = !strconcat("::llvm::SmallVector<", !strconcat(OptionalArrayRefParameter:arrayOf, ">"));
  string convertFromStorage = "$_self";
  string summary = OptionalArrayRefParameter:desc;
  string syntax = ?;
  string parser = ?;
  string printer = ?;
  string defaultValue = !strconcat(cppStorageType, "()");
}
class OptionalAttr<Attr OptionalAttr:attr = ?> {	// Constraint AttrConstraint Attr
  Pred predicate = OptionalAttr:attr.predicate;
  string summary = OptionalAttr:attr.summary;
  string storageType = OptionalAttr:attr.storageType;
  string returnType = !strconcat("::std::optional<", !strconcat(OptionalAttr:attr.returnType, ">"));
  string convertFromStorage = !strconcat("$_self ? ", !strconcat(returnType, !strconcat("(", !strconcat(OptionalAttr:attr.convertFromStorage, ") : (::std::nullopt)"))));
  string constBuilderCall = ?;
  string defaultValue = ?;
  Type valueType = OptionalAttr:attr.valueType;
  bit isOptional = 1;
  Attr baseAttr = OptionalAttr:attr;
  string cppNamespace = "";
  string description = "";
}
class OptionalParameter<string OptionalParameter:type = ?, string OptionalParameter:desc = ""> {	// AttrOrTypeParameter
  string allocator = ?;
  string comparator = ?;
  string cppType = OptionalParameter:type;
  string cppAccessorType = OptionalParameter:type;
  string cppStorageType = cppType;
  string convertFromStorage = "$_self";
  string summary = OptionalParameter:desc;
  string syntax = ?;
  string parser = ?;
  string printer = ?;
  string defaultValue = !strconcat(cppStorageType, "()");
}
class OptionalTypesMatchWith<string OptionalTypesMatchWith:summary = ?, string OptionalTypesMatchWith:lhsArg = ?, string OptionalTypesMatchWith:rhsArg = ?, string OptionalTypesMatchWith:transform = ?, string OptionalTypesMatchWith:comparator = "std::equal_to<>()"> {	// Trait PredTrait PredOpTrait TypesMatchWith
  string summary = OptionalTypesMatchWith:summary;
  Pred predicate = CPred<0: !strconcat(!strconcat("!get", !strconcat(snakeCaseToCamelCase<0: OptionalTypesMatchWith:lhsArg>.ret, !strconcat("()", !strconcat(" || !get", !strconcat(snakeCaseToCamelCase<0: OptionalTypesMatchWith:rhsArg>.ret, !strconcat("() || ", OptionalTypesMatchWith:comparator)))))), !strconcat("(", !strconcat(!subst("$_self", !strconcat("$", !strconcat(OptionalTypesMatchWith:lhsArg, ".getType()")), OptionalTypesMatchWith:transform), !strconcat(", $", !strconcat(OptionalTypesMatchWith:rhsArg, ".getType())")))))>;
  list<Trait> dependentTraits = [];
  string lhs = OptionalTypesMatchWith:lhsArg;
  string rhs = OptionalTypesMatchWith:rhsArg;
  string transformer = OptionalTypesMatchWith:transform;
}
class Or<list<Pred> Or:children = ?> {	// Pred CombinedPred
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = Or:children;
}
class ParamNativeAttrTrait<string ParamNativeAttrTrait:prop = ?, string ParamNativeAttrTrait:params = ?> {	// Trait NativeTrait ParamNativeTrait
  string trait = !strconcat(ParamNativeAttrTrait:prop, !strconcat("<", !strconcat(ParamNativeAttrTrait:params, ">::Impl")));
  string cppNamespace = "::mlir::AttributeTrait";
  code extraConcreteClassDeclaration = [{}];
  code extraConcreteClassDefinition = [{}];
}
class ParamNativeOpTrait<string ParamNativeOpTrait:prop = ?, string ParamNativeOpTrait:params = ?, list<Trait> ParamNativeOpTrait:traits = []> {	// Trait NativeTrait ParamNativeTrait
  string trait = !strconcat(ParamNativeOpTrait:prop, !strconcat("<", !strconcat(ParamNativeOpTrait:params, ">::Impl")));
  string cppNamespace = "::mlir::OpTrait";
  code extraConcreteClassDeclaration = [{}];
  code extraConcreteClassDefinition = [{}];
  list<Trait> dependentTraits = ParamNativeOpTrait:traits;
}
class ParamNativeTrait<string ParamNativeTrait:prop = ?, string ParamNativeTrait:params = ?, string ParamNativeTrait:entityType = ?> {	// Trait NativeTrait
  string trait = !strconcat(ParamNativeTrait:prop, !strconcat("<", !strconcat(ParamNativeTrait:params, ">::Impl")));
  string cppNamespace = !strconcat("::mlir::", !strconcat(ParamNativeTrait:entityType, "Trait"));
  code extraConcreteClassDeclaration = [{}];
  code extraConcreteClassDefinition = [{}];
}
class ParamNativeTypeTrait<string ParamNativeTypeTrait:prop = ?, string ParamNativeTypeTrait:params = ?> {	// Trait NativeTrait ParamNativeTrait
  string trait = !strconcat(ParamNativeTypeTrait:prop, !strconcat("<", !strconcat(ParamNativeTypeTrait:params, ">::Impl")));
  string cppNamespace = "::mlir::TypeTrait";
  code extraConcreteClassDeclaration = [{}];
  code extraConcreteClassDefinition = [{}];
}
class ParentOneOf<list<string> ParentOneOf:ops = ?> {	// Trait NativeTrait ParamNativeTrait ParamNativeOpTrait StructuralOpTrait
  string trait = !strconcat("HasParent", !strconcat("<", !strconcat(!interleave(ParentOneOf:ops, ", "), ">::Impl")));
  string cppNamespace = "::mlir::OpTrait";
  code extraConcreteClassDeclaration = [{}];
  code extraConcreteClassDefinition = [{}];
  list<Trait> dependentTraits = [];
}
class Petite_Op<string Petite_Op:mnemonic = ?, list<Trait> Petite_Op:traits = []> {	// Op
  Dialect opDialect = Petite_Dialect;
  string opName = Petite_Op:mnemonic;
  string cppNamespace = "::mlir::petite";
  string summary = "";
  string description = "";
  OpDocGroup opDocGroup = ?;
  dag arguments = (ins);
  dag results = (outs);
  dag regions = (region);
  dag successors = (successor);
  list<OpBuilder> builders = ?;
  bit skipDefaultBuilders = 0;
  string assemblyFormat = ?;
  bit hasCustomAssemblyFormat = 0;
  bit hasVerifier = 0;
  bit hasRegionVerifier = 0;
  bit hasCanonicalizer = 0;
  bit hasCanonicalizeMethod = 0;
  bit hasFolder = 0;
  bit useCustomPropertiesEncoding = 0;
  list<Trait> traits = Petite_Op:traits;
  string extraClassDeclaration = ?;
  string extraClassDefinition = ?;
}
class Pred {
}
class PredAttrTrait<string PredAttrTrait:descr = ?, Pred PredAttrTrait:pred = ?> {	// Trait PredTrait
  string summary = PredAttrTrait:descr;
  Pred predicate = PredAttrTrait:pred;
}
class PredCombinerKind {
}
class PredOpTrait<string PredOpTrait:descr = ?, Pred PredOpTrait:pred = ?, list<Trait> PredOpTrait:traits = []> {	// Trait PredTrait
  string summary = PredOpTrait:descr;
  Pred predicate = PredOpTrait:pred;
  list<Trait> dependentTraits = PredOpTrait:traits;
}
class PredTrait<string PredTrait:descr = ?, Pred PredTrait:pred = ?> {	// Trait
  string summary = PredTrait:descr;
  Pred predicate = PredTrait:pred;
}
class PredTypeTrait<string PredTypeTrait:descr = ?, Pred PredTypeTrait:pred = ?> {	// Trait PredTrait
  string summary = PredTypeTrait:descr;
  Pred predicate = PredTypeTrait:pred;
}
class PromisedAttrInterface<AttrInterface PromisedAttrInterface:interface = ?> {	// Constraint AttrConstraint
  Pred predicate = CPred<0: !strconcat("$_self.hasPromiseOrImplementsInterface<", !strconcat(!if(!empty(PromisedAttrInterface:interface.cppNamespace), "", !strconcat(PromisedAttrInterface:interface.cppNamespace, "::")), !strconcat(PromisedAttrInterface:interface.cppInterfaceName, ">()")))>;
  string summary = !strconcat("promising or implementing the `", !strconcat(PromisedAttrInterface:interface.cppInterfaceName, "` attr interface"));
}
class PromisedTypeInterface<TypeInterface PromisedTypeInterface:interface = ?> {	// Constraint TypeConstraint
  Pred predicate = HasPromiseOrImplementsTypeInterface<0: PromisedTypeInterface:interface>;
  string summary = !strconcat("promising or implementing the `", !strconcat(PromisedTypeInterface:interface.cppInterfaceName, "` type interface"));
  string cppClassName = "::mlir::Type";
}
class Property<string Property:storageTypeParam = "", string Property:desc = ""> {
  string summary = Property:desc;
  string description = "";
  string storageType = Property:storageTypeParam;
  string interfaceType = Property:storageTypeParam;
  string convertFromStorage = "$_storage";
  string assignToStorage = "$_storage = $_value";
  code convertToAttribute = [{
    convertToAttribute($_ctxt, $_storage)
  }];
  code convertFromAttribute = [{
    return convertFromAttribute($_storage, $_attr, $_diag);
  }];
  code hashProperty = [{
    llvm::hash_value($_storage);
  }];
  code writeToMlirBytecode = [{
    writeToMlirBytecode($_writer, $_storage)
  }];
  code readFromMlirBytecode = [{
    if (::mlir::failed(readFromMlirBytecode($_reader, $_storage)))
      return ::mlir::failure();
  }];
  string defaultValue = ?;
}
class RangedTypesMatchWith<string RangedTypesMatchWith:summary = ?, string RangedTypesMatchWith:lhsArg = ?, string RangedTypesMatchWith:rhsArg = ?, string RangedTypesMatchWith:transform = ?> {	// Trait PredTrait PredOpTrait TypesMatchWith
  string summary = RangedTypesMatchWith:summary;
  Pred predicate = CPred<0: !strconcat("llvm::equal", !strconcat("(", !strconcat(!subst("$_self", !strconcat("$", !strconcat(RangedTypesMatchWith:lhsArg, ".getType()")), RangedTypesMatchWith:transform), !strconcat(", $", !strconcat(RangedTypesMatchWith:rhsArg, ".getType())")))))>;
  list<Trait> dependentTraits = [];
  string lhs = RangedTypesMatchWith:lhsArg;
  string rhs = RangedTypesMatchWith:rhsArg;
  string transformer = RangedTypesMatchWith:transform;
}
class Rank<string Rank:name = ?> {	// StrFunc
  string result = !strconcat("::llvm::cast<::mlir::ShapedType>($", !strconcat(Rank:name, ".getType()).getRank()"));
}
class RankedF32ElementsAttr<list<int> RankedF32ElementsAttr:dims = ?> {	// Constraint AttrConstraint Attr ElementsAttrBase RankedFloatElementsAttr
  Pred predicate = CPred<0: !strconcat("::llvm::isa<::mlir::DenseFPElementsAttr>($_self) &&::llvm::cast<::mlir::DenseFPElementsAttr>($_self).getType().getElementType().isF", !strconcat("32", !strconcat("() && ::llvm::cast<::mlir::DenseFPElementsAttr>($_self).getType().hasRank() && ::llvm::cast<::mlir::DenseFPElementsAttr>($_self).getType().getShape() == ::mlir::ArrayRef<int64_t>({", !strconcat(!interleave(RankedF32ElementsAttr:dims, ", "), "})"))))>;
  string summary = !strconcat("32", !strconcat("-bit float elements attribute of shape [", !strconcat(!interleave(RankedF32ElementsAttr:dims, ", "), "]")));
  code storageType = [{ ::mlir::DenseFPElementsAttr }];
  code returnType = [{ ::mlir::DenseFPElementsAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = !strconcat("::llvm::cast<::mlir::DenseFPElementsAttr>(::mlir::DenseElementsAttr::get(::mlir::RankedTensorType::get({", !strconcat(!interleave(RankedF32ElementsAttr:dims, ", "), "}, $_builder.getF32Type()), ::llvm::ArrayRef($0)))"));
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class RankedF64ElementsAttr<list<int> RankedF64ElementsAttr:dims = ?> {	// Constraint AttrConstraint Attr ElementsAttrBase RankedFloatElementsAttr
  Pred predicate = CPred<0: !strconcat("::llvm::isa<::mlir::DenseFPElementsAttr>($_self) &&::llvm::cast<::mlir::DenseFPElementsAttr>($_self).getType().getElementType().isF", !strconcat("64", !strconcat("() && ::llvm::cast<::mlir::DenseFPElementsAttr>($_self).getType().hasRank() && ::llvm::cast<::mlir::DenseFPElementsAttr>($_self).getType().getShape() == ::mlir::ArrayRef<int64_t>({", !strconcat(!interleave(RankedF64ElementsAttr:dims, ", "), "})"))))>;
  string summary = !strconcat("64", !strconcat("-bit float elements attribute of shape [", !strconcat(!interleave(RankedF64ElementsAttr:dims, ", "), "]")));
  code storageType = [{ ::mlir::DenseFPElementsAttr }];
  code returnType = [{ ::mlir::DenseFPElementsAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = !strconcat("::llvm::cast<::mlir::DenseFPElementsAttr>(::mlir::DenseElementsAttr::get(::mlir::RankedTensorType::get({", !strconcat(!interleave(RankedF64ElementsAttr:dims, ", "), "}, $_builder.getF64Type()), ::llvm::ArrayRef($0)))"));
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class RankedFloatElementsAttr<int RankedFloatElementsAttr:width = ?, list<int> RankedFloatElementsAttr:dims = ?> {	// Constraint AttrConstraint Attr ElementsAttrBase
  Pred predicate = CPred<0: !strconcat("::llvm::isa<::mlir::DenseFPElementsAttr>($_self) &&::llvm::cast<::mlir::DenseFPElementsAttr>($_self).getType().getElementType().isF", !strconcat(!cast<string>(RankedFloatElementsAttr:width), !strconcat("() && ::llvm::cast<::mlir::DenseFPElementsAttr>($_self).getType().hasRank() && ::llvm::cast<::mlir::DenseFPElementsAttr>($_self).getType().getShape() == ::mlir::ArrayRef<int64_t>({", !strconcat(!interleave(RankedFloatElementsAttr:dims, ", "), "})"))))>;
  string summary = !strconcat(!cast<string>(RankedFloatElementsAttr:width), !strconcat("-bit float elements attribute of shape [", !strconcat(!interleave(RankedFloatElementsAttr:dims, ", "), "]")));
  code storageType = [{ ::mlir::DenseFPElementsAttr }];
  code returnType = [{ ::mlir::DenseFPElementsAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = !strconcat("::llvm::cast<::mlir::DenseFPElementsAttr>(::mlir::DenseElementsAttr::get(::mlir::RankedTensorType::get({", !strconcat(!interleave(RankedFloatElementsAttr:dims, ", "), !strconcat("}, $_builder.getF", !strconcat(!cast<string>(RankedFloatElementsAttr:width), "Type()), ::llvm::ArrayRef($0)))"))));
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class RankedI32ElementsAttr<list<int> RankedI32ElementsAttr:dims = ?> {	// Constraint AttrConstraint Attr ElementsAttrBase IntElementsAttrBase SignlessIntElementsAttr RankedSignlessIntElementsAttr
  Pred predicate = And<0: [anonymous_263, CPred<0: !strconcat("::llvm::cast<::mlir::DenseIntElementsAttr>($_self).getType().getShape() == ::mlir::ArrayRef<int64_t>({", !strconcat(!interleave(RankedI32ElementsAttr:dims, ", "), "})"))>]>;
  string summary = !strconcat("32", !strconcat("-bit signless int elements attribute of shape [", !strconcat(!interleave(RankedI32ElementsAttr:dims, ", "), "]")));
  code storageType = [{ ::mlir::DenseIntElementsAttr }];
  code returnType = [{ ::mlir::DenseIntElementsAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = !strconcat("::mlir::DenseIntElementsAttr::get(::mlir::RankedTensorType::get({", !strconcat(!interleave(RankedI32ElementsAttr:dims, ", "), "}, $_builder.getIntegerType(32)), ::llvm::ArrayRef($0))"));
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class RankedI64ElementsAttr<list<int> RankedI64ElementsAttr:dims = ?> {	// Constraint AttrConstraint Attr ElementsAttrBase IntElementsAttrBase SignlessIntElementsAttr RankedSignlessIntElementsAttr
  Pred predicate = And<0: [anonymous_265, CPred<0: !strconcat("::llvm::cast<::mlir::DenseIntElementsAttr>($_self).getType().getShape() == ::mlir::ArrayRef<int64_t>({", !strconcat(!interleave(RankedI64ElementsAttr:dims, ", "), "})"))>]>;
  string summary = !strconcat("64", !strconcat("-bit signless int elements attribute of shape [", !strconcat(!interleave(RankedI64ElementsAttr:dims, ", "), "]")));
  code storageType = [{ ::mlir::DenseIntElementsAttr }];
  code returnType = [{ ::mlir::DenseIntElementsAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = !strconcat("::mlir::DenseIntElementsAttr::get(::mlir::RankedTensorType::get({", !strconcat(!interleave(RankedI64ElementsAttr:dims, ", "), "}, $_builder.getIntegerType(64)), ::llvm::ArrayRef($0))"));
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class RankedOrUnrankedMemRefOf<list<Type> RankedOrUnrankedMemRefOf:allowedTypes = ?, list<Pred> RankedOrUnrankedMemRefOf:preds = [], string RankedOrUnrankedMemRefOf:summary = "ranked or unranked memref"> {	// Constraint TypeConstraint Type ShapedContainerType
  Pred predicate = And<0: [And<0: !listconcat([IsBaseMemRefTypePred], RankedOrUnrankedMemRefOf:preds)>, Concat<0: "[](::mlir::Type elementType) { return ", 1: SubstLeaves<0: "$_self", 1: "elementType", 2: AnyTypeOf<0: RankedOrUnrankedMemRefOf:allowedTypes>.predicate>, 2: "; }(::llvm::cast<::mlir::ShapedType>($_self).getElementType())">]>;
  string summary = !strconcat(RankedOrUnrankedMemRefOf:summary, !strconcat(" of ", !strconcat(AnyTypeOf<0: RankedOrUnrankedMemRefOf:allowedTypes>.summary, " values")));
  string cppClassName = "::mlir::BaseMemRefType";
  string description = "";
  string builderCall = "";
}
class RankedSignlessIntElementsAttr<int RankedSignlessIntElementsAttr:width = ?, list<int> RankedSignlessIntElementsAttr:dims = ?> {	// Constraint AttrConstraint Attr ElementsAttrBase IntElementsAttrBase SignlessIntElementsAttr
  Pred predicate = And<0: [SignlessIntElementsAttr<0: RankedSignlessIntElementsAttr:width>.predicate, CPred<0: !strconcat("::llvm::cast<::mlir::DenseIntElementsAttr>($_self).getType().getShape() == ::mlir::ArrayRef<int64_t>({", !strconcat(!interleave(RankedSignlessIntElementsAttr:dims, ", "), "})"))>]>;
  string summary = !strconcat(!cast<string>(RankedSignlessIntElementsAttr:width), !strconcat("-bit signless int elements attribute of shape [", !strconcat(!interleave(RankedSignlessIntElementsAttr:dims, ", "), "]")));
  code storageType = [{ ::mlir::DenseIntElementsAttr }];
  code returnType = [{ ::mlir::DenseIntElementsAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = !strconcat("::mlir::DenseIntElementsAttr::get(::mlir::RankedTensorType::get({", !strconcat(!interleave(RankedSignlessIntElementsAttr:dims, ", "), !strconcat("}, $_builder.getIntegerType(", !strconcat(!cast<string>(RankedSignlessIntElementsAttr:width), ")), ::llvm::ArrayRef($0))"))));
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class RankedTensorOf<list<Type> RankedTensorOf:allowedTypes = ?, list<Pred> RankedTensorOf:preds = [], string RankedTensorOf:summary = "ranked tensor"> {	// Constraint TypeConstraint Type ShapedContainerType
  Pred predicate = And<0: [And<0: !listconcat([IsRankedTensorTypePred], RankedTensorOf:preds)>, Concat<0: "[](::mlir::Type elementType) { return ", 1: SubstLeaves<0: "$_self", 1: "elementType", 2: AnyTypeOf<0: RankedTensorOf:allowedTypes>.predicate>, 2: "; }(::llvm::cast<::mlir::ShapedType>($_self).getElementType())">]>;
  string summary = !strconcat(RankedTensorOf:summary, !strconcat(" of ", !strconcat(AnyTypeOf<0: RankedTensorOf:allowedTypes>.summary, " values")));
  string cppClassName = "::mlir::RankedTensorType";
  string description = "";
  string builderCall = "";
}
class Region<Pred Region:condition = ?, string Region:descr = ""> {	// Constraint RegionConstraint
  Pred predicate = Region:condition;
  string summary = Region:descr;
}
class RegionConstraint<Pred RegionConstraint:predicate = ?, string RegionConstraint:summary = ""> {	// Constraint
  Pred predicate = RegionConstraint:predicate;
  string summary = RegionConstraint:summary;
}
class Res<Constraint Res:constraint = ?, string Res:desc = "", list<OpVariableDecorator> Res:decorators = []> {	// OpVariable
  Constraint constraint = Res:constraint;
  string summary = Res:desc;
  list<OpVariableDecorator> decorators = Res:decorators;
}
class Resource<string Resource:resourceName = ?> {
  string name = Resource:resourceName;
}
class Results<dag Results:rets = ?> {
  dag results = Results:rets;
}
class SI<int SI:width = ?> {	// Constraint TypeConstraint Type BuildableType
  Pred predicate = CPred<0: !strconcat("$_self.isSignedInteger(", !strconcat(!cast<string>(SI:width), ")"))>;
  string summary = !strconcat(!cast<string>(SI:width), "-bit signed integer");
  string cppClassName = "::mlir::IntegerType";
  string description = "";
  string builderCall = !strconcat("$_builder.getIntegerType(", !strconcat(!cast<string>(SI:width), ", /*isSigned=*/true)"));
  int bitwidth = SI:width;
}
class SameBuildabilityAs<Type SameBuildabilityAs:type = ?, string SameBuildabilityAs:builder = ?> {
  string builderCall = !if(!empty(SameBuildabilityAs:type.builderCall), "", SameBuildabilityAs:builder);
}
class ScalableVectorOf<list<Type> ScalableVectorOf:allowedTypes = ?> {	// Constraint TypeConstraint Type ShapedContainerType
  Pred predicate = And<0: [IsVectorTypeWithAnyDimScalablePred, Concat<0: "[](::mlir::Type elementType) { return ", 1: SubstLeaves<0: "$_self", 1: "elementType", 2: AnyTypeOf<0: ScalableVectorOf:allowedTypes>.predicate>, 2: "; }(::llvm::cast<::mlir::ShapedType>($_self).getElementType())">]>;
  string summary = !strconcat("scalable vector", !strconcat(" of ", !strconcat(AnyTypeOf<0: ScalableVectorOf:allowedTypes>.summary, " values")));
  string cppClassName = "::mlir::VectorType";
  string description = "";
  string builderCall = "";
}
class ScalableVectorOfLength<list<int> ScalableVectorOfLength:allowedLengths = ?> {	// Constraint TypeConstraint Type
  Pred predicate = IsScalableVectorOfLengthPred<0: ScalableVectorOfLength:allowedLengths>;
  string summary = !strconcat(" of length ", !interleave(ScalableVectorOfLength:allowedLengths, "/"));
  string cppClassName = "::mlir::VectorType";
  string description = "";
  string builderCall = "";
}
class ScalableVectorOfLengthAndType<list<int> ScalableVectorOfLengthAndType:allowedLengths = ?, list<Type> ScalableVectorOfLengthAndType:allowedTypes = ?> {	// Constraint TypeConstraint Type AllOfType
  Pred predicate = And<0: [ScalableVectorOf<0: ScalableVectorOfLengthAndType:allowedTypes>.predicate, ScalableVectorOfLength<0: ScalableVectorOfLengthAndType:allowedLengths>.predicate]>;
  string summary = !if(!eq(!strconcat(ScalableVectorOf<0: ScalableVectorOfLengthAndType:allowedTypes>.summary, ScalableVectorOfLength<0: ScalableVectorOfLengthAndType:allowedLengths>.summary), ""), !interleave([ScalableVectorOf<0: ScalableVectorOfLengthAndType:allowedTypes>.summary, ScalableVectorOfLength<0: ScalableVectorOfLengthAndType:allowedLengths>.summary], " and "), !strconcat(ScalableVectorOf<0: ScalableVectorOfLengthAndType:allowedTypes>.summary, ScalableVectorOfLength<0: ScalableVectorOfLengthAndType:allowedLengths>.summary));
  string cppClassName = "::mlir::VectorType";
  string description = "";
  string builderCall = "";
  list<Type> allowedTypes = [ScalableVectorOf<0: ScalableVectorOfLengthAndType:allowedTypes>, ScalableVectorOfLength<0: ScalableVectorOfLengthAndType:allowedLengths>];
}
class ScalableVectorOfRank<list<int> ScalableVectorOfRank:allowedRanks = ?> {	// Constraint TypeConstraint Type
  Pred predicate = IsScalableVectorOfRankPred<0: ScalableVectorOfRank:allowedRanks>;
  string summary = !strconcat(" of ranks ", !interleave(ScalableVectorOfRank:allowedRanks, "/"));
  string cppClassName = "::mlir::VectorType";
  string description = "";
  string builderCall = "";
}
class ScalableVectorOfRankAndLengthAndType<list<int> ScalableVectorOfRankAndLengthAndType:allowedRanks = ?, list<int> ScalableVectorOfRankAndLengthAndType:allowedLengths = ?, list<Type> ScalableVectorOfRankAndLengthAndType:allowedTypes = ?> {	// Constraint TypeConstraint Type AllOfType
  Pred predicate = And<0: [ScalableVectorOfRank<0: ScalableVectorOfRankAndLengthAndType:allowedRanks>.predicate, ScalableVectorOf<0: ScalableVectorOfRankAndLengthAndType:allowedTypes>.predicate, ScalableVectorOfLength<0: ScalableVectorOfRankAndLengthAndType:allowedLengths>.predicate]>;
  string summary = !if(!eq(!strconcat(ScalableVectorOfRank<0: ScalableVectorOfRankAndLengthAndType:allowedRanks>.summary, !strconcat(ScalableVectorOf<0: ScalableVectorOfRankAndLengthAndType:allowedTypes>.summary, ScalableVectorOfLength<0: ScalableVectorOfRankAndLengthAndType:allowedLengths>.summary)), ""), !interleave([ScalableVectorOfRank<0: ScalableVectorOfRankAndLengthAndType:allowedRanks>.summary, ScalableVectorOf<0: ScalableVectorOfRankAndLengthAndType:allowedTypes>.summary, ScalableVectorOfLength<0: ScalableVectorOfRankAndLengthAndType:allowedLengths>.summary], " and "), !strconcat(ScalableVectorOfRank<0: ScalableVectorOfRankAndLengthAndType:allowedRanks>.summary, !strconcat(ScalableVectorOf<0: ScalableVectorOfRankAndLengthAndType:allowedTypes>.summary, ScalableVectorOfLength<0: ScalableVectorOfRankAndLengthAndType:allowedLengths>.summary)));
  string cppClassName = "::mlir::VectorType";
  string description = "";
  string builderCall = "";
  list<Type> allowedTypes = [ScalableVectorOfRank<0: ScalableVectorOfRankAndLengthAndType:allowedRanks>, ScalableVectorOf<0: ScalableVectorOfRankAndLengthAndType:allowedTypes>, ScalableVectorOfLength<0: ScalableVectorOfRankAndLengthAndType:allowedLengths>];
}
class SelfAllocationParameter<string SelfAllocationParameter:type = ?, string SelfAllocationParameter:desc = ?> {	// AttrOrTypeParameter
  code allocator = [{$_dst = $_self.allocateInto($_allocator);}];
  string comparator = ?;
  string cppType = SelfAllocationParameter:type;
  string cppAccessorType = SelfAllocationParameter:type;
  string cppStorageType = cppType;
  string convertFromStorage = "$_self";
  string summary = SelfAllocationParameter:desc;
  string syntax = ?;
  string parser = ?;
  string printer = ?;
  string defaultValue = "";
}
class Shape<string Shape:name = ?> {	// StrFunc
  string result = !strconcat("::llvm::cast<::mlir::ShapedType>($", !strconcat(Shape:name, ".getType()).getShape()"));
}
class ShapedContainerType<list<Type> ShapedContainerType:allowedTypes = ?, Pred ShapedContainerType:containerPred = ?, string ShapedContainerType:descr = ?, string ShapedContainerType:cppClassName = "::mlir::Type"> {	// Constraint TypeConstraint Type
  Pred predicate = And<0: [ShapedContainerType:containerPred, Concat<0: "[](::mlir::Type elementType) { return ", 1: SubstLeaves<0: "$_self", 1: "elementType", 2: AnyTypeOf<0: ShapedContainerType:allowedTypes>.predicate>, 2: "; }(::llvm::cast<::mlir::ShapedType>($_self).getElementType())">]>;
  string summary = !strconcat(ShapedContainerType:descr, !strconcat(" of ", !strconcat(AnyTypeOf<0: ShapedContainerType:allowedTypes>.summary, " values")));
  string cppClassName = ShapedContainerType:cppClassName;
  string description = "";
  string builderCall = "";
}
class ShapedTypeWithNthDimOfSize<int ShapedTypeWithNthDimOfSize:n = ?, list<int> ShapedTypeWithNthDimOfSize:allowedSizes = ?> {	// Constraint TypeConstraint Type
  Pred predicate = IsNthDimSizeIsOneOfPred<0: ShapedTypeWithNthDimOfSize:n, 1: ShapedTypeWithNthDimOfSize:allowedSizes>;
  string summary = !strconcat(" with dim ", !strconcat(!cast<string>(ShapedTypeWithNthDimOfSize:n), !strconcat(" having a size of {", !strconcat(!interleave(ShapedTypeWithNthDimOfSize:allowedSizes, ", "), "}"))));
  string cppClassName = "::mlir::ShapedType";
  string description = "";
  string builderCall = "";
}
class SideEffect<EffectOpInterfaceBase SideEffect:interface = ?, string SideEffect:effectName = ?, Resource SideEffect:resourceReference = ?, int SideEffect:effectStage = ?, EffectRange SideEffect:range = ?> {	// OpVariableDecorator
  string baseEffectName = SideEffect:interface.baseEffectName;
  string interfaceTrait = SideEffect:interface.trait;
  string cppNamespace = SideEffect:interface.cppNamespace;
  string effect = SideEffect:effectName;
  string resource = SideEffect:resourceReference.name;
  int stage = SideEffect:effectStage;
  bit effectOnFullRegion = !cast<bit>(SideEffect:range.Value);
}
class SideEffectsTraitBase<EffectOpInterfaceBase SideEffectsTraitBase:parentInterface = ?, list<SideEffect> SideEffectsTraitBase:staticEffects = ?> {	// Trait NativeTrait InterfaceTrait OpInterfaceTrait
  string trait = SideEffectsTraitBase:parentInterface.trait;
  string cppNamespace = SideEffectsTraitBase:parentInterface.cppNamespace;
  code extraConcreteClassDeclaration = [{}];
  code extraConcreteClassDefinition = [{}];
  string extraTraitClassDeclaration = "";
  code verify = [{}];
  bit verifyWithRegions = 0;
  list<Trait> dependentTraits = [];
  string baseEffectName = SideEffectsTraitBase:parentInterface.baseEffectName;
  list<SideEffect> effects = SideEffectsTraitBase:staticEffects;
}
class SignedIntOfWidths<list<int> SignedIntOfWidths:widths = ?> {	// Constraint TypeConstraint Type AnyTypeOf
  Pred predicate = Or<0: !foreach(allowedtype, !foreach(w, SignedIntOfWidths:widths, SI<0: w>), allowedtype.predicate)>;
  string summary = !if(!eq(!strconcat(!interleave(SignedIntOfWidths:widths, "/"), "-bit signed integer"), ""), !interleave(!foreach(t, !foreach(w, SignedIntOfWidths:widths, SI<0: w>), t.summary), " or "), !strconcat(!interleave(SignedIntOfWidths:widths, "/"), "-bit signed integer"));
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
  list<Type> allowedTypes = !foreach(w, SignedIntOfWidths:widths, SI<0: w>);
}
class SignedIntegerAttrBase<SI SignedIntegerAttrBase:attrValType = ?, string SignedIntegerAttrBase:descr = ?> {	// Constraint AttrConstraint Attr TypedAttrBase
  Pred predicate = And<0: [anonymous_191, CPred<0: !strconcat("::llvm::cast<::mlir::IntegerAttr>($_self).getType().isSignedInteger(", !strconcat(!cast<string>(SignedIntegerAttrBase:attrValType.bitwidth), ")"))>]>;
  string summary = SignedIntegerAttrBase:descr;
  string storageType = "::mlir::IntegerAttr";
  code returnType = [{ ::llvm::APInt }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = !strconcat("$_builder.get", !strconcat("IntegerAttr", !strconcat("(", !strconcat(SignedIntegerAttrBase:attrValType.builderCall, ", $0)"))));
  string defaultValue = ?;
  Type valueType = SignedIntegerAttrBase:attrValType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class SignlessIntElementsAttr<int SignlessIntElementsAttr:width = ?> {	// Constraint AttrConstraint Attr ElementsAttrBase IntElementsAttrBase
  Pred predicate = And<0: [anonymous_247, CPred<0: !strconcat("::llvm::cast<::mlir::DenseIntElementsAttr>($_self).getType().getElementType().isSignlessInteger(", !strconcat(!cast<string>(SignlessIntElementsAttr:width), ")"))>]>;
  string summary = !strconcat(!cast<string>(SignlessIntElementsAttr:width), "-bit signless integer elements attribute");
  code storageType = [{ ::mlir::DenseIntElementsAttr }];
  code returnType = [{ ::mlir::DenseIntElementsAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = !strconcat("::llvm::cast<::mlir::DenseIntElementsAttr>(::mlir::DenseElementsAttr::get(::mlir::RankedTensorType::get({}, $_builder.getIntegerType(", !strconcat(!cast<string>(SignlessIntElementsAttr:width), ")), ::llvm::ArrayRef($0)))"));
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class SignlessIntOfWidths<list<int> SignlessIntOfWidths:widths = ?> {	// Constraint TypeConstraint Type AnyTypeOf
  Pred predicate = Or<0: !foreach(allowedtype, !foreach(w, SignlessIntOfWidths:widths, I<0: w>), allowedtype.predicate)>;
  string summary = !if(!eq(!strconcat(!interleave(SignlessIntOfWidths:widths, "/"), "-bit signless integer"), ""), !interleave(!foreach(t, !foreach(w, SignlessIntOfWidths:widths, I<0: w>), t.summary), " or "), !strconcat(!interleave(SignlessIntOfWidths:widths, "/"), "-bit signless integer"));
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
  list<Type> allowedTypes = !foreach(w, SignlessIntOfWidths:widths, I<0: w>);
}
class SignlessIntegerAttrBase<I SignlessIntegerAttrBase:attrValType = ?, string SignlessIntegerAttrBase:descr = ?> {	// Constraint AttrConstraint Attr TypedAttrBase
  Pred predicate = And<0: [anonymous_191, CPred<0: !strconcat("::llvm::cast<::mlir::IntegerAttr>($_self).getType().isSignlessInteger(", !strconcat(!cast<string>(SignlessIntegerAttrBase:attrValType.bitwidth), ")"))>]>;
  string summary = SignlessIntegerAttrBase:descr;
  string storageType = "::mlir::IntegerAttr";
  code returnType = [{ ::llvm::APInt }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = !strconcat("$_builder.get", !strconcat("IntegerAttr", !strconcat("(", !strconcat(SignlessIntegerAttrBase:attrValType.builderCall, ", $0)"))));
  string defaultValue = ?;
  Type valueType = SignlessIntegerAttrBase:attrValType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class SingleBlockImplicitTerminator<string SingleBlockImplicitTerminator:op = ?> {	// Trait TraitList
  list<Trait> traits = [SingleBlock, SingleBlockImplicitTerminatorImpl<0: SingleBlockImplicitTerminator:op>];
}
class SingleBlockImplicitTerminatorImpl<string SingleBlockImplicitTerminatorImpl:op = ?> {	// Trait NativeTrait ParamNativeTrait ParamNativeOpTrait StructuralOpTrait
  string trait = !strconcat("SingleBlockImplicitTerminator", !strconcat("<", !strconcat(SingleBlockImplicitTerminatorImpl:op, ">::Impl")));
  string cppNamespace = "::mlir::OpTrait";
  code extraConcreteClassDeclaration = [{}];
  code extraConcreteClassDefinition = [{}];
  list<Trait> dependentTraits = [SingleBlock];
}
class SizedRegion<int SizedRegion:numBlocks = ?> {	// Constraint RegionConstraint Region
  Pred predicate = CPred<0: !strconcat("::llvm::hasNItems($_self, ", !strconcat(!cast<string>(SizedRegion:numBlocks), ")"))>;
  string summary = !strconcat("region with ", !strconcat(!cast<string>(SizedRegion:numBlocks), " blocks"));
}
class StaticInterfaceMethod<string StaticInterfaceMethod:desc = ?, string StaticInterfaceMethod:retTy = ?, string StaticInterfaceMethod:methodName = ?, dag StaticInterfaceMethod:args = (ins), code StaticInterfaceMethod:methodBody = [{}], code StaticInterfaceMethod:defaultImplementation = [{}]> {	// InterfaceMethod
  string description = StaticInterfaceMethod:desc;
  string name = StaticInterfaceMethod:methodName;
  string returnType = StaticInterfaceMethod:retTy;
  dag arguments = StaticInterfaceMethod:args;
  string body = StaticInterfaceMethod:methodBody;
  string defaultBody = StaticInterfaceMethod:defaultImplementation;
}
class StaticShapeMemRefOf<list<Type> StaticShapeMemRefOf:allowedTypes = ?> {	// Constraint TypeConstraint Type ConfinedType
  Pred predicate = And<0: [MemRefOf<0: StaticShapeMemRefOf:allowedTypes>.predicate, HasStaticShapePred]>;
  string summary = !strconcat("statically shaped ", MemRefOf<0: StaticShapeMemRefOf:allowedTypes>.summary);
  string cppClassName = "::mlir::MemRefType";
  string description = "";
  string builderCall = "";
}
class StaticShapeTensorOf<list<Type> StaticShapeTensorOf:allowedTypes = ?> {	// Constraint TypeConstraint Type ShapedContainerType RankedTensorOf
  Pred predicate = And<0: [anonymous_139, Concat<0: "[](::mlir::Type elementType) { return ", 1: SubstLeaves<0: "$_self", 1: "elementType", 2: AnyTypeOf<0: StaticShapeTensorOf:allowedTypes>.predicate>, 2: "; }(::llvm::cast<::mlir::ShapedType>($_self).getElementType())">]>;
  string summary = !strconcat("statically shaped tensor", !strconcat(" of ", !strconcat(AnyTypeOf<0: StaticShapeTensorOf:allowedTypes>.summary, " values")));
  string cppClassName = "::mlir::RankedTensorType";
  string description = "";
  string builderCall = "";
}
class StrFunc<string StrFunc:r = ?> {
  string result = StrFunc:r;
}
class StridedMemRefOf<list<Type> StridedMemRefOf:allowedTypes = ?> {	// Constraint TypeConstraint Type ConfinedType
  Pred predicate = And<0: [MemRefOf<0: StridedMemRefOf:allowedTypes>.predicate, HasStridesPred]>;
  string summary = !strconcat("strided ", MemRefOf<0: StridedMemRefOf:allowedTypes>.summary);
  string cppClassName = MemRefOf<0: StridedMemRefOf:allowedTypes>.cppClassName;
  string description = "";
  string builderCall = "";
}
class StridedMemRefRankOf<list<Type> StridedMemRefRankOf:allowedTypes = ?, list<int> StridedMemRefRankOf:ranks = ?> {	// Constraint TypeConstraint Type ConfinedType
  Pred predicate = And<0: [MemRefOf<0: StridedMemRefRankOf:allowedTypes>.predicate, HasAnyRankOfPred<0: StridedMemRefRankOf:ranks>]>;
  string summary = !strconcat(!interleave(!foreach(rank, StridedMemRefRankOf:ranks, !strconcat(!cast<string>(rank), "D")), "/"), !strconcat(" ", MemRefOf<0: StridedMemRefRankOf:allowedTypes>.summary));
  string cppClassName = MemRefOf<0: StridedMemRefRankOf:allowedTypes>.cppClassName;
  string description = "";
  string builderCall = "";
}
class StringBasedAttr<Pred StringBasedAttr:condition = ?, string StringBasedAttr:descr = ?> {	// Constraint AttrConstraint Attr
  Pred predicate = StringBasedAttr:condition;
  string summary = StringBasedAttr:descr;
  code storageType = [{ ::mlir::StringAttr }];
  code returnType = [{ ::llvm::StringRef }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = "$_builder.getStringAttr($0)";
  string defaultValue = ?;
  Type valueType = NoneType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class StringRefParameter<string StringRefParameter:desc = "", string StringRefParameter:value = ""> {	// AttrOrTypeParameter
  code allocator = [{$_dst = $_allocator.copyInto($_self);}];
  string comparator = ?;
  string cppType = "::llvm::StringRef";
  string cppAccessorType = "::llvm::StringRef";
  string cppStorageType = "std::string";
  string convertFromStorage = "$_self";
  string summary = StringRefParameter:desc;
  string syntax = ?;
  string parser = ?;
  code printer = [{$_printer.printString($_self);}];
  string defaultValue = StringRefParameter:value;
}
class StructuralOpTrait {
}
class SubstLeaves<string SubstLeaves:pat = ?, string SubstLeaves:repl = ?, Pred SubstLeaves:child = ?> {	// Pred CombinedPred
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [SubstLeaves:child];
  string pattern = SubstLeaves:pat;
  string replacement = SubstLeaves:repl;
}
class Successor<Pred Successor:condition = ?, string Successor:descr = ""> {	// Constraint SuccessorConstraint
  Pred predicate = Successor:condition;
  string summary = Successor:descr;
}
class SuccessorConstraint<Pred SuccessorConstraint:predicate = ?, string SuccessorConstraint:summary = ""> {	// Constraint
  Pred predicate = SuccessorConstraint:predicate;
  string summary = SuccessorConstraint:summary;
}
class TCOpIsBroadcastableToRes<int TCOpIsBroadcastableToRes:opId = ?, int TCOpIsBroadcastableToRes:resId = ?> {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [TCOpResIsShapedTypePred<0: TCOpIsBroadcastableToRes:opId, 1: TCOpIsBroadcastableToRes:resId>, CPred<0: !strconcat("::mlir::OpTrait::util::getBroadcastedType($_op.getOperand(", !strconcat(!cast<string>(TCOpIsBroadcastableToRes:opId), !strconcat(").getType(), $_op.getResult(", !strconcat(!cast<string>(TCOpIsBroadcastableToRes:resId), ").getType())"))))>];
}
class TCOpResIsShapedTypePred<int TCOpResIsShapedTypePred:i = ?, int TCOpResIsShapedTypePred:j = ?> {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [CPred<0: !strconcat("$_op.getNumResults() > ", !cast<string>(TCOpResIsShapedTypePred:i))>, CPred<0: !strconcat("$_op.getNumOperands() > ", !cast<string>(TCOpResIsShapedTypePred:j))>, SubstLeaves<0: "$_self", 1: !strconcat("$_op.getResult(", !strconcat(!cast<string>(TCOpResIsShapedTypePred:i), ").getType()")), 2: IsShapedTypePred>, SubstLeaves<0: "$_self", 1: !strconcat("$_op.getOperand(", !strconcat(!cast<string>(TCOpResIsShapedTypePred:j), ").getType()")), 2: IsShapedTypePred>];
}
class TCopVTEtAreSameAt<list<int> TCopVTEtAreSameAt:indices = ?> {	// Pred CPred
  string predExpr = !strconcat("(", !strconcat(!strconcat("::llvm::all_equal(::llvm::map_range(::mlir::ArrayRef<unsigned>({", !strconcat(!interleave(TCopVTEtAreSameAt:indices, ", "), "}), [this](unsigned i) { return getElementTypeOrSelf(this->getOperand(i)); }))")), ")"));
}
class TCopVTEtIs<int TCopVTEtIs:idx = ?, Type TCopVTEtIs:type = ?> {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [CPred<0: !strconcat("$_op.getNumOperands() > ", !cast<string>(TCopVTEtIs:idx))>, SubstLeaves<0: "$_self", 1: !strconcat("$_op.getOperand(", !strconcat(!cast<string>(TCopVTEtIs:idx), ").getType()")), 2: IsShapedTypePred>, SubstLeaves<0: "$_self", 1: !strconcat("getElementTypeOrSelf($_op.getOperand(", !strconcat(!cast<string>(TCopVTEtIs:idx), "))")), 2: TCopVTEtIs:type.predicate>];
}
class TCopVTEtIsSameAs<int TCopVTEtIsSameAs:i = ?, int TCopVTEtIsSameAs:j = ?> {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [CPred<0: !strconcat("$_op.getNumOperands() > ", !cast<string>(!if(!gt(TCopVTEtIsSameAs:i, TCopVTEtIsSameAs:j), TCopVTEtIsSameAs:i, TCopVTEtIsSameAs:j)))>, SubstLeaves<0: "$_self", 1: !strconcat("$_op.getOperand(", !strconcat(!cast<string>(TCopVTEtIsSameAs:i), ").getType()")), 2: IsShapedTypePred>, SubstLeaves<0: "$_self", 1: !strconcat("$_op.getOperand(", !strconcat(!cast<string>(TCopVTEtIsSameAs:j), ").getType()")), 2: IsShapedTypePred>, CPred<0: !strconcat("::mlir::getElementTypeOrSelf($_op.getOperand(", !strconcat(!cast<string>(TCopVTEtIsSameAs:i), !strconcat(")) == ::mlir::getElementTypeOrSelf($_op.getOperand(", !strconcat(!cast<string>(TCopVTEtIsSameAs:j), "))"))))>];
}
class TCresIsSameAsOpBase<int TCresIsSameAsOpBase:i = ?, int TCresIsSameAsOpBase:j = ?> {	// Pred CPred
  string predExpr = !strconcat("(", !strconcat(!strconcat("$_op.getResult(", !strconcat(!cast<string>(TCresIsSameAsOpBase:i), !strconcat(").getType() == $_op.getOperand(", !strconcat(!cast<string>(TCresIsSameAsOpBase:j), ").getType()")))), ")"));
}
class TCresVTEtIsSameAsOp<int TCresVTEtIsSameAsOp:i = ?, int TCresVTEtIsSameAsOp:j = ?> {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [TCOpResIsShapedTypePred<0: TCresVTEtIsSameAsOp:i, 1: TCresVTEtIsSameAsOp:j>, TCresVTEtIsSameAsOpBase<0: TCresVTEtIsSameAsOp:i, 1: TCresVTEtIsSameAsOp:j>];
}
class TCresVTEtIsSameAsOpBase<int TCresVTEtIsSameAsOpBase:i = ?, int TCresVTEtIsSameAsOpBase:j = ?> {	// Pred CPred
  string predExpr = !strconcat("(", !strconcat(!strconcat("getElementTypeOrSelf($_op.getResult(", !strconcat(!cast<string>(TCresVTEtIsSameAsOpBase:i), !strconcat(")) == getElementTypeOrSelf($_op.getOperand(", !strconcat(!cast<string>(TCresVTEtIsSameAsOpBase:j), "))")))), ")"));
}
class TensorOf<list<Type> TensorOf:allowedTypes = ?, list<Pred> TensorOf:preds = [], string TensorOf:summary = "tensor"> {	// Constraint TypeConstraint Type ShapedContainerType
  Pred predicate = And<0: [And<0: !listconcat([IsTensorTypePred], TensorOf:preds)>, Concat<0: "[](::mlir::Type elementType) { return ", 1: SubstLeaves<0: "$_self", 1: "elementType", 2: AnyTypeOf<0: TensorOf:allowedTypes>.predicate>, 2: "; }(::llvm::cast<::mlir::ShapedType>($_self).getElementType())">]>;
  string summary = !strconcat(TensorOf:summary, !strconcat(" of ", !strconcat(AnyTypeOf<0: TensorOf:allowedTypes>.summary, " values")));
  string cppClassName = "::mlir::TensorType";
  string description = "";
  string builderCall = "";
}
class TensorRankOf<list<Type> TensorRankOf:allowedTypes = ?, list<int> TensorRankOf:ranks = ?> {	// Constraint TypeConstraint Type ShapedContainerType RankedTensorOf
  Pred predicate = And<0: [And<0: [IsRankedTensorTypePred, HasAnyRankOfPred<0: TensorRankOf:ranks>]>, Concat<0: "[](::mlir::Type elementType) { return ", 1: SubstLeaves<0: "$_self", 1: "elementType", 2: AnyTypeOf<0: TensorRankOf:allowedTypes>.predicate>, 2: "; }(::llvm::cast<::mlir::ShapedType>($_self).getElementType())">]>;
  string summary = !strconcat(!strconcat(!interleave(!foreach(rank, TensorRankOf:ranks, !strconcat(!cast<string>(rank), "D")), "/"), " tensor"), !strconcat(" of ", !strconcat(AnyTypeOf<0: TensorRankOf:allowedTypes>.summary, " values")));
  string cppClassName = "::mlir::RankedTensorType";
  string description = "";
  string builderCall = "";
}
class Trait {
}
class TraitList<list<Trait> TraitList:props = ?> {	// Trait
  list<Trait> traits = TraitList:props;
}
class TupleOf<list<Type> TupleOf:allowedTypes = ?> {	// Constraint TypeConstraint Type MixedContainerType
  Pred predicate = And<0: [IsTupleTypePred, Concat<0: "::llvm::all_of(::llvm::cast<::mlir::TupleType>($_self).getTypes(), [](::mlir::Type t) { return t && (", 1: SubstLeaves<0: "$_self", 1: "t", 2: AnyTypeOf<0: TupleOf:allowedTypes>.predicate>, 2: "); })">]>;
  string summary = !strconcat("tuple", !strconcat(" with any combination of ", !strconcat(AnyTypeOf<0: TupleOf:allowedTypes>.summary, " values")));
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
  Type elementType = AnyTypeOf<0: TupleOf:allowedTypes>;
  string getElementTypesCall = "::llvm::cast<::mlir::TupleType>($_self).getTypes()";
}
class Type<Pred Type:condition = ?, string Type:descr = "", string Type:cppClassName = "::mlir::Type"> {	// Constraint TypeConstraint
  Pred predicate = Type:condition;
  string summary = Type:descr;
  string cppClassName = Type:cppClassName;
  string description = "";
  string builderCall = "";
}
class TypeAlias<Type TypeAlias:t = ?, string TypeAlias:summary = TypeAlias:t.summary> {	// Constraint TypeConstraint Type
  Pred predicate = TypeAlias:t.predicate;
  string summary = TypeAlias:summary;
  string cppClassName = TypeAlias:t.cppClassName;
  string description = TypeAlias:t.description;
  string builderCall = TypeAlias:t.builderCall;
}
class TypeAttrBase<string TypeAttrBase:retType = ?, string TypeAttrBase:summary = ?, Pred TypeAttrBase:typePred = anonymous_5> {	// Constraint AttrConstraint Attr
  Pred predicate = And<0: [anonymous_240, CPred<0: !strconcat("::llvm::isa<", !strconcat(TypeAttrBase:retType, ">(::llvm::cast<::mlir::TypeAttr>($_self).getValue())"))>, SubstLeaves<0: "$_self", 1: "::llvm::cast<::mlir::TypeAttr>($_self).getValue()", 2: TypeAttrBase:typePred>]>;
  string summary = TypeAttrBase:summary;
  code storageType = [{ ::mlir::TypeAttr }];
  string returnType = TypeAttrBase:retType;
  string convertFromStorage = !strconcat("::llvm::cast<", !strconcat(TypeAttrBase:retType, ">($_self.getValue())"));
  string constBuilderCall = ?;
  string defaultValue = ?;
  Type valueType = NoneType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class TypeAttrOf<Type TypeAttrOf:ty = ?> {	// Constraint AttrConstraint Attr TypeAttrBase
  Pred predicate = And<0: [anonymous_240, CPred<0: !strconcat("::llvm::isa<", !strconcat(TypeAttrOf:ty.cppClassName, ">(::llvm::cast<::mlir::TypeAttr>($_self).getValue())"))>, SubstLeaves<0: "$_self", 1: "::llvm::cast<::mlir::TypeAttr>($_self).getValue()", 2: TypeAttrOf:ty.predicate>]>;
  string summary = !strconcat("type attribute of ", TypeAttrOf:ty.summary);
  code storageType = [{ ::mlir::TypeAttr }];
  string returnType = TypeAttrOf:ty.cppClassName;
  string convertFromStorage = !strconcat("::llvm::cast<", !strconcat(TypeAttrOf:ty.cppClassName, ">($_self.getValue())"));
  string constBuilderCall = "::mlir::TypeAttr::get($0)";
  string defaultValue = ?;
  Type valueType = NoneType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class TypeBuilder<dag TypeBuilder:parameters = ?, string TypeBuilder:bodyCode = "", string TypeBuilder:returnType = ""> {	// AttrOrTypeBuilder
  dag dagParams = TypeBuilder:parameters;
  string body = TypeBuilder:bodyCode;
  string returnType = TypeBuilder:returnType;
  bit hasInferredContextParam = 0;
}
class TypeBuilderWithInferredContext<dag TypeBuilderWithInferredContext:parameters = ?, string TypeBuilderWithInferredContext:bodyCode = "", string TypeBuilderWithInferredContext:returnType = ""> {	// AttrOrTypeBuilder TypeBuilder AttrOrTypeBuilderWithInferredContext
  dag dagParams = TypeBuilderWithInferredContext:parameters;
  string body = TypeBuilderWithInferredContext:bodyCode;
  string returnType = TypeBuilderWithInferredContext:returnType;
  bit hasInferredContextParam = 1;
}
class TypeConstraint<Pred TypeConstraint:predicate = ?, string TypeConstraint:summary = "", string TypeConstraint:cppClassNameParam = "::mlir::Type"> {	// Constraint
  Pred predicate = TypeConstraint:predicate;
  string summary = TypeConstraint:summary;
  string cppClassName = TypeConstraint:cppClassNameParam;
}
class TypeDef<Dialect TypeDef:dialect = ?, string TypeDef:name = ?, list<Trait> TypeDef:traits = [], string TypeDef:baseCppClass = "::mlir::Type"> {	// Constraint TypeConstraint Type DialectType AttrOrTypeDef
  Pred predicate = CPred<0: !strconcat("::llvm::isa<", !strconcat(dialect.cppNamespace, !strconcat("::", !strconcat(cppClassName, ">($_self)"))))>;
  string summary = "";
  string cppClassName = !strconcat(TypeDef:name, "Type");
  string description = "";
  string builderCall = !if(!empty(parameters), !strconcat("$_builder.getType<", !strconcat(dialect.cppNamespace, !strconcat("::", !strconcat(cppClassName, ">()")))), "");
  Dialect dialect = TypeDef:dialect;
  string cppBaseClassName = TypeDef:baseCppClass;
  string storageClass = !strconcat(TypeDef:name, "TypeStorage");
  string storageNamespace = "detail";
  bit genStorageClass = 1;
  bit hasStorageCustomConstructor = 0;
  dag parameters = (ins);
  list<AttrOrTypeBuilder> builders = ?;
  list<Trait> traits = TypeDef:traits;
  string mnemonic = ?;
  string assemblyFormat = ?;
  bit hasCustomAssemblyFormat = 0;
  bit genAccessors = 1;
  bit skipDefaultBuilders = 0;
  bit genVerifyDecl = 0;
  code extraClassDeclaration = [{}];
  code extraClassDefinition = [{}];
  string cppType = !strconcat(dialect.cppNamespace, !strconcat("::", cppClassName));
  string typeName = !strconcat(dialect.name, !strconcat(".", mnemonic));
}
class TypeInterface<string TypeInterface:name = ?, list<Interface> TypeInterface:baseInterfaces = []> {	// Interface Trait NativeTrait InterfaceTrait Constraint TypeConstraint Type
  string description = "";
  string cppInterfaceName = TypeInterface:name;
  string cppNamespace = "";
  list<InterfaceMethod> methods = [];
  string extraClassDeclaration = "";
  string extraSharedClassDeclaration = "";
  string extraClassOf = "";
  list<Interface> baseInterfaces = TypeInterface:baseInterfaces;
  string trait = !strconcat(TypeInterface:name, "::Trait");
  code extraConcreteClassDeclaration = [{}];
  code extraConcreteClassDefinition = [{}];
  string extraTraitClassDeclaration = "";
  Pred predicate = CPred<0: !strconcat("::llvm::isa<", !strconcat(!if(!empty(cppNamespace), "", !strconcat(cppNamespace, "::")), !strconcat(TypeInterface:name, ">($_self)")))>;
  string summary = !strconcat(TypeInterface:name, " instance");
  string cppClassName = !strconcat(!if(!empty(cppNamespace), "", !strconcat(cppNamespace, "::")), TypeInterface:name);
  string builderCall = "";
}
class TypeIs<string TypeIs:name = ?, Type TypeIs:type = ?> {	// Trait PredTrait PredOpTrait
  string summary = !strconcat("'", !strconcat(TypeIs:name, !strconcat("' is ", TypeIs:type.summary)));
  Pred predicate = TypeIsPred<0: TypeIs:name, 1: TypeIs:type>;
  list<Trait> dependentTraits = [];
}
class TypeIsPred<string TypeIsPred:name = ?, Type TypeIsPred:type = ?> {	// Pred CombinedPred SubstLeaves
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [TypeIsPred:type.predicate];
  string pattern = "$_self";
  string replacement = !strconcat("$", !strconcat(TypeIsPred:name, ".getType()"));
}
class TypeOrContainer<Type TypeOrContainer:allowedType = ?, string TypeOrContainer:name = ?> {	// Constraint TypeConstraint
  Pred predicate = Or<0: [TypeOrContainer:allowedType.predicate, VectorOf<0: [TypeOrContainer:allowedType]>.predicate, TensorOf<0: [TypeOrContainer:allowedType]>.predicate]>;
  string summary = TypeOrContainer:name;
  string cppClassName = "::mlir::Type";
}
class TypeOrContainerOfAnyRank<Type TypeOrContainerOfAnyRank:allowedType = ?, string TypeOrContainerOfAnyRank:name = ?> {	// Constraint TypeConstraint
  Pred predicate = Or<0: [TypeOrContainerOfAnyRank:allowedType.predicate, VectorOfAnyRankOf<0: [TypeOrContainerOfAnyRank:allowedType]>.predicate, TensorOf<0: [TypeOrContainerOfAnyRank:allowedType]>.predicate]>;
  string summary = TypeOrContainerOfAnyRank:name;
  string cppClassName = "::mlir::Type";
}
class TypeParameter<string TypeParameter:type = ?, string TypeParameter:desc = ?, string TypeParameter:accessorType = ""> {	// AttrOrTypeParameter
  string allocator = ?;
  string comparator = ?;
  string cppType = TypeParameter:type;
  string cppAccessorType = !if(!empty(TypeParameter:accessorType), TypeParameter:type, TypeParameter:accessorType);
  string cppStorageType = cppType;
  string convertFromStorage = "$_self";
  string summary = TypeParameter:desc;
  string syntax = ?;
  string parser = ?;
  string printer = ?;
  string defaultValue = "";
}
class TypedArrayAttrBase<Attr TypedArrayAttrBase:element = ?, string TypedArrayAttrBase:summary = ?> {	// Constraint AttrConstraint Attr ArrayAttrBase
  Pred predicate = And<0: [anonymous_271, Concat<0: "::llvm::all_of(::llvm::cast<::mlir::ArrayAttr>($_self), [&](::mlir::Attribute attr) { return attr && (", 1: SubstLeaves<0: "$_self", 1: "attr", 2: TypedArrayAttrBase:element.predicate>, 2: "); })">]>;
  string summary = TypedArrayAttrBase:summary;
  code storageType = [{ ::mlir::ArrayAttr }];
  code returnType = [{ ::mlir::ArrayAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = "$_builder.getArrayAttr($0)";
  string defaultValue = ?;
  Type valueType = NoneType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
  Attr elementAttr = TypedArrayAttrBase:element;
}
class TypedAttrBase<Type TypedAttrBase:attrValType = ?, string TypedAttrBase:attrKind = ?, Pred TypedAttrBase:condition = ?, string TypedAttrBase:descr = ?> {	// Constraint AttrConstraint Attr
  Pred predicate = TypedAttrBase:condition;
  string summary = TypedAttrBase:descr;
  string storageType = !strconcat("::mlir::", TypedAttrBase:attrKind);
  string returnType = ?;
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = !strconcat("$_builder.get", !strconcat(TypedAttrBase:attrKind, !strconcat("(", !strconcat(TypedAttrBase:attrValType.builderCall, ", $0)"))));
  string defaultValue = ?;
  Type valueType = TypedAttrBase:attrValType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class TypedSignedIntegerAttrBase<SI TypedSignedIntegerAttrBase:attrValType = ?, string TypedSignedIntegerAttrBase:retType = ?, string TypedSignedIntegerAttrBase:descr = ?> {	// Constraint AttrConstraint Attr TypedAttrBase SignedIntegerAttrBase
  Pred predicate = And<0: [anonymous_191, CPred<0: !strconcat("::llvm::cast<::mlir::IntegerAttr>($_self).getType().isSignedInteger(", !strconcat(!cast<string>(TypedSignedIntegerAttrBase:attrValType.bitwidth), ")"))>]>;
  string summary = TypedSignedIntegerAttrBase:descr;
  string storageType = "::mlir::IntegerAttr";
  string returnType = TypedSignedIntegerAttrBase:retType;
  string convertFromStorage = "$_self.getValue().getSExtValue()";
  string constBuilderCall = !strconcat("$_builder.get", !strconcat("IntegerAttr", !strconcat("(", !strconcat(TypedSignedIntegerAttrBase:attrValType.builderCall, ", $0)"))));
  string defaultValue = ?;
  Type valueType = TypedSignedIntegerAttrBase:attrValType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class TypedSignlessIntegerAttrBase<I TypedSignlessIntegerAttrBase:attrValType = ?, string TypedSignlessIntegerAttrBase:retType = ?, string TypedSignlessIntegerAttrBase:descr = ?> {	// Constraint AttrConstraint Attr TypedAttrBase SignlessIntegerAttrBase
  Pred predicate = And<0: [anonymous_191, CPred<0: !strconcat("::llvm::cast<::mlir::IntegerAttr>($_self).getType().isSignlessInteger(", !strconcat(!cast<string>(TypedSignlessIntegerAttrBase:attrValType.bitwidth), ")"))>]>;
  string summary = TypedSignlessIntegerAttrBase:descr;
  string storageType = "::mlir::IntegerAttr";
  string returnType = TypedSignlessIntegerAttrBase:retType;
  string convertFromStorage = "$_self.getValue().getZExtValue()";
  string constBuilderCall = !strconcat("$_builder.get", !strconcat("IntegerAttr", !strconcat("(", !strconcat(TypedSignlessIntegerAttrBase:attrValType.builderCall, ", $0)"))));
  string defaultValue = ?;
  Type valueType = TypedSignlessIntegerAttrBase:attrValType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class TypedStrAttr<Type TypedStrAttr:ty = ?> {	// Constraint AttrConstraint Attr StringBasedAttr
  Pred predicate = anonymous_239;
  string summary = "string attribute";
  code storageType = [{ ::mlir::StringAttr }];
  code returnType = [{ ::llvm::StringRef }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = "$_builder.getStringAttr($0)";
  string defaultValue = ?;
  Type valueType = TypedStrAttr:ty;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class TypedUnsignedIntegerAttrBase<UI TypedUnsignedIntegerAttrBase:attrValType = ?, string TypedUnsignedIntegerAttrBase:retType = ?, string TypedUnsignedIntegerAttrBase:descr = ?> {	// Constraint AttrConstraint Attr TypedAttrBase UnsignedIntegerAttrBase
  Pred predicate = And<0: [anonymous_191, CPred<0: !strconcat("::llvm::cast<::mlir::IntegerAttr>($_self).getType().isUnsignedInteger(", !strconcat(!cast<string>(TypedUnsignedIntegerAttrBase:attrValType.bitwidth), ")"))>]>;
  string summary = TypedUnsignedIntegerAttrBase:descr;
  string storageType = "::mlir::IntegerAttr";
  string returnType = TypedUnsignedIntegerAttrBase:retType;
  string convertFromStorage = "$_self.getValue().getZExtValue()";
  string constBuilderCall = !strconcat("$_builder.get", !strconcat("IntegerAttr", !strconcat("(", !strconcat(TypedUnsignedIntegerAttrBase:attrValType.builderCall, ", $0)"))));
  string defaultValue = ?;
  Type valueType = TypedUnsignedIntegerAttrBase:attrValType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class TypesMatchWith<string TypesMatchWith:summary = ?, string TypesMatchWith:lhsArg = ?, string TypesMatchWith:rhsArg = ?, string TypesMatchWith:transform = ?, string TypesMatchWith:comparator = "std::equal_to<>()"> {	// Trait PredTrait PredOpTrait
  string summary = TypesMatchWith:summary;
  Pred predicate = CPred<0: !strconcat(TypesMatchWith:comparator, !strconcat("(", !strconcat(!subst("$_self", !strconcat("$", !strconcat(TypesMatchWith:lhsArg, ".getType()")), TypesMatchWith:transform), !strconcat(", $", !strconcat(TypesMatchWith:rhsArg, ".getType())")))))>;
  list<Trait> dependentTraits = [];
  string lhs = TypesMatchWith:lhsArg;
  string rhs = TypesMatchWith:rhsArg;
  string transformer = TypesMatchWith:transform;
}
class UI<int UI:width = ?> {	// Constraint TypeConstraint Type BuildableType
  Pred predicate = CPred<0: !strconcat("$_self.isUnsignedInteger(", !strconcat(!cast<string>(UI:width), ")"))>;
  string summary = !strconcat(!cast<string>(UI:width), "-bit unsigned integer");
  string cppClassName = "::mlir::IntegerType";
  string description = "";
  string builderCall = !strconcat("$_builder.getIntegerType(", !strconcat(!cast<string>(UI:width), ", /*isSigned=*/false)"));
  int bitwidth = UI:width;
}
class UnrankedMemRefOf<list<Type> UnrankedMemRefOf:allowedTypes = ?> {	// Constraint TypeConstraint Type ShapedContainerType
  Pred predicate = And<0: [IsUnrankedMemRefTypePred, Concat<0: "[](::mlir::Type elementType) { return ", 1: SubstLeaves<0: "$_self", 1: "elementType", 2: AnyTypeOf<0: UnrankedMemRefOf:allowedTypes>.predicate>, 2: "; }(::llvm::cast<::mlir::ShapedType>($_self).getElementType())">]>;
  string summary = !strconcat("unranked.memref", !strconcat(" of ", !strconcat(AnyTypeOf<0: UnrankedMemRefOf:allowedTypes>.summary, " values")));
  string cppClassName = "::mlir::UnrankedMemRefType";
  string description = "";
  string builderCall = "";
}
class UnrankedTensorOf<list<Type> UnrankedTensorOf:allowedTypes = ?, list<Pred> UnrankedTensorOf:preds = [], string UnrankedTensorOf:summary = "unranked tensor"> {	// Constraint TypeConstraint Type ShapedContainerType
  Pred predicate = And<0: [And<0: !listconcat([IsUnrankedTensorTypePred], UnrankedTensorOf:preds)>, Concat<0: "[](::mlir::Type elementType) { return ", 1: SubstLeaves<0: "$_self", 1: "elementType", 2: AnyTypeOf<0: UnrankedTensorOf:allowedTypes>.predicate>, 2: "; }(::llvm::cast<::mlir::ShapedType>($_self).getElementType())">]>;
  string summary = !strconcat(UnrankedTensorOf:summary, !strconcat(" of ", !strconcat(AnyTypeOf<0: UnrankedTensorOf:allowedTypes>.summary, " values")));
  string cppClassName = "::mlir::UnrankedTensorType";
  string description = "";
  string builderCall = "";
}
class UnsignedIntOfWidths<list<int> UnsignedIntOfWidths:widths = ?> {	// Constraint TypeConstraint Type AnyTypeOf
  Pred predicate = Or<0: !foreach(allowedtype, !foreach(w, UnsignedIntOfWidths:widths, UI<0: w>), allowedtype.predicate)>;
  string summary = !if(!eq(!strconcat(!interleave(UnsignedIntOfWidths:widths, "/"), "-bit unsigned integer"), ""), !interleave(!foreach(t, !foreach(w, UnsignedIntOfWidths:widths, UI<0: w>), t.summary), " or "), !strconcat(!interleave(UnsignedIntOfWidths:widths, "/"), "-bit unsigned integer"));
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
  list<Type> allowedTypes = !foreach(w, UnsignedIntOfWidths:widths, UI<0: w>);
}
class UnsignedIntegerAttrBase<UI UnsignedIntegerAttrBase:attrValType = ?, string UnsignedIntegerAttrBase:descr = ?> {	// Constraint AttrConstraint Attr TypedAttrBase
  Pred predicate = And<0: [anonymous_191, CPred<0: !strconcat("::llvm::cast<::mlir::IntegerAttr>($_self).getType().isUnsignedInteger(", !strconcat(!cast<string>(UnsignedIntegerAttrBase:attrValType.bitwidth), ")"))>]>;
  string summary = UnsignedIntegerAttrBase:descr;
  string storageType = "::mlir::IntegerAttr";
  code returnType = [{ ::llvm::APInt }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = !strconcat("$_builder.get", !strconcat("IntegerAttr", !strconcat("(", !strconcat(UnsignedIntegerAttrBase:attrValType.builderCall, ", $0)"))));
  string defaultValue = ?;
  Type valueType = UnsignedIntegerAttrBase:attrValType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class Variadic<Type Variadic:type = ?> {	// Constraint TypeConstraint
  Pred predicate = Variadic:type.predicate;
  string summary = !strconcat("variadic of ", Variadic:type.summary);
  string cppClassName = Variadic:type.cppClassName;
  Type baseType = Variadic:type;
  int minSize = 0;
}
class VariadicOfVariadic<Type VariadicOfVariadic:type = ?, string VariadicOfVariadic:variadicSegmentAttrName = ?> {	// Constraint TypeConstraint Variadic
  Pred predicate = VariadicOfVariadic:type.predicate;
  string summary = !strconcat("variadic of ", VariadicOfVariadic:type.summary);
  string cppClassName = VariadicOfVariadic:type.cppClassName;
  Type baseType = VariadicOfVariadic:type;
  int minSize = 0;
  string segmentAttrName = VariadicOfVariadic:variadicSegmentAttrName;
}
class VariadicRegion<Region VariadicRegion:region = ?> {	// Constraint RegionConstraint Region
  Pred predicate = VariadicRegion:region.predicate;
  string summary = VariadicRegion:region.summary;
}
class VariadicSuccessor<Successor VariadicSuccessor:successor = ?> {	// Constraint SuccessorConstraint Successor
  Pred predicate = VariadicSuccessor:successor.predicate;
  string summary = VariadicSuccessor:successor.summary;
}
class VectorOf<list<Type> VectorOf:allowedTypes = ?> {	// Constraint TypeConstraint Type ShapedContainerType
  Pred predicate = And<0: [IsVectorTypePred, Concat<0: "[](::mlir::Type elementType) { return ", 1: SubstLeaves<0: "$_self", 1: "elementType", 2: AnyTypeOf<0: VectorOf:allowedTypes>.predicate>, 2: "; }(::llvm::cast<::mlir::ShapedType>($_self).getElementType())">]>;
  string summary = !strconcat("vector", !strconcat(" of ", !strconcat(AnyTypeOf<0: VectorOf:allowedTypes>.summary, " values")));
  string cppClassName = "::mlir::VectorType";
  string description = "";
  string builderCall = "";
}
class VectorOfAnyRankOf<list<Type> VectorOfAnyRankOf:allowedTypes = ?> {	// Constraint TypeConstraint Type ShapedContainerType
  Pred predicate = And<0: [IsVectorOfAnyRankTypePred, Concat<0: "[](::mlir::Type elementType) { return ", 1: SubstLeaves<0: "$_self", 1: "elementType", 2: AnyTypeOf<0: VectorOfAnyRankOf:allowedTypes>.predicate>, 2: "; }(::llvm::cast<::mlir::ShapedType>($_self).getElementType())">]>;
  string summary = !strconcat("vector", !strconcat(" of ", !strconcat(AnyTypeOf<0: VectorOfAnyRankOf:allowedTypes>.summary, " values")));
  string cppClassName = "::mlir::VectorType";
  string description = "";
  string builderCall = "";
}
class VectorOfLength<list<int> VectorOfLength:allowedLengths = ?> {	// Constraint TypeConstraint Type
  Pred predicate = IsVectorOfLengthPred<0: VectorOfLength:allowedLengths>;
  string summary = !strconcat(" of length ", !interleave(VectorOfLength:allowedLengths, "/"));
  string cppClassName = "::mlir::VectorType";
  string description = "";
  string builderCall = "";
}
class VectorOfLengthAndType<list<int> VectorOfLengthAndType:allowedLengths = ?, list<Type> VectorOfLengthAndType:allowedTypes = ?> {	// Constraint TypeConstraint Type AllOfType
  Pred predicate = And<0: [VectorOf<0: VectorOfLengthAndType:allowedTypes>.predicate, VectorOfLength<0: VectorOfLengthAndType:allowedLengths>.predicate]>;
  string summary = !if(!eq(!strconcat(VectorOf<0: VectorOfLengthAndType:allowedTypes>.summary, VectorOfLength<0: VectorOfLengthAndType:allowedLengths>.summary), ""), !interleave([VectorOf<0: VectorOfLengthAndType:allowedTypes>.summary, VectorOfLength<0: VectorOfLengthAndType:allowedLengths>.summary], " and "), !strconcat(VectorOf<0: VectorOfLengthAndType:allowedTypes>.summary, VectorOfLength<0: VectorOfLengthAndType:allowedLengths>.summary));
  string cppClassName = "::mlir::VectorType";
  string description = "";
  string builderCall = "";
  list<Type> allowedTypes = [VectorOf<0: VectorOfLengthAndType:allowedTypes>, VectorOfLength<0: VectorOfLengthAndType:allowedLengths>];
}
class VectorOfRank<list<int> VectorOfRank:allowedRanks = ?> {	// Constraint TypeConstraint Type
  Pred predicate = IsVectorOfRankPred<0: VectorOfRank:allowedRanks>;
  string summary = !strconcat(" of ranks ", !interleave(VectorOfRank:allowedRanks, "/"));
  string cppClassName = "::mlir::VectorType";
  string description = "";
  string builderCall = "";
}
class VectorOfRankAndType<list<int> VectorOfRankAndType:allowedRanks = ?, list<Type> VectorOfRankAndType:allowedTypes = ?> {	// Constraint TypeConstraint Type AllOfType
  Pred predicate = And<0: [VectorOf<0: VectorOfRankAndType:allowedTypes>.predicate, VectorOfRank<0: VectorOfRankAndType:allowedRanks>.predicate]>;
  string summary = !if(!eq(!strconcat(VectorOf<0: VectorOfRankAndType:allowedTypes>.summary, VectorOfRank<0: VectorOfRankAndType:allowedRanks>.summary), ""), !interleave([VectorOf<0: VectorOfRankAndType:allowedTypes>.summary, VectorOfRank<0: VectorOfRankAndType:allowedRanks>.summary], " and "), !strconcat(VectorOf<0: VectorOfRankAndType:allowedTypes>.summary, VectorOfRank<0: VectorOfRankAndType:allowedRanks>.summary));
  string cppClassName = "::mlir::VectorType";
  string description = "";
  string builderCall = "";
  list<Type> allowedTypes = [VectorOf<0: VectorOfRankAndType:allowedTypes>, VectorOfRank<0: VectorOfRankAndType:allowedRanks>];
}
class VectorWithTrailingDimScalableOf<list<Type> VectorWithTrailingDimScalableOf:allowedTypes = ?> {	// Constraint TypeConstraint Type ShapedContainerType
  Pred predicate = And<0: [IsVectorTypeWithOnlyTrailingDimScalablePred, Concat<0: "[](::mlir::Type elementType) { return ", 1: SubstLeaves<0: "$_self", 1: "elementType", 2: AnyTypeOf<0: VectorWithTrailingDimScalableOf:allowedTypes>.predicate>, 2: "; }(::llvm::cast<::mlir::ShapedType>($_self).getElementType())">]>;
  string summary = !strconcat("trailing scalable vector", !strconcat(" of ", !strconcat(AnyTypeOf<0: VectorWithTrailingDimScalableOf:allowedTypes>.summary, " values")));
  string cppClassName = "::mlir::VectorType";
  string description = "";
  string builderCall = "";
}
class VectorWithTrailingDimScalableOfSizeAndType<list<int> VectorWithTrailingDimScalableOfSizeAndType:allowedTrailingSizes = ?, list<Type> VectorWithTrailingDimScalableOfSizeAndType:allowedTypes = ?> {	// Constraint TypeConstraint Type AllOfType
  Pred predicate = And<0: [VectorWithTrailingDimScalableOf<0: VectorWithTrailingDimScalableOfSizeAndType:allowedTypes>.predicate, ShapedTypeWithNthDimOfSize<0: -1, 1: VectorWithTrailingDimScalableOfSizeAndType:allowedTrailingSizes>.predicate]>;
  string summary = !if(!eq(!strconcat(VectorWithTrailingDimScalableOf<0: VectorWithTrailingDimScalableOfSizeAndType:allowedTypes>.summary, ShapedTypeWithNthDimOfSize<0: -1, 1: VectorWithTrailingDimScalableOfSizeAndType:allowedTrailingSizes>.summary), ""), !interleave([VectorWithTrailingDimScalableOf<0: VectorWithTrailingDimScalableOfSizeAndType:allowedTypes>.summary, ShapedTypeWithNthDimOfSize<0: -1, 1: VectorWithTrailingDimScalableOfSizeAndType:allowedTrailingSizes>.summary], " and "), !strconcat(VectorWithTrailingDimScalableOf<0: VectorWithTrailingDimScalableOfSizeAndType:allowedTypes>.summary, ShapedTypeWithNthDimOfSize<0: -1, 1: VectorWithTrailingDimScalableOfSizeAndType:allowedTrailingSizes>.summary));
  string cppClassName = "::mlir::VectorType";
  string description = "";
  string builderCall = "";
  list<Type> allowedTypes = [VectorWithTrailingDimScalableOf<0: VectorWithTrailingDimScalableOfSizeAndType:allowedTypes>, ShapedTypeWithNthDimOfSize<0: -1, 1: VectorWithTrailingDimScalableOfSizeAndType:allowedTrailingSizes>];
}
class _snakeCaseHelper<string _snakeCaseHelper:str = ?> {
  int idx = !find(_snakeCaseHelper:str, "_", 0);
  string ret = !if(!ge(idx, 0), !strconcat(!substr(_snakeCaseHelper:str, 0, idx), firstCharToUpper<0: !substr(_snakeCaseHelper:str, !add(idx, 1), 9223372036854775807)>.ret), _snakeCaseHelper:str);
}
class firstCharToUpper<string firstCharToUpper:str = ?> {
  string ret = !if(!gt(!size(firstCharToUpper:str), 0), !strconcat(!toupper(!substr(firstCharToUpper:str, 0, 1)), !substr(firstCharToUpper:str, 1, 9223372036854775807)), "");
}
class snakeCaseToCamelCase<string snakeCaseToCamelCase:str = ?> {
  string ret = !foldl(firstCharToUpper<0: snakeCaseToCamelCase:str>.ret, !range(0, !size(snakeCaseToCamelCase:str), 1), acc, idx, _snakeCaseHelper<0: acc>.ret);
}
------------- Defs -----------------
def APIntAttr {	// Constraint AttrConstraint Attr
  Pred predicate = anonymous_191;
  string summary = "arbitrary integer attribute";
  code storageType = [{ ::mlir::IntegerAttr }];
  code returnType = [{ ::mlir::APInt }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = ?;
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def AffineMapArrayAttr {	// Constraint AttrConstraint Attr ArrayAttrBase TypedArrayAttrBase
  Pred predicate = anonymous_277;
  string summary = "AffineMap array attribute";
  code storageType = [{ ::mlir::ArrayAttr }];
  code returnType = [{ ::mlir::ArrayAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = "$_builder.getAffineMapArrayAttr($0)";
  string defaultValue = ?;
  Type valueType = NoneType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
  Attr elementAttr = AffineMapAttr;
}
def AffineMapAttr {	// Constraint AttrConstraint Attr
  Pred predicate = anonymous_270;
  string summary = "AffineMap attribute";
  code storageType = [{::mlir::AffineMapAttr }];
  code returnType = [{ ::mlir::AffineMap }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = "::mlir::AffineMapAttr::get($0)";
  string defaultValue = ?;
  Type valueType = Index;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def AffineScope {	// Trait NativeTrait NativeOpTrait
  string trait = "AffineScope";
  string cppNamespace = "::mlir::OpTrait";
  code extraConcreteClassDeclaration = [{}];
  code extraConcreteClassDefinition = [{}];
  list<Trait> dependentTraits = [];
}
def AlwaysSpeculatable {	// Trait TraitList
  list<Trait> traits = [ConditionallySpeculatable, AlwaysSpeculatableImplTrait];
}
def AlwaysSpeculatableImplTrait {	// Trait NativeTrait NativeOpTrait
  string trait = "AlwaysSpeculatableImplTrait";
  string cppNamespace = "::mlir::OpTrait";
  code extraConcreteClassDeclaration = [{}];
  code extraConcreteClassDefinition = [{}];
  list<Trait> dependentTraits = [];
}
def AnyAttr {	// Constraint AttrConstraint Attr
  Pred predicate = anonymous_5;
  string summary = "any attribute";
  string storageType = "::mlir::Attribute";
  string returnType = "::mlir::Attribute";
  string convertFromStorage = "$_self";
  string constBuilderCall = "$0";
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def AnyComplex {	// Constraint TypeConstraint Type
  Pred predicate = anonymous_47;
  string summary = "complex-type";
  string cppClassName = "::mlir::ComplexType";
  string description = "";
  string builderCall = "";
}
def AnyFixedVector {	// Constraint TypeConstraint Type ShapedContainerType FixedVectorOf
  Pred predicate = anonymous_55;
  string summary = "fixed-length vector of any type values";
  string cppClassName = "::mlir::VectorType";
  string description = "";
  string builderCall = "";
}
def AnyFloat {	// Constraint TypeConstraint Type
  Pred predicate = anonymous_34;
  string summary = "floating-point";
  string cppClassName = "::mlir::FloatType";
  string description = "";
  string builderCall = "";
}
def AnyI1 {	// Constraint TypeConstraint Type AnyI
  Pred predicate = anonymous_8;
  string summary = "1-bit integer";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
  int bitwidth = 1;
}
def AnyI16 {	// Constraint TypeConstraint Type AnyI
  Pred predicate = anonymous_10;
  string summary = "16-bit integer";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
  int bitwidth = 16;
}
def AnyI16Attr {	// Constraint AttrConstraint Attr TypedAttrBase AnyIntegerAttrBase
  Pred predicate = anonymous_199;
  string summary = "16-bit integer attribute";
  string storageType = "::mlir::IntegerAttr";
  code returnType = [{ ::llvm::APInt }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = ?;
  string defaultValue = ?;
  Type valueType = AnyI16;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def AnyI1Attr {	// Constraint AttrConstraint Attr TypedAttrBase AnyIntegerAttrBase
  Pred predicate = anonymous_195;
  string summary = "1-bit integer attribute";
  string storageType = "::mlir::IntegerAttr";
  code returnType = [{ ::llvm::APInt }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = ?;
  string defaultValue = ?;
  Type valueType = AnyI1;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def AnyI32 {	// Constraint TypeConstraint Type AnyI
  Pred predicate = anonymous_11;
  string summary = "32-bit integer";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
  int bitwidth = 32;
}
def AnyI32Attr {	// Constraint AttrConstraint Attr TypedAttrBase AnyIntegerAttrBase
  Pred predicate = anonymous_201;
  string summary = "32-bit integer attribute";
  string storageType = "::mlir::IntegerAttr";
  code returnType = [{ ::llvm::APInt }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = ?;
  string defaultValue = ?;
  Type valueType = AnyI32;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def AnyI32ElementsAttr {	// Constraint AttrConstraint Attr ElementsAttrBase IntElementsAttrBase IntElementsAttrOf
  Pred predicate = anonymous_259;
  string summary = "32-bit integer elements attribute";
  code storageType = [{ ::mlir::DenseIntElementsAttr }];
  code returnType = [{ ::mlir::DenseIntElementsAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = ?;
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def AnyI64 {	// Constraint TypeConstraint Type AnyI
  Pred predicate = anonymous_12;
  string summary = "64-bit integer";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
  int bitwidth = 64;
}
def AnyI64Attr {	// Constraint AttrConstraint Attr TypedAttrBase AnyIntegerAttrBase
  Pred predicate = anonymous_203;
  string summary = "64-bit integer attribute";
  string storageType = "::mlir::IntegerAttr";
  code returnType = [{ ::llvm::APInt }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = ?;
  string defaultValue = ?;
  Type valueType = AnyI64;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def AnyI64ElementsAttr {	// Constraint AttrConstraint Attr ElementsAttrBase IntElementsAttrBase IntElementsAttrOf
  Pred predicate = anonymous_261;
  string summary = "64-bit integer elements attribute";
  code storageType = [{ ::mlir::DenseIntElementsAttr }];
  code returnType = [{ ::mlir::DenseIntElementsAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = ?;
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def AnyI8 {	// Constraint TypeConstraint Type AnyI
  Pred predicate = anonymous_9;
  string summary = "8-bit integer";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
  int bitwidth = 8;
}
def AnyI8Attr {	// Constraint AttrConstraint Attr TypedAttrBase AnyIntegerAttrBase
  Pred predicate = anonymous_197;
  string summary = "8-bit integer attribute";
  string storageType = "::mlir::IntegerAttr";
  code returnType = [{ ::llvm::APInt }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = ?;
  string defaultValue = ?;
  Type valueType = AnyI8;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def AnyIntElementsAttr {	// Constraint AttrConstraint Attr ElementsAttrBase IntElementsAttrBase
  Pred predicate = anonymous_257;
  string summary = "integer elements attribute";
  code storageType = [{ ::mlir::DenseIntElementsAttr }];
  code returnType = [{ ::mlir::DenseIntElementsAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = ?;
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def AnyInteger {	// Constraint TypeConstraint Type
  Pred predicate = anonymous_7;
  string summary = "integer";
  string cppClassName = "::mlir::IntegerType";
  string description = "";
  string builderCall = "";
}
def AnyMemRef {	// Constraint TypeConstraint Type ShapedContainerType MemRefOf
  Pred predicate = anonymous_142;
  string summary = "memref of any type values";
  string cppClassName = "::mlir::MemRefType";
  string description = "";
  string builderCall = "";
}
def AnyNon0RankedMemRef {	// Constraint TypeConstraint Type ConfinedType Non0RankedMemRefOf
  Pred predicate = anonymous_144;
  string summary = "non-0-ranked.memref of any type values";
  string cppClassName = "::mlir::MemRefType";
  string description = "";
  string builderCall = "";
}
def AnyNon0RankedOrUnrankedMemRef {	// Constraint TypeConstraint Type AnyTypeOf
  Pred predicate = anonymous_147;
  string summary = "unranked.memref of any type values or non-0-ranked.memref of any type values";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
  list<Type> allowedTypes = [AnyUnrankedMemRef, AnyNon0RankedMemRef];
}
def AnyNon0RankedOrUnrankedTensor {	// Constraint TypeConstraint Type AnyTypeOf
  Pred predicate = anonymous_118;
  string summary = "non-0-ranked or unranked tensor";
  string cppClassName = "::mlir::TensorType";
  string description = "";
  string builderCall = "";
  list<Type> allowedTypes = [AnyUnrankedTensor, AnyNon0RankedTensor];
}
def AnyNon0RankedTensor {	// Constraint TypeConstraint Type ShapedContainerType TensorOf Non0RankedTensorOf
  Pred predicate = anonymous_115;
  string summary = "non-0-ranked.tensor of any type values";
  string cppClassName = "::mlir::TensorType";
  string description = "";
  string builderCall = "";
}
def AnyRankedOrUnrankedMemRef {	// Constraint TypeConstraint Type ShapedContainerType RankedOrUnrankedMemRefOf
  Pred predicate = anonymous_146;
  string summary = "ranked or unranked memref of any type values";
  string cppClassName = "::mlir::BaseMemRefType";
  string description = "";
  string builderCall = "";
}
def AnyRankedTensor {	// Constraint TypeConstraint Type ShapedContainerType RankedTensorOf
  Pred predicate = anonymous_114;
  string summary = "ranked tensor of any type values";
  string cppClassName = "::mlir::RankedTensorType";
  string description = "";
  string builderCall = "";
}
def AnyRegion {	// Constraint RegionConstraint Region
  Pred predicate = anonymous_5;
  string summary = "any region";
}
def AnyScalableVector {	// Constraint TypeConstraint Type ShapedContainerType ScalableVectorOf
  Pred predicate = anonymous_56;
  string summary = "scalable vector of any type values";
  string cppClassName = "::mlir::VectorType";
  string description = "";
  string builderCall = "";
}
def AnyShaped {	// Constraint TypeConstraint Type ShapedContainerType
  Pred predicate = anonymous_57;
  string summary = "shaped of any type values";
  string cppClassName = "::mlir::ShapedType";
  string description = "";
  string builderCall = "";
}
def AnySignedInteger {	// Constraint TypeConstraint Type
  Pred predicate = anonymous_20;
  string summary = "signed integer";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
}
def AnySignlessInteger {	// Constraint TypeConstraint Type
  Pred predicate = anonymous_13;
  string summary = "signless integer";
  string cppClassName = "::mlir::IntegerType";
  string description = "";
  string builderCall = "";
}
def AnySignlessIntegerOrIndex {	// Constraint TypeConstraint Type
  Pred predicate = anonymous_33;
  string summary = "signless integer or index";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
}
def AnyStaticShapeMemRef {	// Constraint TypeConstraint Type ConfinedType StaticShapeMemRefOf
  Pred predicate = anonymous_157;
  string summary = "statically shaped memref of any type values";
  string cppClassName = "::mlir::MemRefType";
  string description = "";
  string builderCall = "";
}
def AnyStaticShapeTensor {	// Constraint TypeConstraint Type ShapedContainerType RankedTensorOf StaticShapeTensorOf
  Pred predicate = anonymous_140;
  string summary = "statically shaped tensor of any type values";
  string cppClassName = "::mlir::RankedTensorType";
  string description = "";
  string builderCall = "";
}
def AnyStridedMemRef {	// Constraint TypeConstraint Type ConfinedType StridedMemRefOf
  Pred predicate = anonymous_158;
  string summary = "strided memref of any type values";
  string cppClassName = "::mlir::MemRefType";
  string description = "";
  string builderCall = "";
}
def AnySuccessor {	// Constraint SuccessorConstraint Successor
  Pred predicate = ?;
  string summary = "any successor";
}
def AnyTensor {	// Constraint TypeConstraint Type ShapedContainerType TensorOf
  Pred predicate = anonymous_59;
  string summary = "tensor of any type values";
  string cppClassName = "::mlir::TensorType";
  string description = "";
  string builderCall = "";
}
def AnyTuple {	// Constraint TypeConstraint Type
  Pred predicate = IsTupleTypePred;
  string summary = "tuple";
  string cppClassName = "::mlir::TupleType";
  string description = "";
  string builderCall = "";
}
def AnyType {	// Constraint TypeConstraint Type
  Pred predicate = anonymous_5;
  string summary = "any type";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
}
def AnyUnrankedMemRef {	// Constraint TypeConstraint Type ShapedContainerType UnrankedMemRefOf
  Pred predicate = anonymous_141;
  string summary = "unranked.memref of any type values";
  string cppClassName = "::mlir::UnrankedMemRefType";
  string description = "";
  string builderCall = "";
}
def AnyUnrankedTensor {	// Constraint TypeConstraint Type ShapedContainerType UnrankedTensorOf
  Pred predicate = anonymous_117;
  string summary = "unranked tensor of any type values";
  string cppClassName = "::mlir::UnrankedTensorType";
  string description = "";
  string builderCall = "";
}
def AnyUnsignedInteger {	// Constraint TypeConstraint Type
  Pred predicate = anonymous_26;
  string summary = "unsigned integer";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
}
def AnyVector {	// Constraint TypeConstraint Type ShapedContainerType VectorOf
  Pred predicate = anonymous_53;
  string summary = "vector of any type values";
  string cppClassName = "::mlir::VectorType";
  string description = "";
  string builderCall = "";
}
def AnyVectorOfAnyRank {	// Constraint TypeConstraint Type ShapedContainerType VectorOfAnyRankOf
  Pred predicate = anonymous_54;
  string summary = "vector of any type values";
  string cppClassName = "::mlir::VectorType";
  string description = "";
  string builderCall = "";
}
def ArrayAttr {	// Constraint AttrConstraint Attr ArrayAttrBase
  Pred predicate = anonymous_271;
  string summary = "array attribute";
  code storageType = [{ ::mlir::ArrayAttr }];
  code returnType = [{ ::mlir::ArrayAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = "$_builder.getArrayAttr($0)";
  string defaultValue = ?;
  Type valueType = NoneType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def AttrSizedOperandSegments {	// Trait NativeTrait NativeOpTrait StructuralOpTrait
  string trait = "AttrSizedOperandSegments";
  string cppNamespace = "::mlir::OpTrait";
  code extraConcreteClassDeclaration = [{}];
  code extraConcreteClassDefinition = [{}];
  list<Trait> dependentTraits = [];
}
def AttrSizedResultSegments {	// Trait NativeTrait NativeOpTrait StructuralOpTrait
  string trait = "AttrSizedResultSegments";
  string cppNamespace = "::mlir::OpTrait";
  code extraConcreteClassDeclaration = [{}];
  code extraConcreteClassDefinition = [{}];
  list<Trait> dependentTraits = [];
}
def AutomaticAllocationScope {	// Trait NativeTrait NativeOpTrait
  string trait = "AutomaticAllocationScope";
  string cppNamespace = "::mlir::OpTrait";
  code extraConcreteClassDeclaration = [{}];
  code extraConcreteClassDefinition = [{}];
  list<Trait> dependentTraits = [];
}
def AutomaticAllocationScopeResource {	// Resource IntrinsicResource
  string name = "::mlir::SideEffects::AutomaticAllocationScopeResource";
}
def BF16 {	// Constraint TypeConstraint Type BuildableType
  Pred predicate = anonymous_40;
  string summary = "bfloat16 type";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "$_builder.getBF16Type()";
}
def BF16MemRef {	// Constraint TypeConstraint Type ShapedContainerType MemRefOf
  Pred predicate = anonymous_153;
  string summary = "memref of bfloat16 type values";
  string cppClassName = "::mlir::MemRefType";
  string description = "";
  string builderCall = "";
}
def BF16Tensor {	// Constraint TypeConstraint Type ShapedContainerType TensorOf
  Pred predicate = anonymous_94;
  string summary = "tensor of bfloat16 type values";
  string cppClassName = "::mlir::TensorType";
  string description = "";
  string builderCall = "";
}
def BoolArrayAttr {	// Constraint AttrConstraint Attr ArrayAttrBase TypedArrayAttrBase
  Pred predicate = anonymous_280;
  string summary = "1-bit boolean array attribute";
  code storageType = [{ ::mlir::ArrayAttr }];
  code returnType = [{ ::mlir::ArrayAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = "$_builder.getBoolArrayAttr($0)";
  string defaultValue = ?;
  Type valueType = NoneType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
  Attr elementAttr = BoolAttr;
}
def BoolAttr {	// Constraint AttrConstraint Attr
  Pred predicate = anonymous_190;
  string summary = "bool attribute";
  code storageType = [{ ::mlir::BoolAttr }];
  code returnType = [{ bool }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = "$_builder.getBoolAttr($0)";
  string defaultValue = ?;
  Type valueType = I1;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def BoolLike {	// Constraint TypeConstraint TypeOrContainer
  Pred predicate = anonymous_163;
  string summary = "bool-like";
  string cppClassName = "::mlir::Type";
}
def BoolLikeOfAnyRank {	// Constraint TypeConstraint TypeOrContainerOfAnyRank
  Pred predicate = anonymous_166;
  string summary = "bool-like";
  string cppClassName = "::mlir::Type";
}
def CallOpInterface {	// Interface Trait NativeTrait InterfaceTrait OpInterfaceTrait OpInterface
  code description = [{
    A call-like operation is one that transfers control from one sub-routine to
    another. These operations may be traditional direct calls `call @foo`, or
    indirect calls to other operations `call_indirect %foo`. An operation that
    uses this interface, must *not* also provide the `CallableOpInterface`.
  }];
  string cppInterfaceName = "CallOpInterface";
  string cppNamespace = "::mlir";
  list<InterfaceMethod> methods = [anonymous_341, anonymous_342, anonymous_343, anonymous_344];
  code extraClassDeclaration = [{
    /// Resolve the callable operation for given callee to a
    /// CallableOpInterface, or nullptr if a valid callable was not resolved.
    /// `symbolTable` is an optional parameter that will allow for using a
    /// cached symbol table for symbol lookups instead of performing an O(N)
    /// scan.
    ::mlir::Operation *resolveCallable(::mlir::SymbolTableCollection *symbolTable = nullptr);
  }];
  string extraSharedClassDeclaration = "";
  string extraClassOf = "";
  list<Interface> baseInterfaces = [];
  string trait = "CallOpInterface::Trait";
  code extraConcreteClassDeclaration = [{}];
  code extraConcreteClassDefinition = [{}];
  string extraTraitClassDeclaration = "";
  code verify = [{}];
  bit verifyWithRegions = 0;
  list<Trait> dependentTraits = [];
}
def CallableOpInterface {	// Interface Trait NativeTrait InterfaceTrait OpInterfaceTrait OpInterface
  code description = [{
    A callable operation is one who represents a potential sub-routine, and may
    be a target for a call-like operation (those providing the CallOpInterface
    above). These operations may be traditional functional operation
    `func @foo(...)`, as well as function producing operations
    `%foo = dialect.create_function(...)`. These operations may only contain a
    single region, or subroutine.
  }];
  string cppInterfaceName = "CallableOpInterface";
  string cppNamespace = "::mlir";
  list<InterfaceMethod> methods = [anonymous_345, anonymous_346, anonymous_347, anonymous_348, anonymous_349, anonymous_350, anonymous_351, anonymous_352, anonymous_353];
  string extraClassDeclaration = "";
  string extraSharedClassDeclaration = "";
  string extraClassOf = "";
  list<Interface> baseInterfaces = [];
  string trait = "CallableOpInterface::Trait";
  code extraConcreteClassDeclaration = [{}];
  code extraConcreteClassDefinition = [{}];
  string extraTraitClassDeclaration = "";
  code verify = [{}];
  bit verifyWithRegions = 0;
  list<Trait> dependentTraits = [];
}
def Commutative {	// Trait NativeTrait NativeOpTrait
  string trait = "IsCommutative";
  string cppNamespace = "::mlir::OpTrait";
  code extraConcreteClassDeclaration = [{}];
  code extraConcreteClassDefinition = [{}];
  list<Trait> dependentTraits = [];
}
def ConditionallySpeculatable {	// Interface Trait NativeTrait InterfaceTrait OpInterfaceTrait OpInterface
  code description = [{
    An interface used to query information about the speculability of an
    operation.
  }];
  string cppInterfaceName = "ConditionallySpeculatable";
  string cppNamespace = "::mlir";
  list<InterfaceMethod> methods = [anonymous_360];
  string extraClassDeclaration = "";
  string extraSharedClassDeclaration = "";
  string extraClassOf = "";
  list<Interface> baseInterfaces = [];
  string trait = "ConditionallySpeculatable::Trait";
  code extraConcreteClassDeclaration = [{}];
  code extraConcreteClassDefinition = [{}];
  string extraTraitClassDeclaration = "";
  code verify = [{}];
  bit verifyWithRegions = 0;
  list<Trait> dependentTraits = [];
}
def ConstBoolAttrFalse {	// Constraint AttrConstraint ConstantAttr
  Pred predicate = anonymous_313;
  string summary = "constant attribute false";
  Attr attr = BoolAttr;
  string value = "false";
}
def ConstBoolAttrTrue {	// Constraint AttrConstraint ConstantAttr
  Pred predicate = anonymous_314;
  string summary = "constant attribute true";
  Attr attr = BoolAttr;
  string value = "true";
}
def ConstUnitAttr {	// Constraint AttrConstraint ConstantAttr
  Pred predicate = anonymous_315;
  string summary = "constant attribute true";
  Attr attr = UnitAttr;
  string value = "true";
}
def ConstantLike {	// Trait NativeTrait NativeOpTrait
  string trait = "ConstantLike";
  string cppNamespace = "::mlir::OpTrait";
  code extraConcreteClassDeclaration = [{}];
  code extraConcreteClassDefinition = [{}];
  list<Trait> dependentTraits = [];
}
def DefaultResource {	// Resource IntrinsicResource
  string name = "::mlir::SideEffects::DefaultResource";
}
def DenseBoolArrayAttr {	// Constraint AttrConstraint Attr ElementsAttrBase DenseArrayAttrBase
  Pred predicate = anonymous_248;
  string summary = "i1 dense array attribute";
  string storageType = "::mlir::DenseBoolArrayAttr";
  string returnType = "::llvm::ArrayRef<bool>";
  string convertFromStorage = "$_self";
  string constBuilderCall = "$_builder.getDenseBoolArrayAttr($0)";
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def DenseF32ArrayAttr {	// Constraint AttrConstraint Attr ElementsAttrBase DenseArrayAttrBase
  Pred predicate = anonymous_253;
  string summary = "f32 dense array attribute";
  string storageType = "::mlir::DenseF32ArrayAttr";
  string returnType = "::llvm::ArrayRef<float>";
  string convertFromStorage = "$_self";
  string constBuilderCall = "$_builder.getDenseF32ArrayAttr($0)";
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def DenseF64ArrayAttr {	// Constraint AttrConstraint Attr ElementsAttrBase DenseArrayAttrBase
  Pred predicate = anonymous_254;
  string summary = "f64 dense array attribute";
  string storageType = "::mlir::DenseF64ArrayAttr";
  string returnType = "::llvm::ArrayRef<double>";
  string convertFromStorage = "$_self";
  string constBuilderCall = "$_builder.getDenseF64ArrayAttr($0)";
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def DenseI16ArrayAttr {	// Constraint AttrConstraint Attr ElementsAttrBase DenseArrayAttrBase
  Pred predicate = anonymous_250;
  string summary = "i16 dense array attribute";
  string storageType = "::mlir::DenseI16ArrayAttr";
  string returnType = "::llvm::ArrayRef<int16_t>";
  string convertFromStorage = "$_self";
  string constBuilderCall = "$_builder.getDenseI16ArrayAttr($0)";
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def DenseI32ArrayAttr {	// Constraint AttrConstraint Attr ElementsAttrBase DenseArrayAttrBase
  Pred predicate = anonymous_251;
  string summary = "i32 dense array attribute";
  string storageType = "::mlir::DenseI32ArrayAttr";
  string returnType = "::llvm::ArrayRef<int32_t>";
  string convertFromStorage = "$_self";
  string constBuilderCall = "$_builder.getDenseI32ArrayAttr($0)";
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def DenseI64ArrayAttr {	// Constraint AttrConstraint Attr ElementsAttrBase DenseArrayAttrBase
  Pred predicate = anonymous_252;
  string summary = "i64 dense array attribute";
  string storageType = "::mlir::DenseI64ArrayAttr";
  string returnType = "::llvm::ArrayRef<int64_t>";
  string convertFromStorage = "$_self";
  string constBuilderCall = "$_builder.getDenseI64ArrayAttr($0)";
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def DenseI8ArrayAttr {	// Constraint AttrConstraint Attr ElementsAttrBase DenseArrayAttrBase
  Pred predicate = anonymous_249;
  string summary = "i8 dense array attribute";
  string storageType = "::mlir::DenseI8ArrayAttr";
  string returnType = "::llvm::ArrayRef<int8_t>";
  string convertFromStorage = "$_self";
  string constBuilderCall = "$_builder.getDenseI8ArrayAttr($0)";
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def DictArrayAttr {	// Constraint AttrConstraint Attr ArrayAttrBase TypedArrayAttrBase
  Pred predicate = anonymous_304;
  string summary = "Array of dictionary attributes";
  code storageType = [{ ::mlir::ArrayAttr }];
  code returnType = [{ ::mlir::ArrayAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = "$_builder.getArrayAttr($0)";
  string defaultValue = ?;
  Type valueType = NoneType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
  Attr elementAttr = DictionaryAttr;
}
def DictionaryAttr {	// Constraint AttrConstraint Attr DictionaryAttrBase
  Pred predicate = anonymous_245;
  string summary = "dictionary of named attribute values";
  code storageType = [{ ::mlir::DictionaryAttr }];
  code returnType = [{ ::mlir::DictionaryAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = "$_builder.getDictionaryAttr($0)";
  string defaultValue = ?;
  Type valueType = NoneType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def ElementsAttr {	// Constraint AttrConstraint Attr ElementsAttrBase
  Pred predicate = anonymous_246;
  string summary = "constant vector/tensor attribute";
  code storageType = [{ ::mlir::ElementsAttr }];
  code returnType = [{ ::mlir::ElementsAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = ?;
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def Elementwise {	// Trait NativeTrait NativeOpTrait
  string trait = "Elementwise";
  string cppNamespace = "::mlir::OpTrait";
  code extraConcreteClassDeclaration = [{}];
  code extraConcreteClassDefinition = [{}];
  list<Trait> dependentTraits = [];
}
def ElementwiseMappable {	// Trait TraitList
  list<Trait> traits = [Elementwise, Scalarizable, Vectorizable, Tensorizable];
}
def F128 {	// Constraint TypeConstraint Type BuildableType F
  Pred predicate = anonymous_39;
  string summary = "128-bit float";
  string cppClassName = "::mlir::FloatType";
  string description = "";
  string builderCall = "$_builder.getF128Type()";
  int bitwidth = 128;
}
def F16 {	// Constraint TypeConstraint Type BuildableType F
  Pred predicate = anonymous_35;
  string summary = "16-bit float";
  string cppClassName = "::mlir::FloatType";
  string description = "";
  string builderCall = "$_builder.getF16Type()";
  int bitwidth = 16;
}
def F16MemRef {	// Constraint TypeConstraint Type ShapedContainerType MemRefOf
  Pred predicate = anonymous_154;
  string summary = "memref of 16-bit float values";
  string cppClassName = "::mlir::MemRefType";
  string description = "";
  string builderCall = "";
}
def F16Tensor {	// Constraint TypeConstraint Type ShapedContainerType TensorOf
  Pred predicate = anonymous_99;
  string summary = "tensor of 16-bit float values";
  string cppClassName = "::mlir::TensorType";
  string description = "";
  string builderCall = "";
}
def F32 {	// Constraint TypeConstraint Type BuildableType F
  Pred predicate = anonymous_36;
  string summary = "32-bit float";
  string cppClassName = "::mlir::FloatType";
  string description = "";
  string builderCall = "$_builder.getF32Type()";
  int bitwidth = 32;
}
def F32ArrayAttr {	// Constraint AttrConstraint Attr ArrayAttrBase TypedArrayAttrBase
  Pred predicate = anonymous_289;
  string summary = "32-bit float array attribute";
  code storageType = [{ ::mlir::ArrayAttr }];
  code returnType = [{ ::mlir::ArrayAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = "$_builder.getF32ArrayAttr($0)";
  string defaultValue = ?;
  Type valueType = NoneType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
  Attr elementAttr = F32Attr;
}
def F32Attr {	// Constraint AttrConstraint Attr TypedAttrBase FloatAttrBase
  Pred predicate = anonymous_236;
  string summary = "32-bit float attribute";
  string storageType = "::mlir::FloatAttr";
  code returnType = [{ ::llvm::APFloat }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = "$_builder.getFloatAttr($_builder.getF32Type(), $0)";
  string defaultValue = ?;
  Type valueType = F32;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def F32MemRef {	// Constraint TypeConstraint Type ShapedContainerType MemRefOf
  Pred predicate = anonymous_155;
  string summary = "memref of 32-bit float values";
  string cppClassName = "::mlir::MemRefType";
  string description = "";
  string builderCall = "";
}
def F32Tensor {	// Constraint TypeConstraint Type ShapedContainerType TensorOf
  Pred predicate = anonymous_104;
  string summary = "tensor of 32-bit float values";
  string cppClassName = "::mlir::TensorType";
  string description = "";
  string builderCall = "";
}
def F64 {	// Constraint TypeConstraint Type BuildableType F
  Pred predicate = anonymous_37;
  string summary = "64-bit float";
  string cppClassName = "::mlir::FloatType";
  string description = "";
  string builderCall = "$_builder.getF64Type()";
  int bitwidth = 64;
}
def F64ArrayAttr {	// Constraint AttrConstraint Attr ArrayAttrBase TypedArrayAttrBase
  Pred predicate = anonymous_292;
  string summary = "64-bit float array attribute";
  code storageType = [{ ::mlir::ArrayAttr }];
  code returnType = [{ ::mlir::ArrayAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = "$_builder.getF64ArrayAttr($0)";
  string defaultValue = ?;
  Type valueType = NoneType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
  Attr elementAttr = F64Attr;
}
def F64Attr {	// Constraint AttrConstraint Attr TypedAttrBase FloatAttrBase
  Pred predicate = anonymous_238;
  string summary = "64-bit float attribute";
  string storageType = "::mlir::FloatAttr";
  code returnType = [{ ::llvm::APFloat }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = "$_builder.getFloatAttr($_builder.getF64Type(), $0)";
  string defaultValue = ?;
  Type valueType = F64;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def F64ElementsAttr {	// Constraint AttrConstraint Attr ElementsAttrBase FloatElementsAttr
  Pred predicate = anonymous_268;
  string summary = "64-bit float elements attribute";
  code storageType = [{ ::mlir::DenseElementsAttr }];
  code returnType = [{ ::mlir::DenseElementsAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = "::mlir::DenseElementsAttr::get(::mlir::RankedTensorType::get({}, $_builder.getF64Type()),::llvm::ArrayRef($0))";
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def F64MemRef {	// Constraint TypeConstraint Type ShapedContainerType MemRefOf
  Pred predicate = anonymous_156;
  string summary = "memref of 64-bit float values";
  string cppClassName = "::mlir::MemRefType";
  string description = "";
  string builderCall = "";
}
def F64Tensor {	// Constraint TypeConstraint Type ShapedContainerType TensorOf
  Pred predicate = anonymous_109;
  string summary = "tensor of 64-bit float values";
  string cppClassName = "::mlir::TensorType";
  string description = "";
  string builderCall = "";
}
def F80 {	// Constraint TypeConstraint Type BuildableType F
  Pred predicate = anonymous_38;
  string summary = "80-bit float";
  string cppClassName = "::mlir::FloatType";
  string description = "";
  string builderCall = "$_builder.getF80Type()";
  int bitwidth = 80;
}
def F8E4M3B11FNUZ {	// Constraint TypeConstraint Type BuildableType
  Pred predicate = anonymous_45;
  string summary = "f8E4M3B11FNUZ type";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "$_builder.getFloat8E4M3B11FNUZType()";
}
def F8E4M3FN {	// Constraint TypeConstraint Type BuildableType
  Pred predicate = anonymous_42;
  string summary = "f8E4M3FN type";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "$_builder.getFloat8E4M3FNType()";
}
def F8E4M3FNUZ {	// Constraint TypeConstraint Type BuildableType
  Pred predicate = anonymous_44;
  string summary = "f8E4M3FNUZ type";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "$_builder.getFloat8E4M3FNUZType()";
}
def F8E5M2 {	// Constraint TypeConstraint Type BuildableType
  Pred predicate = anonymous_43;
  string summary = "f8E5M2 type";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "$_builder.getFloat8E5M2Type()";
}
def F8E5M2FNUZ {	// Constraint TypeConstraint Type BuildableType
  Pred predicate = anonymous_46;
  string summary = "f8E5M2FNUZ type";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "$_builder.getFloat8E5M2FNUZType()";
}
def FirstAttrDerivedResultType {	// Trait GenInternalTrait GenInternalOpTrait
  string trait = "::mlir::OpTrait::FirstAttrDerivedResultType";
  list<Trait> dependentTraits = [];
}
def FlatSymbolRefArrayAttr {	// Constraint AttrConstraint Attr ArrayAttrBase TypedArrayAttrBase
  Pred predicate = anonymous_312;
  string summary = "flat symbol ref array attribute";
  code storageType = [{ ::mlir::ArrayAttr }];
  code returnType = [{ ::mlir::ArrayAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = ?;
  string defaultValue = ?;
  Type valueType = NoneType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
  Attr elementAttr = FlatSymbolRefAttr;
}
def FlatSymbolRefAttr {	// Constraint AttrConstraint Attr
  Pred predicate = anonymous_306;
  string summary = "flat symbol reference attribute";
  code storageType = [{ ::mlir::FlatSymbolRefAttr }];
  code returnType = [{ ::llvm::StringRef }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = "::mlir::SymbolRefAttr::get($_builder.getContext(), $0)";
  string defaultValue = ?;
  Type valueType = NoneType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def FloatLike {	// Constraint TypeConstraint TypeOrContainer
  Pred predicate = anonymous_187;
  string summary = "floating-point-like";
  string cppClassName = "::mlir::Type";
}
def FullEffect {	// EffectRange
  bits<1> Value = { 1 };
}
def FunctionOpInterface {	// Interface Trait NativeTrait InterfaceTrait OpInterfaceTrait OpInterface
  code description = [{
    This interfaces provides support for interacting with operations that
    behave like functions. In particular, these operations:

      - must be symbols, i.e. have the `Symbol` trait.
      - must have a single region, that may be comprised with multiple blocks,
        that corresponds to the function body.
        * when this region is empty, the operation corresponds to an external
          function.
        * leading arguments of the first block of the region are treated as
          function arguments.

    The function, aside from implementing the various interface methods,
    should have the following ODS arguments:

      - `function_type` (required)
        * A TypeAttr that holds the signature type of the function.

      - `arg_attrs` (optional)
        * An ArrayAttr of DictionaryAttr that contains attribute dictionaries
          for each of the function arguments.

      - `res_attrs` (optional)
        * An ArrayAttr of DictionaryAttr that contains attribute dictionaries
          for each of the function results.
  }];
  string cppInterfaceName = "FunctionOpInterface";
  string cppNamespace = "::mlir";
  list<InterfaceMethod> methods = [anonymous_354, anonymous_355, anonymous_356, anonymous_357, anonymous_358];
  string extraClassDeclaration = "";
  code extraSharedClassDeclaration = [{
    /// Block list iterator types.
    using BlockListType = ::mlir::Region::BlockListType;
    using iterator = BlockListType::iterator;
    using reverse_iterator = BlockListType::reverse_iterator;

    /// Block argument iterator types.
    using BlockArgListType = ::mlir::Region::BlockArgListType;
    using args_iterator = BlockArgListType::iterator;

    //===------------------------------------------------------------------===//
    // Body Handling
    //===------------------------------------------------------------------===//

    /// Returns true if this function is external, i.e. it has no body.
    bool isExternal() { return empty(); }

    /// Return the region containing the body of this function.
    ::mlir::Region &getFunctionBody() { return $_op->getRegion(0); }

    /// Delete all blocks from this function.
    void eraseBody() {
      getFunctionBody().dropAllReferences();
      getFunctionBody().getBlocks().clear();
    }

    /// Return the list of blocks within the function body.
    BlockListType &getBlocks() { return getFunctionBody().getBlocks(); }

    iterator begin() { return getFunctionBody().begin(); }
    iterator end() { return getFunctionBody().end(); }
    reverse_iterator rbegin() { return getFunctionBody().rbegin(); }
    reverse_iterator rend() { return getFunctionBody().rend(); }

    /// Returns true if this function has no blocks within the body.
    bool empty() { return getFunctionBody().empty(); }

    /// Push a new block to the back of the body region.
    void push_back(::mlir::Block *block) { getFunctionBody().push_back(block); }

    /// Push a new block to the front of the body region.
    void push_front(::mlir::Block *block) { getFunctionBody().push_front(block); }

    /// Return the last block in the body region.
    ::mlir::Block &back() { return getFunctionBody().back(); }

    /// Return the first block in the body region.
    ::mlir::Block &front() { return getFunctionBody().front(); }

    /// Add an entry block to an empty function, and set up the block arguments
    /// to match the signature of the function. The newly inserted entry block
    /// is returned.
    ::mlir::Block *addEntryBlock() {
      assert(empty() && "function already has an entry block");
      ::mlir::Block *entry = new ::mlir::Block();
      push_back(entry);

      // FIXME: Allow for passing in locations for these arguments instead of using
      // the operations location.
      ::llvm::ArrayRef<::mlir::Type> inputTypes = $_op.getArgumentTypes();
      ::llvm::SmallVector<::mlir::Location> locations(inputTypes.size(),
                                              $_op.getOperation()->getLoc());
      entry->addArguments(inputTypes, locations);
      return entry;
    }

    /// Add a normal block to the end of the function's block list. The function
    /// should at least already have an entry block.
    ::mlir::Block *addBlock() {
      assert(!empty() && "function should at least have an entry block");
      push_back(new ::mlir::Block());
      return &back();
    }

    //===------------------------------------------------------------------===//
    // Type Attribute Handling
    //===------------------------------------------------------------------===//

    /// Change the type of this function in place. This is an extremely dangerous
    /// operation and it is up to the caller to ensure that this is legal for
    /// this function, and to restore invariants:
    ///  - the entry block args must be updated to match the function params.
    ///  - the argument/result attributes may need an update: if the new type
    ///    has less parameters we drop the extra attributes, if there are more
    ///    parameters they won't have any attributes.
    void setType(::mlir::Type newType) {
      ::mlir::function_interface_impl::setFunctionType($_op, newType);
    }

    //===------------------------------------------------------------------===//
    // Argument and Result Handling
    //===------------------------------------------------------------------===//

    /// Returns the number of function arguments.
    unsigned getNumArguments() { return $_op.getArgumentTypes().size(); }

    /// Returns the number of function results.
    unsigned getNumResults() { return $_op.getResultTypes().size(); }

    /// Returns the entry block function argument at the given index.
    ::mlir::BlockArgument getArgument(unsigned idx) {
      return getFunctionBody().getArgument(idx);
    }

    /// Support argument iteration.
    args_iterator args_begin() { return getFunctionBody().args_begin(); }
    args_iterator args_end() { return getFunctionBody().args_end(); }
    BlockArgListType getArguments() { return getFunctionBody().getArguments(); }

    /// Insert a single argument of type `argType` with attributes `argAttrs` and
    /// location `argLoc` at `argIndex`.
    void insertArgument(unsigned argIndex, ::mlir::Type argType, ::mlir::DictionaryAttr argAttrs,
                        ::mlir::Location argLoc) {
      insertArguments({argIndex}, {argType}, {argAttrs}, {argLoc});
    }

    /// Inserts arguments with the listed types, attributes, and locations at the
    /// listed indices. `argIndices` must be sorted. Arguments are inserted in the
    /// order they are listed, such that arguments with identical index will
    /// appear in the same order that they were listed here.
    void insertArguments(::llvm::ArrayRef<unsigned> argIndices, ::mlir::TypeRange argTypes,
                        ::llvm::ArrayRef<::mlir::DictionaryAttr> argAttrs,
                        ::llvm::ArrayRef<::mlir::Location> argLocs) {
      unsigned originalNumArgs = $_op.getNumArguments();
      ::mlir::Type newType = $_op.getTypeWithArgsAndResults(
          argIndices, argTypes, /*resultIndices=*/{}, /*resultTypes=*/{});
      ::mlir::function_interface_impl::insertFunctionArguments(
          $_op, argIndices, argTypes, argAttrs, argLocs,
          originalNumArgs, newType);
    }

    /// Insert a single result of type `resultType` at `resultIndex`.
    void insertResult(unsigned resultIndex, ::mlir::Type resultType,
                      ::mlir::DictionaryAttr resultAttrs) {
      insertResults({resultIndex}, {resultType}, {resultAttrs});
    }

    /// Inserts results with the listed types at the listed indices.
    /// `resultIndices` must be sorted. Results are inserted in the order they are
    /// listed, such that results with identical index will appear in the same
    /// order that they were listed here.
    void insertResults(::llvm::ArrayRef<unsigned> resultIndices, ::mlir::TypeRange resultTypes,
                       ::llvm::ArrayRef<::mlir::DictionaryAttr> resultAttrs) {
      unsigned originalNumResults = $_op.getNumResults();
      ::mlir::Type newType = $_op.getTypeWithArgsAndResults(
        /*argIndices=*/{}, /*argTypes=*/{}, resultIndices, resultTypes);
      ::mlir::function_interface_impl::insertFunctionResults(
          $_op, resultIndices, resultTypes, resultAttrs,
          originalNumResults, newType);
    }

    /// Erase a single argument at `argIndex`.
    void eraseArgument(unsigned argIndex) {
      ::llvm::BitVector argsToErase($_op.getNumArguments());
      argsToErase.set(argIndex);
      eraseArguments(argsToErase);
    }

    /// Erases the arguments listed in `argIndices`.
    void eraseArguments(const ::llvm::BitVector &argIndices) {
      ::mlir::Type newType = $_op.getTypeWithoutArgs(argIndices);
      ::mlir::function_interface_impl::eraseFunctionArguments(
        $_op, argIndices, newType);
    }

    /// Erase a single result at `resultIndex`.
    void eraseResult(unsigned resultIndex) {
      ::llvm::BitVector resultsToErase($_op.getNumResults());
      resultsToErase.set(resultIndex);
      eraseResults(resultsToErase);
    }

    /// Erases the results listed in `resultIndices`.
    void eraseResults(const ::llvm::BitVector &resultIndices) {
      ::mlir::Type newType = $_op.getTypeWithoutResults(resultIndices);
      ::mlir::function_interface_impl::eraseFunctionResults(
          $_op, resultIndices, newType);
    }

    /// Return the type of this function with the specified arguments and
    /// results inserted. This is used to update the function's signature in
    /// the `insertArguments` and `insertResults` methods. The arrays must be
    /// sorted by increasing index.
    ::mlir::Type getTypeWithArgsAndResults(
      ::llvm::ArrayRef<unsigned> argIndices, ::mlir::TypeRange argTypes,
      ::llvm::ArrayRef<unsigned> resultIndices, ::mlir::TypeRange resultTypes) {
      ::llvm::SmallVector<::mlir::Type> argStorage, resultStorage;
      ::mlir::TypeRange newArgTypes = insertTypesInto(
          $_op.getArgumentTypes(), argIndices, argTypes, argStorage);
      ::mlir::TypeRange newResultTypes = insertTypesInto(
          $_op.getResultTypes(), resultIndices, resultTypes, resultStorage);
      return $_op.cloneTypeWith(newArgTypes, newResultTypes);
    }

    /// Return the type of this function without the specified arguments and
    /// results. This is used to update the function's signature in the
    /// `eraseArguments` and `eraseResults` methods.
    ::mlir::Type getTypeWithoutArgsAndResults(
      const ::llvm::BitVector &argIndices, const ::llvm::BitVector &resultIndices) {
      ::llvm::SmallVector<::mlir::Type> argStorage, resultStorage;
      ::mlir::TypeRange newArgTypes = filterTypesOut(
          $_op.getArgumentTypes(), argIndices, argStorage);
      ::mlir::TypeRange newResultTypes = filterTypesOut(
          $_op.getResultTypes(), resultIndices, resultStorage);
      return $_op.cloneTypeWith(newArgTypes, newResultTypes);
    }
    ::mlir::Type getTypeWithoutArgs(const ::llvm::BitVector &argIndices) {
      ::llvm::SmallVector<::mlir::Type> argStorage;
      ::mlir::TypeRange newArgTypes = filterTypesOut(
          $_op.getArgumentTypes(), argIndices, argStorage);
      return $_op.cloneTypeWith(newArgTypes, $_op.getResultTypes());
    }
    ::mlir::Type getTypeWithoutResults(const ::llvm::BitVector &resultIndices) {
      ::llvm::SmallVector<::mlir::Type> resultStorage;
      ::mlir::TypeRange newResultTypes = filterTypesOut(
          $_op.getResultTypes(), resultIndices, resultStorage);
      return $_op.cloneTypeWith($_op.getArgumentTypes(), newResultTypes);
    }

    //===------------------------------------------------------------------===//
    // Argument Attributes
    //===------------------------------------------------------------------===//

    /// Return all of the attributes for the argument at 'index'.
    ::llvm::ArrayRef<::mlir::NamedAttribute> getArgAttrs(unsigned index) {
      return ::mlir::function_interface_impl::getArgAttrs($_op, index);
    }

    /// Return an ArrayAttr containing all argument attribute dictionaries of
    /// this function, or nullptr if no arguments have attributes.
    ::mlir::ArrayAttr getAllArgAttrs() { return $_op.getArgAttrsAttr(); }

    /// Return all argument attributes of this function.
    void getAllArgAttrs(::llvm::SmallVectorImpl<::mlir::DictionaryAttr> &result) {
      if (::mlir::ArrayAttr argAttrs = getAllArgAttrs()) {
        auto argAttrRange = argAttrs.template getAsRange<::mlir::DictionaryAttr>();
        result.append(argAttrRange.begin(), argAttrRange.end());
      } else {
        result.append($_op.getNumArguments(),
                      ::mlir::DictionaryAttr::get(this->getOperation()->getContext()));
      }
    }

    /// Return the specified attribute, if present, for the argument at 'index',
    /// null otherwise.
    ::mlir::Attribute getArgAttr(unsigned index, ::mlir::StringAttr name) {
      auto argDict = getArgAttrDict(index);
      return argDict ? argDict.get(name) : nullptr;
    }
    ::mlir::Attribute getArgAttr(unsigned index, ::llvm::StringRef name) {
      auto argDict = getArgAttrDict(index);
      return argDict ? argDict.get(name) : nullptr;
    }

    template <typename AttrClass>
    AttrClass getArgAttrOfType(unsigned index, ::mlir::StringAttr name) {
      return ::llvm::dyn_cast_or_null<AttrClass>(getArgAttr(index, name));
    }
    template <typename AttrClass>
    AttrClass getArgAttrOfType(unsigned index, ::llvm::StringRef name) {
      return ::llvm::dyn_cast_or_null<AttrClass>(getArgAttr(index, name));
    }

    /// Set the attributes held by the argument at 'index'.
    void setArgAttrs(unsigned index, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
      ::mlir::function_interface_impl::setArgAttrs($_op, index, attributes);
    }

    /// Set the attributes held by the argument at 'index'. `attributes` may be
    /// null, in which case any existing argument attributes are removed.
    void setArgAttrs(unsigned index, ::mlir::DictionaryAttr attributes) {
      ::mlir::function_interface_impl::setArgAttrs($_op, index, attributes);
    }
    void setAllArgAttrs(::llvm::ArrayRef<::mlir::DictionaryAttr> attributes) {
      assert(attributes.size() == $_op.getNumArguments());
      ::mlir::function_interface_impl::setAllArgAttrDicts($_op, attributes);
    }
    void setAllArgAttrs(::llvm::ArrayRef<::mlir::Attribute> attributes) {
      assert(attributes.size() == $_op.getNumArguments());
      ::mlir::function_interface_impl::setAllArgAttrDicts($_op, attributes);
    }
    void setAllArgAttrs(::mlir::ArrayAttr attributes) {
      assert(attributes.size() == $_op.getNumArguments());
      $_op.setArgAttrsAttr(attributes);
    }

    /// If the an attribute exists with the specified name, change it to the new
    /// value. Otherwise, add a new attribute with the specified name/value.
    void setArgAttr(unsigned index, ::mlir::StringAttr name, ::mlir::Attribute value) {
      ::mlir::function_interface_impl::setArgAttr($_op, index, name, value);
    }
    void setArgAttr(unsigned index, ::llvm::StringRef name, ::mlir::Attribute value) {
      setArgAttr(index,
                 ::mlir::StringAttr::get(this->getOperation()->getContext(), name),
                 value);
    }

    /// Remove the attribute 'name' from the argument at 'index'. Return the
    /// attribute that was erased, or nullptr if there was no attribute with
    /// such name.
    ::mlir::Attribute removeArgAttr(unsigned index, ::mlir::StringAttr name) {
      return ::mlir::function_interface_impl::removeArgAttr($_op, index, name);
    }
    ::mlir::Attribute removeArgAttr(unsigned index, ::llvm::StringRef name) {
      return removeArgAttr(
          index, ::mlir::StringAttr::get(this->getOperation()->getContext(), name));
    }

    //===------------------------------------------------------------------===//
    // Result Attributes
    //===------------------------------------------------------------------===//

    /// Return all of the attributes for the result at 'index'.
    ::llvm::ArrayRef<::mlir::NamedAttribute> getResultAttrs(unsigned index) {
      return ::mlir::function_interface_impl::getResultAttrs($_op, index);
    }

    /// Return an ArrayAttr containing all result attribute dictionaries of this
    /// function, or nullptr if no result have attributes.
    ::mlir::ArrayAttr getAllResultAttrs() { return $_op.getResAttrsAttr(); }

    /// Return all result attributes of this function.
    void getAllResultAttrs(::llvm::SmallVectorImpl<::mlir::DictionaryAttr> &result) {
      if (::mlir::ArrayAttr argAttrs = getAllResultAttrs()) {
        auto argAttrRange = argAttrs.template getAsRange<::mlir::DictionaryAttr>();
        result.append(argAttrRange.begin(), argAttrRange.end());
      } else {
        result.append($_op.getNumResults(),
                      ::mlir::DictionaryAttr::get(this->getOperation()->getContext()));
      }
    }

    /// Return the specified attribute, if present, for the result at 'index',
    /// null otherwise.
    ::mlir::Attribute getResultAttr(unsigned index, ::mlir::StringAttr name) {
      auto argDict = getResultAttrDict(index);
      return argDict ? argDict.get(name) : nullptr;
    }
    ::mlir::Attribute getResultAttr(unsigned index, ::llvm::StringRef name) {
      auto argDict = getResultAttrDict(index);
      return argDict ? argDict.get(name) : nullptr;
    }

    template <typename AttrClass>
    AttrClass getResultAttrOfType(unsigned index, ::mlir::StringAttr name) {
      return ::llvm::dyn_cast_or_null<AttrClass>(getResultAttr(index, name));
    }
    template <typename AttrClass>
    AttrClass getResultAttrOfType(unsigned index, ::llvm::StringRef name) {
      return ::llvm::dyn_cast_or_null<AttrClass>(getResultAttr(index, name));
    }

    /// Set the attributes held by the result at 'index'.
    void setResultAttrs(unsigned index, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
      ::mlir::function_interface_impl::setResultAttrs($_op, index, attributes);
    }

    /// Set the attributes held by the result at 'index'. `attributes` may be
    /// null, in which case any existing argument attributes are removed.
    void setResultAttrs(unsigned index, ::mlir::DictionaryAttr attributes) {
      ::mlir::function_interface_impl::setResultAttrs($_op, index, attributes);
    }
    void setAllResultAttrs(::llvm::ArrayRef<::mlir::DictionaryAttr> attributes) {
      assert(attributes.size() == $_op.getNumResults());
      ::mlir::function_interface_impl::setAllResultAttrDicts(
        $_op, attributes);
    }
    void setAllResultAttrs(::llvm::ArrayRef<::mlir::Attribute> attributes) {
      assert(attributes.size() == $_op.getNumResults());
      ::mlir::function_interface_impl::setAllResultAttrDicts(
        $_op, attributes);
    }
    void setAllResultAttrs(::mlir::ArrayAttr attributes) {
      assert(attributes.size() == $_op.getNumResults());
      $_op.setResAttrsAttr(attributes);
    }

    /// If the an attribute exists with the specified name, change it to the new
    /// value. Otherwise, add a new attribute with the specified name/value.
    void setResultAttr(unsigned index, ::mlir::StringAttr name, ::mlir::Attribute value) {
      ::mlir::function_interface_impl::setResultAttr($_op, index, name, value);
    }
    void setResultAttr(unsigned index, ::llvm::StringRef name, ::mlir::Attribute value) {
      setResultAttr(index,
                    ::mlir::StringAttr::get(this->getOperation()->getContext(), name),
                    value);
    }

    /// Remove the attribute 'name' from the result at 'index'. Return the
    /// attribute that was erased, or nullptr if there was no attribute with
    /// such name.
    ::mlir::Attribute removeResultAttr(unsigned index, ::mlir::StringAttr name) {
      return ::mlir::function_interface_impl::removeResultAttr($_op, index, name);
    }

    /// Returns the dictionary attribute corresponding to the argument at
    /// 'index'. If there are no argument attributes at 'index', a null
    /// attribute is returned.
    ::mlir::DictionaryAttr getArgAttrDict(unsigned index) {
      assert(index < $_op.getNumArguments() && "invalid argument number");
      return ::mlir::function_interface_impl::getArgAttrDict($_op, index);
    }

    /// Returns the dictionary attribute corresponding to the result at 'index'.
    /// If there are no result attributes at 'index', a null attribute is
    /// returned.
    ::mlir::DictionaryAttr getResultAttrDict(unsigned index) {
      assert(index < $_op.getNumResults() && "invalid result number");
      return ::mlir::function_interface_impl::getResultAttrDict($_op, index);
    }
  }];
  string extraClassOf = "";
  list<Interface> baseInterfaces = [Symbol, CallableOpInterface];
  string trait = "FunctionOpInterface::Trait";
  code extraConcreteClassDeclaration = [{}];
  code extraConcreteClassDefinition = [{}];
  code extraTraitClassDeclaration = [{
    //===------------------------------------------------------------------===//
    // Builders
    //===------------------------------------------------------------------===//

    /// Build the function with the given name, attributes, and type. This
    /// builder also inserts an entry block into the function body with the
    /// given argument types.
    static void buildWithEntryBlock(
        OpBuilder &builder, OperationState &state, StringRef name, Type type,
        ArrayRef<NamedAttribute> attrs, TypeRange inputTypes) {
      OpBuilder::InsertionGuard g(builder);
      state.addAttribute(SymbolTable::getSymbolAttrName(),
                        builder.getStringAttr(name));
      state.addAttribute(ConcreteOp::getFunctionTypeAttrName(state.name),
                        TypeAttr::get(type));
      state.attributes.append(attrs.begin(), attrs.end());

      // Add the function body.
      Region *bodyRegion = state.addRegion();
      Block *body = builder.createBlock(bodyRegion);
      for (Type input : inputTypes)
        body->addArgument(input, state.location);
    }
  }];
  string verify = "return function_interface_impl::verifyTrait(cast<ConcreteOp>($_op));";
  bit verifyWithRegions = 0;
  list<Trait> dependentTraits = [];
}
def FunctionType {	// Constraint TypeConstraint Type
  Pred predicate = anonymous_48;
  string summary = "function type";
  string cppClassName = "::mlir::FunctionType";
  string description = "";
  string builderCall = "";
}
def HasRankPred {	// Pred CPred
  string predExpr = "(::llvm::cast<::mlir::ShapedType>($_self).hasRank())";
}
def HasStaticShapePred {	// Pred CPred
  string predExpr = "(::llvm::cast<::mlir::ShapedType>($_self).hasStaticShape())";
}
def HasStridesPred {	// Pred CPred
  code predExpr = [{( isStrided(::llvm::cast<::mlir::MemRefType>($_self)) )}];
}
def I1 {	// Constraint TypeConstraint Type BuildableType I
  Pred predicate = anonymous_14;
  string summary = "1-bit signless integer";
  string cppClassName = "::mlir::IntegerType";
  string description = "";
  string builderCall = "$_builder.getIntegerType(1)";
  int bitwidth = 1;
}
def I128 {	// Constraint TypeConstraint Type BuildableType I
  Pred predicate = anonymous_19;
  string summary = "128-bit signless integer";
  string cppClassName = "::mlir::IntegerType";
  string description = "";
  string builderCall = "$_builder.getIntegerType(128)";
  int bitwidth = 128;
}
def I16 {	// Constraint TypeConstraint Type BuildableType I
  Pred predicate = anonymous_16;
  string summary = "16-bit signless integer";
  string cppClassName = "::mlir::IntegerType";
  string description = "";
  string builderCall = "$_builder.getIntegerType(16)";
  int bitwidth = 16;
}
def I16Attr {	// Constraint AttrConstraint Attr TypedAttrBase SignlessIntegerAttrBase TypedSignlessIntegerAttrBase
  Pred predicate = anonymous_209;
  string summary = "16-bit signless integer attribute";
  string storageType = "::mlir::IntegerAttr";
  string returnType = "uint16_t";
  string convertFromStorage = "$_self.getValue().getZExtValue()";
  string constBuilderCall = "$_builder.getIntegerAttr($_builder.getIntegerType(16), $0)";
  string defaultValue = ?;
  Type valueType = I16;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def I16MemRef {	// Constraint TypeConstraint Type ShapedContainerType MemRefOf
  Pred predicate = anonymous_150;
  string summary = "memref of 16-bit signless integer values";
  string cppClassName = "::mlir::MemRefType";
  string description = "";
  string builderCall = "";
}
def I16Tensor {	// Constraint TypeConstraint Type ShapedContainerType TensorOf
  Pred predicate = anonymous_74;
  string summary = "tensor of 16-bit signless integer values";
  string cppClassName = "::mlir::TensorType";
  string description = "";
  string builderCall = "";
}
def I1Attr {	// Constraint AttrConstraint Attr TypedAttrBase SignlessIntegerAttrBase TypedSignlessIntegerAttrBase
  Pred predicate = anonymous_205;
  string summary = "1-bit signless integer attribute";
  string storageType = "::mlir::IntegerAttr";
  string returnType = "bool";
  string convertFromStorage = "$_self.getValue().getZExtValue()";
  string constBuilderCall = "$_builder.getIntegerAttr($_builder.getIntegerType(1), $0)";
  string defaultValue = ?;
  Type valueType = I1;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def I1MemRef {	// Constraint TypeConstraint Type ShapedContainerType MemRefOf
  Pred predicate = anonymous_148;
  string summary = "memref of 1-bit signless integer values";
  string cppClassName = "::mlir::MemRefType";
  string description = "";
  string builderCall = "";
}
def I1Tensor {	// Constraint TypeConstraint Type ShapedContainerType TensorOf
  Pred predicate = anonymous_64;
  string summary = "tensor of 1-bit signless integer values";
  string cppClassName = "::mlir::TensorType";
  string description = "";
  string builderCall = "";
}
def I32 {	// Constraint TypeConstraint Type BuildableType I
  Pred predicate = anonymous_17;
  string summary = "32-bit signless integer";
  string cppClassName = "::mlir::IntegerType";
  string description = "";
  string builderCall = "$_builder.getIntegerType(32)";
  int bitwidth = 32;
}
def I32ArrayAttr {	// Constraint AttrConstraint Attr ArrayAttrBase TypedArrayAttrBase
  Pred predicate = anonymous_283;
  string summary = "32-bit integer array attribute";
  code storageType = [{ ::mlir::ArrayAttr }];
  code returnType = [{ ::mlir::ArrayAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = "$_builder.getI32ArrayAttr($0)";
  string defaultValue = ?;
  Type valueType = NoneType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
  Attr elementAttr = I32Attr;
}
def I32Attr {	// Constraint AttrConstraint Attr TypedAttrBase SignlessIntegerAttrBase TypedSignlessIntegerAttrBase
  Pred predicate = anonymous_211;
  string summary = "32-bit signless integer attribute";
  string storageType = "::mlir::IntegerAttr";
  string returnType = "uint32_t";
  string convertFromStorage = "$_self.getValue().getZExtValue()";
  string constBuilderCall = "$_builder.getIntegerAttr($_builder.getIntegerType(32), $0)";
  string defaultValue = ?;
  Type valueType = I32;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def I32ElementsAttr {	// Constraint AttrConstraint Attr ElementsAttrBase IntElementsAttrBase SignlessIntElementsAttr
  Pred predicate = anonymous_263;
  string summary = "32-bit signless integer elements attribute";
  code storageType = [{ ::mlir::DenseIntElementsAttr }];
  code returnType = [{ ::mlir::DenseIntElementsAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = "::llvm::cast<::mlir::DenseIntElementsAttr>(::mlir::DenseElementsAttr::get(::mlir::RankedTensorType::get({}, $_builder.getIntegerType(32)), ::llvm::ArrayRef($0)))";
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def I32MemRef {	// Constraint TypeConstraint Type ShapedContainerType MemRefOf
  Pred predicate = anonymous_151;
  string summary = "memref of 32-bit signless integer values";
  string cppClassName = "::mlir::MemRefType";
  string description = "";
  string builderCall = "";
}
def I32Tensor {	// Constraint TypeConstraint Type ShapedContainerType TensorOf
  Pred predicate = anonymous_79;
  string summary = "tensor of 32-bit signless integer values";
  string cppClassName = "::mlir::TensorType";
  string description = "";
  string builderCall = "";
}
def I64 {	// Constraint TypeConstraint Type BuildableType I
  Pred predicate = anonymous_18;
  string summary = "64-bit signless integer";
  string cppClassName = "::mlir::IntegerType";
  string description = "";
  string builderCall = "$_builder.getIntegerType(64)";
  int bitwidth = 64;
}
def I64ArrayAttr {	// Constraint AttrConstraint Attr ArrayAttrBase TypedArrayAttrBase
  Pred predicate = anonymous_286;
  string summary = "64-bit integer array attribute";
  code storageType = [{ ::mlir::ArrayAttr }];
  code returnType = [{ ::mlir::ArrayAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = "$_builder.getI64ArrayAttr($0)";
  string defaultValue = ?;
  Type valueType = NoneType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
  Attr elementAttr = I64Attr;
}
def I64Attr {	// Constraint AttrConstraint Attr TypedAttrBase SignlessIntegerAttrBase TypedSignlessIntegerAttrBase
  Pred predicate = anonymous_213;
  string summary = "64-bit signless integer attribute";
  string storageType = "::mlir::IntegerAttr";
  string returnType = "uint64_t";
  string convertFromStorage = "$_self.getValue().getZExtValue()";
  string constBuilderCall = "$_builder.getIntegerAttr($_builder.getIntegerType(64), $0)";
  string defaultValue = ?;
  Type valueType = I64;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def I64ElementsAttr {	// Constraint AttrConstraint Attr ElementsAttrBase IntElementsAttrBase SignlessIntElementsAttr
  Pred predicate = anonymous_265;
  string summary = "64-bit signless integer elements attribute";
  code storageType = [{ ::mlir::DenseIntElementsAttr }];
  code returnType = [{ ::mlir::DenseIntElementsAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = "::llvm::cast<::mlir::DenseIntElementsAttr>(::mlir::DenseElementsAttr::get(::mlir::RankedTensorType::get({}, $_builder.getIntegerType(64)), ::llvm::ArrayRef($0)))";
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def I64MemRef {	// Constraint TypeConstraint Type ShapedContainerType MemRefOf
  Pred predicate = anonymous_152;
  string summary = "memref of 64-bit signless integer values";
  string cppClassName = "::mlir::MemRefType";
  string description = "";
  string builderCall = "";
}
def I64SmallVectorArrayAttr {	// Constraint AttrConstraint Attr ArrayAttrBase TypedArrayAttrBase
  Pred predicate = anonymous_286;
  string summary = "64-bit integer array attribute";
  code storageType = [{ ::mlir::ArrayAttr }];
  code returnType = [{ ::llvm::SmallVector<int64_t, 8> }];
  code convertFromStorage = [{
    llvm::to_vector<4>(
      llvm::map_range($_self.getAsRange<mlir::IntegerAttr>(),
      [](mlir::IntegerAttr attr) { return attr.getInt(); }));
  }];
  string constBuilderCall = "$_builder.getI64ArrayAttr($0)";
  string defaultValue = ?;
  Type valueType = NoneType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
  Attr elementAttr = I64Attr;
}
def I64Tensor {	// Constraint TypeConstraint Type ShapedContainerType TensorOf
  Pred predicate = anonymous_84;
  string summary = "tensor of 64-bit signless integer values";
  string cppClassName = "::mlir::TensorType";
  string description = "";
  string builderCall = "";
}
def I8 {	// Constraint TypeConstraint Type BuildableType I
  Pred predicate = anonymous_15;
  string summary = "8-bit signless integer";
  string cppClassName = "::mlir::IntegerType";
  string description = "";
  string builderCall = "$_builder.getIntegerType(8)";
  int bitwidth = 8;
}
def I8Attr {	// Constraint AttrConstraint Attr TypedAttrBase SignlessIntegerAttrBase TypedSignlessIntegerAttrBase
  Pred predicate = anonymous_207;
  string summary = "8-bit signless integer attribute";
  string storageType = "::mlir::IntegerAttr";
  string returnType = "uint8_t";
  string convertFromStorage = "$_self.getValue().getZExtValue()";
  string constBuilderCall = "$_builder.getIntegerAttr($_builder.getIntegerType(8), $0)";
  string defaultValue = ?;
  Type valueType = I8;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def I8MemRef {	// Constraint TypeConstraint Type ShapedContainerType MemRefOf
  Pred predicate = anonymous_149;
  string summary = "memref of 8-bit signless integer values";
  string cppClassName = "::mlir::MemRefType";
  string description = "";
  string builderCall = "";
}
def I8Tensor {	// Constraint TypeConstraint Type ShapedContainerType TensorOf
  Pred predicate = anonymous_69;
  string summary = "tensor of 8-bit signless integer values";
  string cppClassName = "::mlir::TensorType";
  string description = "";
  string builderCall = "";
}
def Idempotent {	// Trait NativeTrait NativeOpTrait
  string trait = "IsIdempotent";
  string cppNamespace = "::mlir::OpTrait";
  code extraConcreteClassDeclaration = [{}];
  code extraConcreteClassDefinition = [{}];
  list<Trait> dependentTraits = [];
}
def Index {	// Constraint TypeConstraint Type BuildableType
  Pred predicate = anonymous_32;
  string summary = "index";
  string cppClassName = "::mlir::IndexType";
  string description = "";
  string builderCall = "$_builder.getIndexType()";
}
def IndexAttr {	// Constraint AttrConstraint Attr TypedAttrBase
  Pred predicate = anonymous_193;
  string summary = "index attribute";
  string storageType = "::mlir::IntegerAttr";
  code returnType = [{ ::llvm::APInt }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = "$_builder.getIntegerAttr($_builder.getIndexType(), $0)";
  string defaultValue = ?;
  Type valueType = Index;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def IndexElementsAttr {	// Constraint AttrConstraint Attr ElementsAttrBase IntElementsAttrBase
  Pred predicate = anonymous_256;
  string summary = "index elements attribute";
  code storageType = [{ ::mlir::DenseIntElementsAttr }];
  code returnType = [{ ::mlir::DenseIntElementsAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = ?;
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def IndexListArrayAttr {	// Constraint AttrConstraint Attr ArrayAttrBase TypedArrayAttrBase
  Pred predicate = anonymous_301;
  string summary = "Array of 64-bit integer array attributes";
  code storageType = [{ ::mlir::ArrayAttr }];
  code returnType = [{ ::mlir::ArrayAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = "$_builder.getArrayAttr($0)";
  string defaultValue = ?;
  Type valueType = NoneType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
  Attr elementAttr = I64ArrayAttr;
}
def IndexTensor {	// Constraint TypeConstraint Type ShapedContainerType TensorOf
  Pred predicate = anonymous_89;
  string summary = "tensor of index values";
  string cppClassName = "::mlir::TensorType";
  string description = "";
  string builderCall = "";
}
def IntNonNegative {	// Constraint AttrConstraint
  Pred predicate = anonymous_316;
  string summary = "whose value is non-negative";
}
def IntPositive {	// Constraint AttrConstraint
  Pred predicate = anonymous_317;
  string summary = "whose value is positive";
}
def Involution {	// Trait NativeTrait NativeOpTrait
  string trait = "IsInvolution";
  string cppNamespace = "::mlir::OpTrait";
  code extraConcreteClassDeclaration = [{}];
  code extraConcreteClassDefinition = [{}];
  list<Trait> dependentTraits = [];
}
def IsBaseMemRefTypePred {	// Pred CPred
  string predExpr = "(::llvm::isa<::mlir::BaseMemRefType>($_self))";
}
def IsFixedVectorTypePred {	// Pred CPred
  code predExpr = [{(::llvm::isa<::mlir::VectorType>($_self) &&
                                  !::llvm::cast<VectorType>($_self).isScalable())}];
}
def IsMemRefTypePred {	// Pred CPred
  string predExpr = "(::llvm::isa<::mlir::MemRefType>($_self))";
}
def IsNullAttr {	// Constraint AttrConstraint
  Pred predicate = anonymous_318;
  string summary = "empty attribute (for optional attributes)";
}
def IsRankedTensorTypePred {	// Pred CPred
  string predExpr = "(::llvm::isa<::mlir::RankedTensorType>($_self))";
}
def IsShapedTypePred {	// Pred CPred
  string predExpr = "(::llvm::isa<::mlir::ShapedType>($_self))";
}
def IsTensorTypePred {	// Pred CPred
  string predExpr = "(::llvm::isa<::mlir::TensorType>($_self))";
}
def IsTupleTypePred {	// Pred CPred
  string predExpr = "(::llvm::isa<::mlir::TupleType>($_self))";
}
def IsUnrankedMemRefTypePred {	// Pred CPred
  string predExpr = "(::llvm::isa<::mlir::UnrankedMemRefType>($_self))";
}
def IsUnrankedTensorTypePred {	// Pred CPred
  string predExpr = "(::llvm::isa<::mlir::UnrankedTensorType>($_self))";
}
def IsVectorOfAnyRankTypePred {	// Pred CPred
  string predExpr = "(::llvm::isa<::mlir::VectorType>($_self))";
}
def IsVectorTypePred {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_0, anonymous_1];
}
def IsVectorTypeWithAllDimsScalablePred {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsVectorTypePred, anonymous_4];
}
def IsVectorTypeWithAnyDimScalablePred {	// Pred CPred
  code predExpr = [{(::llvm::isa<::mlir::VectorType>($_self) &&
                  ::llvm::cast<VectorType>($_self).isScalable())}];
}
def IsVectorTypeWithOnlyTrailingDimScalablePred {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_0, anonymous_1, anonymous_2, anonymous_3];
}
def IsolatedFromAbove {	// Trait NativeTrait NativeOpTrait
  string trait = "IsIsolatedFromAbove";
  string cppNamespace = "::mlir::OpTrait";
  code extraConcreteClassDeclaration = [{}];
  code extraConcreteClassDefinition = [{}];
  list<Trait> dependentTraits = [];
}
def LocationArrayAttr {	// Constraint AttrConstraint Attr ArrayAttrBase TypedArrayAttrBase
  Pred predicate = anonymous_274;
  string summary = "location array attribute";
  code storageType = [{ ::mlir::ArrayAttr }];
  code returnType = [{ ::mlir::ArrayAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = "$_builder.getArrayAttr($0)";
  string defaultValue = ?;
  Type valueType = NoneType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
  Attr elementAttr = LocationAttr;
}
def LocationAttr {	// Constraint AttrConstraint Attr
  Pred predicate = anonymous_189;
  string summary = "location attribute";
  string storageType = ?;
  string returnType = ?;
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = ?;
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def MemAlloc {	// OpVariableDecorator SideEffect MemoryEffect MemAlloc
  string baseEffectName = "::mlir::MemoryEffects::Effect";
  string interfaceTrait = "MemoryEffectOpInterface::Trait";
  string cppNamespace = "::mlir";
  string effect = "::mlir::MemoryEffects::Allocate";
  string resource = "::mlir::SideEffects::DefaultResource";
  int stage = 0;
  bit effectOnFullRegion = 0;
}
def MemFree {	// OpVariableDecorator SideEffect MemoryEffect MemFree
  string baseEffectName = "::mlir::MemoryEffects::Effect";
  string interfaceTrait = "MemoryEffectOpInterface::Trait";
  string cppNamespace = "::mlir";
  string effect = "::mlir::MemoryEffects::Free";
  string resource = "::mlir::SideEffects::DefaultResource";
  int stage = 0;
  bit effectOnFullRegion = 0;
}
def MemRead {	// OpVariableDecorator SideEffect MemoryEffect MemRead
  string baseEffectName = "::mlir::MemoryEffects::Effect";
  string interfaceTrait = "MemoryEffectOpInterface::Trait";
  string cppNamespace = "::mlir";
  string effect = "::mlir::MemoryEffects::Read";
  string resource = "::mlir::SideEffects::DefaultResource";
  int stage = 0;
  bit effectOnFullRegion = 0;
}
def MemRefsNormalizable {	// Trait NativeTrait NativeOpTrait
  string trait = "MemRefsNormalizable";
  string cppNamespace = "::mlir::OpTrait";
  code extraConcreteClassDeclaration = [{}];
  code extraConcreteClassDefinition = [{}];
  list<Trait> dependentTraits = [];
}
def MemWrite {	// OpVariableDecorator SideEffect MemoryEffect MemWrite
  string baseEffectName = "::mlir::MemoryEffects::Effect";
  string interfaceTrait = "MemoryEffectOpInterface::Trait";
  string cppNamespace = "::mlir";
  string effect = "::mlir::MemoryEffects::Write";
  string resource = "::mlir::SideEffects::DefaultResource";
  int stage = 0;
  bit effectOnFullRegion = 0;
}
def MemoryEffectsOpInterface {	// Interface Trait NativeTrait InterfaceTrait OpInterfaceTrait OpInterface EffectOpInterfaceBase
  code description = [{
    An interface used to query information about the memory effects applied by
    an operation.
  }];
  string cppInterfaceName = "MemoryEffectOpInterface";
  string cppNamespace = "::mlir";
  list<InterfaceMethod> methods = [anonymous_359];
  code extraClassDeclaration = [{
    /// Collect all of the effect instances that correspond to the given
    /// `Effect` and place them in 'effects'.
    template <typename Effect> void getEffects(
      ::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<
                                              ::mlir::MemoryEffects::Effect>> &effects) {
      getEffects(effects);
      ::llvm::erase_if(effects, [&](auto &it) {
        return !::llvm::isa<Effect>(it.getEffect());
      });
    }

    /// Returns true if this operation exhibits the given effect.
    template <typename Effect> bool hasEffect() {
      ::llvm::SmallVector<::mlir::SideEffects::EffectInstance<
                                            ::mlir::MemoryEffects::Effect>, 4> effects;
      getEffects(effects);
      return ::llvm::any_of(effects, [](const auto &it) {
        return ::llvm::isa<Effect>(it.getEffect());
      });
    }

    /// Returns true if this operation only has the given effect.
    template <typename Effect> bool onlyHasEffect() {
      ::llvm::SmallVector<::mlir::SideEffects::EffectInstance<
                                            ::mlir::MemoryEffects::Effect>, 4> effects;
      getEffects(effects);
      return !effects.empty() && ::llvm::all_of(effects, [](const auto &it) {
        return ::llvm::isa<Effect>(it.getEffect());
      });
    }

    /// Returns true if this operation has no effects.
    bool hasNoEffect() {
      ::llvm::SmallVector<::mlir::SideEffects::EffectInstance<
                                            ::mlir::MemoryEffects::Effect>, 4> effects;
      getEffects(effects);
      return effects.empty();
    }

    /// Collect all of the effect instances that operate on the provided value
    /// and place them in 'effects'.
    void getEffectsOnValue(::mlir::Value value,
              ::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<
              ::mlir::MemoryEffects::Effect>> & effects) {
      getEffects(effects);
      ::llvm::erase_if(effects, [&](auto &it) { return it.getValue() != value; });
    }

    /// Return the effect of the given type `Effect` that is applied to the
    /// given value, or std::nullopt if no effect exists.
    template <typename Effect>
    ::std::optional<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>>
    getEffectOnValue(::mlir::Value value) {
      ::llvm::SmallVector<::mlir::SideEffects::EffectInstance<
              ::mlir::MemoryEffects::Effect>, 4> effects;
      getEffects(effects);
      auto it = ::llvm::find_if(effects, [&](auto &it) {
        return ::llvm::isa<Effect>(it.getEffect()) && it.getValue() == value;
      });
      if (it == effects.end())
        return std::nullopt;
      return *it;
    }

    /// Collect all of the effect instances that operate on the provided symbol
    /// reference and place them in 'effects'.
    void getEffectsOnSymbol(::mlir::SymbolRefAttr value,
              ::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<
              ::mlir::MemoryEffects::Effect>> & effects) {
      getEffects(effects);
      ::llvm::erase_if(effects, [&](auto &it) {
        return it.getSymbolRef() != value;
      });
    }

    /// Collect all of the effect instances that operate on the provided
    /// resource and place them in 'effects'.
    void getEffectsOnResource(::mlir::SideEffects::Resource *resource,
              ::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<
              ::mlir::MemoryEffects::Effect>> & effects) {
      getEffects(effects);
      ::llvm::erase_if(effects, [&](auto &it) {
        return it.getResource() != resource;
      });
    }
  }];
  string extraSharedClassDeclaration = "";
  string extraClassOf = "";
  list<Interface> baseInterfaces = [];
  string trait = "MemoryEffectOpInterface::Trait";
  code extraConcreteClassDeclaration = [{}];
  code extraConcreteClassDefinition = [{}];
  string extraTraitClassDeclaration = "";
  code verify = [{}];
  bit verifyWithRegions = 0;
  list<Trait> dependentTraits = [];
  string baseEffectName = "::mlir::MemoryEffects::Effect";
}
def NoMemoryEffect {	// Trait NativeTrait InterfaceTrait OpInterfaceTrait SideEffectsTraitBase MemoryEffects
  string trait = "MemoryEffectOpInterface::Trait";
  string cppNamespace = "::mlir";
  code extraConcreteClassDeclaration = [{}];
  code extraConcreteClassDefinition = [{}];
  string extraTraitClassDeclaration = "";
  code verify = [{}];
  bit verifyWithRegions = 0;
  list<Trait> dependentTraits = [];
  string baseEffectName = "::mlir::MemoryEffects::Effect";
  list<SideEffect> effects = [];
}
def NoRegionArguments {	// Trait NativeTrait NativeOpTrait StructuralOpTrait
  string trait = "NoRegionArguments";
  string cppNamespace = "::mlir::OpTrait";
  code extraConcreteClassDeclaration = [{}];
  code extraConcreteClassDefinition = [{}];
  list<Trait> dependentTraits = [];
}
def NoTerminator {	// Trait NativeTrait NativeOpTrait StructuralOpTrait
  string trait = "NoTerminator";
  string cppNamespace = "::mlir::OpTrait";
  code extraConcreteClassDeclaration = [{}];
  code extraConcreteClassDefinition = [{}];
  list<Trait> dependentTraits = [];
}
def NoneType {	// Constraint TypeConstraint Type BuildableType
  Pred predicate = anonymous_6;
  string summary = "none type";
  string cppClassName = "::mlir::NoneType";
  string description = "";
  string builderCall = "$_builder.getType<::mlir::NoneType>()";
}
def PartialEffect {	// EffectRange
  bits<1> Value = { 0 };
}
def Petite_DatabaseTableOp {	// Op Petite_Op
  Dialect opDialect = Petite_Dialect;
  string opName = "database_table";
  string cppNamespace = "::mlir::petite";
  string summary = "Database table operation";
  code description = [{
    Database table operation stores a 2D floating-point tensor in the database. The data is
    attached to the operation as an attribute. For example:

    ```mlir
      %0 = petite.database_table dense<[[1.0, 2.0], [3.0, 4.0]]> : tensor<*xf64>
    ```
  }];
  OpDocGroup opDocGroup = ?;
  dag arguments = (ins);
  dag results = (outs F64Tensor:$result);
  dag regions = (region);
  dag successors = (successor);
  list<OpBuilder> builders = [anonymous_361];
  bit skipDefaultBuilders = 0;
  string assemblyFormat = ?;
  bit hasCustomAssemblyFormat = 1;
  bit hasVerifier = 1;
  bit hasRegionVerifier = 0;
  bit hasCanonicalizer = 0;
  bit hasCanonicalizeMethod = 0;
  bit hasFolder = 0;
  bit useCustomPropertiesEncoding = 0;
  list<Trait> traits = [Pure];
  string extraClassDeclaration = ?;
  string extraClassDefinition = ?;
}
def Petite_Dialect {	// Dialect
  string name = "petite";
  string summary = ?;
  string description = ?;
  list<string> dependentDialects = [];
  dag discardableAttrs = (ins);
  string cppNamespace = "::mlir::petite";
  string extraClassDeclaration = "";
  bit hasConstantMaterializer = 0;
  bit hasNonDefaultDestructor = 0;
  bit hasOperationAttrVerify = 0;
  bit hasRegionArgAttrVerify = 0;
  bit hasRegionResultAttrVerify = 0;
  bit hasOperationInterfaceFallback = 0;
  bit useDefaultAttributePrinterParser = 0;
  bit useDefaultTypePrinterParser = 0;
  bit hasCanonicalizer = 0;
  bit isExtensible = 0;
  bit usePropertiesForAttributes = 1;
}
def PredCombinerAnd {	// PredCombinerKind
}
def PredCombinerConcat {	// PredCombinerKind
}
def PredCombinerNot {	// PredCombinerKind
}
def PredCombinerOr {	// PredCombinerKind
}
def PredCombinerSubstLeaves {	// PredCombinerKind
}
def Pure {	// Trait TraitList
  list<Trait> traits = [AlwaysSpeculatable, NoMemoryEffect];
}
def RecursiveMemoryEffects {	// Trait NativeTrait NativeOpTrait
  string trait = "HasRecursiveMemoryEffects";
  string cppNamespace = "::mlir::OpTrait";
  code extraConcreteClassDeclaration = [{}];
  code extraConcreteClassDefinition = [{}];
  list<Trait> dependentTraits = [];
}
def RecursivelySpeculatable {	// Trait TraitList
  list<Trait> traits = [ConditionallySpeculatable, RecursivelySpeculatableImplTrait];
}
def RecursivelySpeculatableImplTrait {	// Trait NativeTrait NativeOpTrait
  string trait = "RecursivelySpeculatableImplTrait";
  string cppNamespace = "::mlir::OpTrait";
  code extraConcreteClassDeclaration = [{}];
  code extraConcreteClassDefinition = [{}];
  list<Trait> dependentTraits = [];
}
def ResultsAreFloatLike {	// Trait NativeTrait NativeOpTrait
  string trait = "ResultsAreFloatLike";
  string cppNamespace = "::mlir::OpTrait";
  code extraConcreteClassDeclaration = [{}];
  code extraConcreteClassDefinition = [{}];
  list<Trait> dependentTraits = [];
}
def ResultsBroadcastableShape {	// Trait NativeTrait NativeOpTrait
  string trait = "ResultsBroadcastableShape";
  string cppNamespace = "::mlir::OpTrait";
  code extraConcreteClassDeclaration = [{}];
  code extraConcreteClassDefinition = [{}];
  list<Trait> dependentTraits = [];
}
def SI1 {	// Constraint TypeConstraint Type BuildableType SI
  Pred predicate = anonymous_21;
  string summary = "1-bit signed integer";
  string cppClassName = "::mlir::IntegerType";
  string description = "";
  string builderCall = "$_builder.getIntegerType(1, /*isSigned=*/true)";
  int bitwidth = 1;
}
def SI16 {	// Constraint TypeConstraint Type BuildableType SI
  Pred predicate = anonymous_23;
  string summary = "16-bit signed integer";
  string cppClassName = "::mlir::IntegerType";
  string description = "";
  string builderCall = "$_builder.getIntegerType(16, /*isSigned=*/true)";
  int bitwidth = 16;
}
def SI16Attr {	// Constraint AttrConstraint Attr TypedAttrBase SignedIntegerAttrBase TypedSignedIntegerAttrBase
  Pred predicate = anonymous_219;
  string summary = "16-bit signed integer attribute";
  string storageType = "::mlir::IntegerAttr";
  string returnType = "int16_t";
  string convertFromStorage = "$_self.getValue().getSExtValue()";
  string constBuilderCall = "$_builder.getIntegerAttr($_builder.getIntegerType(16, /*isSigned=*/true), $0)";
  string defaultValue = ?;
  Type valueType = SI16;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def SI1Attr {	// Constraint AttrConstraint Attr TypedAttrBase SignedIntegerAttrBase TypedSignedIntegerAttrBase
  Pred predicate = anonymous_215;
  string summary = "1-bit signed integer attribute";
  string storageType = "::mlir::IntegerAttr";
  string returnType = "bool";
  string convertFromStorage = "$_self.getValue().getSExtValue()";
  string constBuilderCall = "$_builder.getIntegerAttr($_builder.getIntegerType(1, /*isSigned=*/true), $0)";
  string defaultValue = ?;
  Type valueType = SI1;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def SI32 {	// Constraint TypeConstraint Type BuildableType SI
  Pred predicate = anonymous_24;
  string summary = "32-bit signed integer";
  string cppClassName = "::mlir::IntegerType";
  string description = "";
  string builderCall = "$_builder.getIntegerType(32, /*isSigned=*/true)";
  int bitwidth = 32;
}
def SI32Attr {	// Constraint AttrConstraint Attr TypedAttrBase SignedIntegerAttrBase TypedSignedIntegerAttrBase
  Pred predicate = anonymous_221;
  string summary = "32-bit signed integer attribute";
  string storageType = "::mlir::IntegerAttr";
  string returnType = "int32_t";
  string convertFromStorage = "$_self.getValue().getSExtValue()";
  string constBuilderCall = "$_builder.getIntegerAttr($_builder.getIntegerType(32, /*isSigned=*/true), $0)";
  string defaultValue = ?;
  Type valueType = SI32;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def SI64 {	// Constraint TypeConstraint Type BuildableType SI
  Pred predicate = anonymous_25;
  string summary = "64-bit signed integer";
  string cppClassName = "::mlir::IntegerType";
  string description = "";
  string builderCall = "$_builder.getIntegerType(64, /*isSigned=*/true)";
  int bitwidth = 64;
}
def SI64Attr {	// Constraint AttrConstraint Attr TypedAttrBase SignedIntegerAttrBase TypedSignedIntegerAttrBase
  Pred predicate = anonymous_223;
  string summary = "64-bit signed integer attribute";
  string storageType = "::mlir::IntegerAttr";
  string returnType = "int64_t";
  string convertFromStorage = "$_self.getValue().getSExtValue()";
  string constBuilderCall = "$_builder.getIntegerAttr($_builder.getIntegerType(64, /*isSigned=*/true), $0)";
  string defaultValue = ?;
  Type valueType = SI64;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def SI8 {	// Constraint TypeConstraint Type BuildableType SI
  Pred predicate = anonymous_22;
  string summary = "8-bit signed integer";
  string cppClassName = "::mlir::IntegerType";
  string description = "";
  string builderCall = "$_builder.getIntegerType(8, /*isSigned=*/true)";
  int bitwidth = 8;
}
def SI8Attr {	// Constraint AttrConstraint Attr TypedAttrBase SignedIntegerAttrBase TypedSignedIntegerAttrBase
  Pred predicate = anonymous_217;
  string summary = "8-bit signed integer attribute";
  string storageType = "::mlir::IntegerAttr";
  string returnType = "int8_t";
  string convertFromStorage = "$_self.getValue().getSExtValue()";
  string constBuilderCall = "$_builder.getIntegerAttr($_builder.getIntegerType(8, /*isSigned=*/true), $0)";
  string defaultValue = ?;
  Type valueType = SI8;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def SameOperandsAndResultElementType {	// Trait NativeTrait NativeOpTrait
  string trait = "SameOperandsAndResultElementType";
  string cppNamespace = "::mlir::OpTrait";
  code extraConcreteClassDeclaration = [{}];
  code extraConcreteClassDefinition = [{}];
  list<Trait> dependentTraits = [];
}
def SameOperandsAndResultShape {	// Trait NativeTrait NativeOpTrait
  string trait = "SameOperandsAndResultShape";
  string cppNamespace = "::mlir::OpTrait";
  code extraConcreteClassDeclaration = [{}];
  code extraConcreteClassDefinition = [{}];
  list<Trait> dependentTraits = [];
}
def SameOperandsElementType {	// Trait NativeTrait NativeOpTrait
  string trait = "SameOperandsElementType";
  string cppNamespace = "::mlir::OpTrait";
  code extraConcreteClassDeclaration = [{}];
  code extraConcreteClassDefinition = [{}];
  list<Trait> dependentTraits = [];
}
def SameOperandsShape {	// Trait NativeTrait NativeOpTrait
  string trait = "SameOperandsShape";
  string cppNamespace = "::mlir::OpTrait";
  code extraConcreteClassDeclaration = [{}];
  code extraConcreteClassDefinition = [{}];
  list<Trait> dependentTraits = [];
}
def SameTypeOperands {	// Trait NativeTrait NativeOpTrait
  string trait = "SameTypeOperands";
  string cppNamespace = "::mlir::OpTrait";
  code extraConcreteClassDeclaration = [{}];
  code extraConcreteClassDefinition = [{}];
  list<Trait> dependentTraits = [];
}
def SameVariadicOperandSize {	// Trait GenInternalTrait GenInternalOpTrait
  string trait = "::mlir::OpTrait::SameVariadicOperandSize";
  list<Trait> dependentTraits = [];
}
def SameVariadicResultSize {	// Trait GenInternalTrait GenInternalOpTrait
  string trait = "::mlir::OpTrait::SameVariadicResultSize";
  list<Trait> dependentTraits = [];
}
def Scalarizable {	// Trait NativeTrait NativeOpTrait
  string trait = "Scalarizable";
  string cppNamespace = "::mlir::OpTrait";
  code extraConcreteClassDeclaration = [{}];
  code extraConcreteClassDefinition = [{}];
  list<Trait> dependentTraits = [Elementwise];
}
def ScanOp {	// Op Petite_Op
  Dialect opDialect = Petite_Dialect;
  string opName = "scan";
  string cppNamespace = "::mlir::petite";
  string summary = "Scan a table from the database";
  code description = [{
    The "scan" operation retrieves a table from the database by its name.
  }];
  OpDocGroup opDocGroup = ?;
  dag arguments = (ins StrAttr:$table_name);
  dag results = (outs TableType:$result);
  dag regions = (region);
  dag successors = (successor);
  list<OpBuilder> builders = [anonymous_362];
  bit skipDefaultBuilders = 0;
  string assemblyFormat = ?;
  bit hasCustomAssemblyFormat = 1;
  bit hasVerifier = 0;
  bit hasRegionVerifier = 0;
  bit hasCanonicalizer = 0;
  bit hasCanonicalizeMethod = 0;
  bit hasFolder = 0;
  bit useCustomPropertiesEncoding = 0;
  list<Trait> traits = [Pure];
  string extraClassDeclaration = ?;
  string extraClassDefinition = ?;
}
def SelectOp {	// Op Petite_Op
  Dialect opDialect = Petite_Dialect;
  string opName = "select";
  string cppNamespace = "::mlir::petite";
  string summary = "Select rows from a table based on conditions";
  code description = [{
    The "select" operation retrieves rows from a table that match specific conditions.
  }];
  OpDocGroup opDocGroup = ?;
  dag arguments = (ins TableType:$table, ArrayAttr:$conditions);
  dag results = (outs TableType:$result);
  dag regions = (region);
  dag successors = (successor);
  list<OpBuilder> builders = [anonymous_363];
  bit skipDefaultBuilders = 0;
  string assemblyFormat = ?;
  bit hasCustomAssemblyFormat = 1;
  bit hasVerifier = 0;
  bit hasRegionVerifier = 0;
  bit hasCanonicalizer = 0;
  bit hasCanonicalizeMethod = 0;
  bit hasFolder = 0;
  bit useCustomPropertiesEncoding = 0;
  list<Trait> traits = [Pure];
  string extraClassDeclaration = ?;
  string extraClassDefinition = ?;
}
def SignlessIntegerLike {	// Constraint TypeConstraint TypeOrContainer
  Pred predicate = anonymous_175;
  string summary = "signless-integer-like";
  string cppClassName = "::mlir::Type";
}
def SignlessIntegerLikeOfAnyRank {	// Constraint TypeConstraint TypeOrContainerOfAnyRank
  Pred predicate = anonymous_178;
  string summary = "signless-integer-like";
  string cppClassName = "::mlir::Type";
}
def SignlessIntegerOrFloatLike {	// Constraint TypeConstraint
  Pred predicate = anonymous_188;
  string summary = "signless-integer-like or floating-point-like";
  string cppClassName = "::mlir::Type";
}
def SingleBlock {	// Trait NativeTrait NativeOpTrait StructuralOpTrait
  string trait = "SingleBlock";
  string cppNamespace = "::mlir::OpTrait";
  code extraConcreteClassDeclaration = [{}];
  code extraConcreteClassDefinition = [{}];
  list<Trait> dependentTraits = [];
}
def StrArrayAttr {	// Constraint AttrConstraint Attr ArrayAttrBase TypedArrayAttrBase
  Pred predicate = anonymous_295;
  string summary = "string array attribute";
  code storageType = [{ ::mlir::ArrayAttr }];
  code returnType = [{ ::mlir::ArrayAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = "$_builder.getStrArrayAttr($0)";
  string defaultValue = ?;
  Type valueType = NoneType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
  Attr elementAttr = StrAttr;
}
def StrAttr {	// Constraint AttrConstraint Attr StringBasedAttr
  Pred predicate = anonymous_239;
  string summary = "string attribute";
  code storageType = [{ ::mlir::StringAttr }];
  code returnType = [{ ::llvm::StringRef }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = "$_builder.getStringAttr($0)";
  string defaultValue = ?;
  Type valueType = NoneType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def StringElementsAttr {	// Constraint AttrConstraint Attr ElementsAttrBase
  Pred predicate = anonymous_269;
  string summary = "string elements attribute";
  code storageType = [{ ::mlir::DenseElementsAttr }];
  code returnType = [{ ::mlir::DenseElementsAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = ?;
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def Symbol {	// Interface Trait NativeTrait InterfaceTrait OpInterfaceTrait OpInterface
  code description = [{
    This interface describes an operation that may define a `Symbol`. A `Symbol`
    operation resides immediately within a region that defines a `SymbolTable`.
    See [Symbols and SymbolTables](../SymbolsAndSymbolTables.md) for more details
    and constraints on `Symbol` operations.
  }];
  string cppInterfaceName = "SymbolOpInterface";
  string cppNamespace = "::mlir";
  list<InterfaceMethod> methods = [anonymous_324, anonymous_325, anonymous_326, anonymous_327, anonymous_328, anonymous_329, anonymous_330, anonymous_331, anonymous_332, anonymous_333, anonymous_334, anonymous_335, anonymous_336, anonymous_337, anonymous_338, anonymous_339];
  string extraClassDeclaration = "";
  code extraSharedClassDeclaration = [{
    using Visibility = mlir::SymbolTable::Visibility;

    /// Convenience version of `getNameAttr` that returns a StringRef.
    ::mlir::StringRef getName() {
      return getNameAttr().getValue();
    }

    /// Convenience version of `setName` that take a StringRef.
    void setName(::mlir::StringRef name) {
      setName(::mlir::StringAttr::get($_op->getContext(), name));
    }
  }];
  code extraClassOf = [{
    return $_op->hasAttr(::mlir::SymbolTable::getSymbolAttrName());
  }];
  list<Interface> baseInterfaces = [];
  string trait = "SymbolOpInterface::Trait";
  code extraConcreteClassDeclaration = [{}];
  code extraConcreteClassDefinition = [{}];
  string extraTraitClassDeclaration = "";
  code verify = [{
    // If this is an optional symbol, bail out early if possible.
    auto concreteOp = cast<ConcreteOp>($_op);
    if (concreteOp.isOptionalSymbol()) {
      if(!concreteOp->getInherentAttr(::mlir::SymbolTable::getSymbolAttrName()).value_or(Attribute{}))
        return success();
    }
    if (::mlir::failed(::mlir::detail::verifySymbol($_op)))
      return ::mlir::failure();
    if (concreteOp.isDeclaration() && concreteOp.isPublic())
      return concreteOp.emitOpError("symbol declaration cannot have public "
             "visibility");
    auto parent = $_op->getParentOp();
    if (parent && !parent->hasTrait<OpTrait::SymbolTable>() && parent->isRegistered()) {
      return concreteOp.emitOpError("symbol's parent must have the SymbolTable "
             "trait");
    }
    return success();
  }];
  bit verifyWithRegions = 0;
  list<Trait> dependentTraits = [];
}
def SymbolNameAttr {	// Constraint AttrConstraint Attr StringBasedAttr
  Pred predicate = anonymous_239;
  string summary = "string attribute";
  code storageType = [{ ::mlir::StringAttr }];
  code returnType = [{ ::llvm::StringRef }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = "$_builder.getStringAttr($0)";
  string defaultValue = ?;
  Type valueType = NoneType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def SymbolRefArrayAttr {	// Constraint AttrConstraint Attr ArrayAttrBase TypedArrayAttrBase
  Pred predicate = anonymous_309;
  string summary = "symbol ref array attribute";
  code storageType = [{ ::mlir::ArrayAttr }];
  code returnType = [{ ::mlir::ArrayAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = ?;
  string defaultValue = ?;
  Type valueType = NoneType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
  Attr elementAttr = SymbolRefAttr;
}
def SymbolRefAttr {	// Constraint AttrConstraint Attr
  Pred predicate = anonymous_305;
  string summary = "symbol reference attribute";
  code storageType = [{ ::mlir::SymbolRefAttr }];
  code returnType = [{ ::mlir::SymbolRefAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = "::mlir::SymbolRefAttr::get($_builder.getContext(), $0)";
  string defaultValue = ?;
  Type valueType = NoneType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def SymbolTable {	// Trait NativeTrait NativeOpTrait
  string trait = "SymbolTable";
  string cppNamespace = "::mlir::OpTrait";
  code extraConcreteClassDeclaration = [{}];
  code extraConcreteClassDefinition = [{}];
  list<Trait> dependentTraits = [];
}
def SymbolUserOpInterface {	// Interface Trait NativeTrait InterfaceTrait OpInterfaceTrait OpInterface
  code description = [{
    This interface describes an operation that may use a `Symbol`. This
    interface allows for users of symbols to hook into verification and other
    symbol related utilities that are either costly or otherwise disallowed
    within a traditional operation.
  }];
  string cppInterfaceName = "SymbolUserOpInterface";
  string cppNamespace = "::mlir";
  list<InterfaceMethod> methods = [anonymous_340];
  string extraClassDeclaration = "";
  string extraSharedClassDeclaration = "";
  string extraClassOf = "";
  list<Interface> baseInterfaces = [];
  string trait = "SymbolUserOpInterface::Trait";
  code extraConcreteClassDeclaration = [{}];
  code extraConcreteClassDefinition = [{}];
  string extraTraitClassDeclaration = "";
  code verify = [{}];
  bit verifyWithRegions = 0;
  list<Trait> dependentTraits = [];
}
def TF32 {	// Constraint TypeConstraint Type BuildableType
  Pred predicate = anonymous_41;
  string summary = "tf32 type";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "$_builder.getTF32Type()";
}
def TableType {	// AttrOrTypeDef
  string cppBaseClassName = "Type::TypeBase<TableType, Type, TypeStorage>";
  code description = [{
    This type represents a table in the database.
  }];
  string storageClass = "TableTypeStorage";
  string storageNamespace = "detail";
  bit genStorageClass = 1;
  bit hasStorageCustomConstructor = 0;
  dag parameters = (ins);
  list<AttrOrTypeBuilder> builders = ?;
  list<Trait> traits = [];
  string mnemonic = ?;
  string assemblyFormat = ?;
  bit hasCustomAssemblyFormat = 0;
  bit genAccessors = 1;
  bit skipDefaultBuilders = 0;
  bit genVerifyDecl = 0;
  code extraClassDeclaration = [{}];
  code extraClassDefinition = [{}];
}
def Tensorizable {	// Trait NativeTrait NativeOpTrait
  string trait = "Tensorizable";
  string cppNamespace = "::mlir::OpTrait";
  code extraConcreteClassDeclaration = [{}];
  code extraConcreteClassDefinition = [{}];
  list<Trait> dependentTraits = [Elementwise];
}
def Terminator {	// Trait NativeTrait NativeOpTrait
  string trait = "IsTerminator";
  string cppNamespace = "::mlir::OpTrait";
  code extraConcreteClassDeclaration = [{}];
  code extraConcreteClassDefinition = [{}];
  list<Trait> dependentTraits = [];
}
def TypeArrayAttr {	// Constraint AttrConstraint Attr ArrayAttrBase TypedArrayAttrBase
  Pred predicate = anonymous_298;
  string summary = "type array attribute";
  code storageType = [{ ::mlir::ArrayAttr }];
  code returnType = [{ ::mlir::ArrayAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = "$_builder.getTypeArrayAttr($0)";
  string defaultValue = ?;
  Type valueType = NoneType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
  Attr elementAttr = TypeAttr;
}
def TypeAttr {	// Constraint AttrConstraint Attr TypeAttrBase
  Pred predicate = anonymous_243;
  string summary = "any type attribute";
  code storageType = [{ ::mlir::TypeAttr }];
  string returnType = "::mlir::Type";
  string convertFromStorage = "::llvm::cast<::mlir::Type>($_self.getValue())";
  string constBuilderCall = "::mlir::TypeAttr::get($0)";
  string defaultValue = ?;
  Type valueType = NoneType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def UI1 {	// Constraint TypeConstraint Type BuildableType UI
  Pred predicate = anonymous_27;
  string summary = "1-bit unsigned integer";
  string cppClassName = "::mlir::IntegerType";
  string description = "";
  string builderCall = "$_builder.getIntegerType(1, /*isSigned=*/false)";
  int bitwidth = 1;
}
def UI16 {	// Constraint TypeConstraint Type BuildableType UI
  Pred predicate = anonymous_29;
  string summary = "16-bit unsigned integer";
  string cppClassName = "::mlir::IntegerType";
  string description = "";
  string builderCall = "$_builder.getIntegerType(16, /*isSigned=*/false)";
  int bitwidth = 16;
}
def UI16Attr {	// Constraint AttrConstraint Attr TypedAttrBase UnsignedIntegerAttrBase TypedUnsignedIntegerAttrBase
  Pred predicate = anonymous_229;
  string summary = "16-bit unsigned integer attribute";
  string storageType = "::mlir::IntegerAttr";
  string returnType = "uint16_t";
  string convertFromStorage = "$_self.getValue().getZExtValue()";
  string constBuilderCall = "$_builder.getIntegerAttr($_builder.getIntegerType(16, /*isSigned=*/false), $0)";
  string defaultValue = ?;
  Type valueType = UI16;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def UI1Attr {	// Constraint AttrConstraint Attr TypedAttrBase UnsignedIntegerAttrBase TypedUnsignedIntegerAttrBase
  Pred predicate = anonymous_225;
  string summary = "1-bit unsigned integer attribute";
  string storageType = "::mlir::IntegerAttr";
  string returnType = "bool";
  string convertFromStorage = "$_self.getValue().getZExtValue()";
  string constBuilderCall = "$_builder.getIntegerAttr($_builder.getIntegerType(1, /*isSigned=*/false), $0)";
  string defaultValue = ?;
  Type valueType = UI1;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def UI32 {	// Constraint TypeConstraint Type BuildableType UI
  Pred predicate = anonymous_30;
  string summary = "32-bit unsigned integer";
  string cppClassName = "::mlir::IntegerType";
  string description = "";
  string builderCall = "$_builder.getIntegerType(32, /*isSigned=*/false)";
  int bitwidth = 32;
}
def UI32Attr {	// Constraint AttrConstraint Attr TypedAttrBase UnsignedIntegerAttrBase TypedUnsignedIntegerAttrBase
  Pred predicate = anonymous_231;
  string summary = "32-bit unsigned integer attribute";
  string storageType = "::mlir::IntegerAttr";
  string returnType = "uint32_t";
  string convertFromStorage = "$_self.getValue().getZExtValue()";
  string constBuilderCall = "$_builder.getIntegerAttr($_builder.getIntegerType(32, /*isSigned=*/false), $0)";
  string defaultValue = ?;
  Type valueType = UI32;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def UI64 {	// Constraint TypeConstraint Type BuildableType UI
  Pred predicate = anonymous_31;
  string summary = "64-bit unsigned integer";
  string cppClassName = "::mlir::IntegerType";
  string description = "";
  string builderCall = "$_builder.getIntegerType(64, /*isSigned=*/false)";
  int bitwidth = 64;
}
def UI64Attr {	// Constraint AttrConstraint Attr TypedAttrBase UnsignedIntegerAttrBase TypedUnsignedIntegerAttrBase
  Pred predicate = anonymous_233;
  string summary = "64-bit unsigned integer attribute";
  string storageType = "::mlir::IntegerAttr";
  string returnType = "uint64_t";
  string convertFromStorage = "$_self.getValue().getZExtValue()";
  string constBuilderCall = "$_builder.getIntegerAttr($_builder.getIntegerType(64, /*isSigned=*/false), $0)";
  string defaultValue = ?;
  Type valueType = UI64;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def UI8 {	// Constraint TypeConstraint Type BuildableType UI
  Pred predicate = anonymous_28;
  string summary = "8-bit unsigned integer";
  string cppClassName = "::mlir::IntegerType";
  string description = "";
  string builderCall = "$_builder.getIntegerType(8, /*isSigned=*/false)";
  int bitwidth = 8;
}
def UI8Attr {	// Constraint AttrConstraint Attr TypedAttrBase UnsignedIntegerAttrBase TypedUnsignedIntegerAttrBase
  Pred predicate = anonymous_227;
  string summary = "8-bit unsigned integer attribute";
  string storageType = "::mlir::IntegerAttr";
  string returnType = "uint8_t";
  string convertFromStorage = "$_self.getValue().getZExtValue()";
  string constBuilderCall = "$_builder.getIntegerAttr($_builder.getIntegerType(8, /*isSigned=*/false), $0)";
  string defaultValue = ?;
  Type valueType = UI8;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def UnitAttr {	// Constraint AttrConstraint Attr
  Pred predicate = anonymous_244;
  string summary = "unit attribute";
  code storageType = [{ ::mlir::UnitAttr }];
  string returnType = "bool";
  string convertFromStorage = "$_self != nullptr";
  string constBuilderCall = "(($0) ? $_builder.getUnitAttr() : nullptr)";
  string defaultValue = "false";
  Type valueType = NoneType;
  bit isOptional = 1;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def Vectorizable {	// Trait NativeTrait NativeOpTrait
  string trait = "Vectorizable";
  string cppNamespace = "::mlir::OpTrait";
  code extraConcreteClassDeclaration = [{}];
  code extraConcreteClassDefinition = [{}];
  list<Trait> dependentTraits = [Elementwise];
}
def anonymous_0 {	// Pred CPred
  string predExpr = "(::llvm::isa<::mlir::VectorType>($_self))";
}
def anonymous_1 {	// Pred CPred
  string predExpr = "(::llvm::cast<::mlir::VectorType>($_self).getRank() > 0)";
}
def anonymous_10 {	// Pred CPred
  string predExpr = "($_self.isInteger(16))";
}
def anonymous_100 {	// Constraint TypeConstraint Type AnyTypeOf
  Pred predicate = anonymous_101;
  string summary = "32-bit float";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
  list<Type> allowedTypes = [F32];
}
def anonymous_101 {	// Pred CombinedPred Or
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = [anonymous_36];
}
def anonymous_102 {	// Pred CombinedPred SubstLeaves
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [anonymous_101];
  string pattern = "$_self";
  string replacement = "elementType";
}
def anonymous_103 {	// Pred CombinedPred Concat
  PredCombinerKind kind = PredCombinerConcat;
  list<Pred> children = [anonymous_102];
  string prefix = "[](::mlir::Type elementType) { return ";
  string suffix = "; }(::llvm::cast<::mlir::ShapedType>($_self).getElementType())";
}
def anonymous_104 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_58, anonymous_103];
}
def anonymous_105 {	// Constraint TypeConstraint Type AnyTypeOf
  Pred predicate = anonymous_106;
  string summary = "64-bit float";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
  list<Type> allowedTypes = [F64];
}
def anonymous_106 {	// Pred CombinedPred Or
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = [anonymous_37];
}
def anonymous_107 {	// Pred CombinedPred SubstLeaves
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [anonymous_106];
  string pattern = "$_self";
  string replacement = "elementType";
}
def anonymous_108 {	// Pred CombinedPred Concat
  PredCombinerKind kind = PredCombinerConcat;
  list<Pred> children = [anonymous_107];
  string prefix = "[](::mlir::Type elementType) { return ";
  string suffix = "; }(::llvm::cast<::mlir::ShapedType>($_self).getElementType())";
}
def anonymous_109 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_58, anonymous_108];
}
def anonymous_11 {	// Pred CPred
  string predExpr = "($_self.isInteger(32))";
}
def anonymous_110 {	// Pred CombinedPred And HasRankGreaterOrEqualPred
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [HasRankPred, anonymous_111];
}
def anonymous_111 {	// Pred CPred
  code predExpr = [{(::llvm::cast<::mlir::ShapedType>($_self).getRank() >= 1)}];
}
def anonymous_112 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsTensorTypePred, anonymous_110];
}
def anonymous_113 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsRankedTensorTypePred];
}
def anonymous_114 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_113, anonymous_52];
}
def anonymous_115 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_112, anonymous_52];
}
def anonymous_116 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsUnrankedTensorTypePred];
}
def anonymous_117 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_116, anonymous_52];
}
def anonymous_118 {	// Pred CombinedPred Or
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = [anonymous_117, anonymous_115];
}
def anonymous_119 {	// Pred CombinedPred And HasAnyRankOfPred
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [HasRankPred, anonymous_121];
}
def anonymous_12 {	// Pred CPred
  string predExpr = "($_self.isInteger(64))";
}
def anonymous_120 {	// Pred CPred
  code predExpr = [{(::llvm::cast<::mlir::ShapedType>($_self).getRank()
                         == 0)}];
}
def anonymous_121 {	// Pred CombinedPred Or
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = [anonymous_120];
}
def anonymous_122 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsRankedTensorTypePred, anonymous_119];
}
def anonymous_123 {	// Pred CombinedPred And HasAnyRankOfPred
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [HasRankPred, anonymous_125];
}
def anonymous_124 {	// Pred CPred
  code predExpr = [{(::llvm::cast<::mlir::ShapedType>($_self).getRank()
                         == 1)}];
}
def anonymous_125 {	// Pred CombinedPred Or
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = [anonymous_124];
}
def anonymous_126 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsRankedTensorTypePred, anonymous_123];
}
def anonymous_127 {	// Pred CombinedPred And HasAnyRankOfPred
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [HasRankPred, anonymous_129];
}
def anonymous_128 {	// Pred CPred
  code predExpr = [{(::llvm::cast<::mlir::ShapedType>($_self).getRank()
                         == 2)}];
}
def anonymous_129 {	// Pred CombinedPred Or
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = [anonymous_128];
}
def anonymous_13 {	// Pred CPred
  string predExpr = "($_self.isSignlessInteger())";
}
def anonymous_130 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsRankedTensorTypePred, anonymous_127];
}
def anonymous_131 {	// Pred CombinedPred And HasAnyRankOfPred
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [HasRankPred, anonymous_133];
}
def anonymous_132 {	// Pred CPred
  code predExpr = [{(::llvm::cast<::mlir::ShapedType>($_self).getRank()
                         == 3)}];
}
def anonymous_133 {	// Pred CombinedPred Or
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = [anonymous_132];
}
def anonymous_134 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsRankedTensorTypePred, anonymous_131];
}
def anonymous_135 {	// Pred CombinedPred And HasAnyRankOfPred
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [HasRankPred, anonymous_137];
}
def anonymous_136 {	// Pred CPred
  code predExpr = [{(::llvm::cast<::mlir::ShapedType>($_self).getRank()
                         == 4)}];
}
def anonymous_137 {	// Pred CombinedPred Or
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = [anonymous_136];
}
def anonymous_138 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsRankedTensorTypePred, anonymous_135];
}
def anonymous_139 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsRankedTensorTypePred, HasStaticShapePred];
}
def anonymous_14 {	// Pred CPred
  string predExpr = "($_self.isSignlessInteger(1))";
}
def anonymous_140 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_139, anonymous_52];
}
def anonymous_141 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsUnrankedMemRefTypePred, anonymous_52];
}
def anonymous_142 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsMemRefTypePred, anonymous_52];
}
def anonymous_143 {	// Constraint TypeConstraint Type ShapedContainerType MemRefOf
  Pred predicate = anonymous_142;
  string summary = "memref of any type values";
  string cppClassName = "::mlir::MemRefType";
  string description = "";
  string builderCall = "";
}
def anonymous_144 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_142, anonymous_110];
}
def anonymous_145 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsBaseMemRefTypePred];
}
def anonymous_146 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_145, anonymous_52];
}
def anonymous_147 {	// Pred CombinedPred Or
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = [anonymous_141, anonymous_144];
}
def anonymous_148 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsMemRefTypePred, anonymous_63];
}
def anonymous_149 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsMemRefTypePred, anonymous_68];
}
def anonymous_15 {	// Pred CPred
  string predExpr = "($_self.isSignlessInteger(8))";
}
def anonymous_150 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsMemRefTypePred, anonymous_73];
}
def anonymous_151 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsMemRefTypePred, anonymous_78];
}
def anonymous_152 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsMemRefTypePred, anonymous_83];
}
def anonymous_153 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsMemRefTypePred, anonymous_93];
}
def anonymous_154 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsMemRefTypePred, anonymous_98];
}
def anonymous_155 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsMemRefTypePred, anonymous_103];
}
def anonymous_156 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsMemRefTypePred, anonymous_108];
}
def anonymous_157 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_142, HasStaticShapePred];
}
def anonymous_158 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_142, HasStridesPred];
}
def anonymous_159 {	// Constraint TypeConstraint Type ShapedContainerType VectorOf
  Pred predicate = anonymous_161;
  string summary = "vector of 1-bit signless integer values";
  string cppClassName = "::mlir::VectorType";
  string description = "";
  string builderCall = "";
}
def anonymous_16 {	// Pred CPred
  string predExpr = "($_self.isSignlessInteger(16))";
}
def anonymous_160 {	// Constraint TypeConstraint Type AnyTypeOf
  Pred predicate = anonymous_61;
  string summary = "1-bit signless integer";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
  list<Type> allowedTypes = [I1];
}
def anonymous_161 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsVectorTypePred, anonymous_63];
}
def anonymous_162 {	// Constraint TypeConstraint Type ShapedContainerType TensorOf
  Pred predicate = anonymous_64;
  string summary = "tensor of 1-bit signless integer values";
  string cppClassName = "::mlir::TensorType";
  string description = "";
  string builderCall = "";
}
def anonymous_163 {	// Pred CombinedPred Or
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = [anonymous_14, anonymous_161, anonymous_64];
}
def anonymous_164 {	// Constraint TypeConstraint Type ShapedContainerType VectorOfAnyRankOf
  Pred predicate = anonymous_165;
  string summary = "vector of 1-bit signless integer values";
  string cppClassName = "::mlir::VectorType";
  string description = "";
  string builderCall = "";
}
def anonymous_165 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsVectorOfAnyRankTypePred, anonymous_63];
}
def anonymous_166 {	// Pred CombinedPred Or
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = [anonymous_14, anonymous_165, anonymous_64];
}
def anonymous_167 {	// Constraint TypeConstraint Type ShapedContainerType VectorOf
  Pred predicate = anonymous_172;
  string summary = "vector of signless integer or index values";
  string cppClassName = "::mlir::VectorType";
  string description = "";
  string builderCall = "";
}
def anonymous_168 {	// Constraint TypeConstraint Type AnyTypeOf
  Pred predicate = anonymous_169;
  string summary = "signless integer or index";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
  list<Type> allowedTypes = [AnySignlessIntegerOrIndex];
}
def anonymous_169 {	// Pred CombinedPred Or
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = [anonymous_33];
}
def anonymous_17 {	// Pred CPred
  string predExpr = "($_self.isSignlessInteger(32))";
}
def anonymous_170 {	// Pred CombinedPred SubstLeaves
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [anonymous_169];
  string pattern = "$_self";
  string replacement = "elementType";
}
def anonymous_171 {	// Pred CombinedPred Concat
  PredCombinerKind kind = PredCombinerConcat;
  list<Pred> children = [anonymous_170];
  string prefix = "[](::mlir::Type elementType) { return ";
  string suffix = "; }(::llvm::cast<::mlir::ShapedType>($_self).getElementType())";
}
def anonymous_172 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsVectorTypePred, anonymous_171];
}
def anonymous_173 {	// Constraint TypeConstraint Type ShapedContainerType TensorOf
  Pred predicate = anonymous_174;
  string summary = "tensor of signless integer or index values";
  string cppClassName = "::mlir::TensorType";
  string description = "";
  string builderCall = "";
}
def anonymous_174 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_58, anonymous_171];
}
def anonymous_175 {	// Pred CombinedPred Or
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = [anonymous_33, anonymous_172, anonymous_174];
}
def anonymous_176 {	// Constraint TypeConstraint Type ShapedContainerType VectorOfAnyRankOf
  Pred predicate = anonymous_177;
  string summary = "vector of signless integer or index values";
  string cppClassName = "::mlir::VectorType";
  string description = "";
  string builderCall = "";
}
def anonymous_177 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsVectorOfAnyRankTypePred, anonymous_171];
}
def anonymous_178 {	// Pred CombinedPred Or
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = [anonymous_33, anonymous_177, anonymous_174];
}
def anonymous_179 {	// Constraint TypeConstraint Type ShapedContainerType VectorOf
  Pred predicate = anonymous_184;
  string summary = "vector of floating-point values";
  string cppClassName = "::mlir::VectorType";
  string description = "";
  string builderCall = "";
}
def anonymous_18 {	// Pred CPred
  string predExpr = "($_self.isSignlessInteger(64))";
}
def anonymous_180 {	// Constraint TypeConstraint Type AnyTypeOf
  Pred predicate = anonymous_181;
  string summary = "floating-point";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
  list<Type> allowedTypes = [AnyFloat];
}
def anonymous_181 {	// Pred CombinedPred Or
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = [anonymous_34];
}
def anonymous_182 {	// Pred CombinedPred SubstLeaves
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [anonymous_181];
  string pattern = "$_self";
  string replacement = "elementType";
}
def anonymous_183 {	// Pred CombinedPred Concat
  PredCombinerKind kind = PredCombinerConcat;
  list<Pred> children = [anonymous_182];
  string prefix = "[](::mlir::Type elementType) { return ";
  string suffix = "; }(::llvm::cast<::mlir::ShapedType>($_self).getElementType())";
}
def anonymous_184 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsVectorTypePred, anonymous_183];
}
def anonymous_185 {	// Constraint TypeConstraint Type ShapedContainerType TensorOf
  Pred predicate = anonymous_186;
  string summary = "tensor of floating-point values";
  string cppClassName = "::mlir::TensorType";
  string description = "";
  string builderCall = "";
}
def anonymous_186 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_58, anonymous_183];
}
def anonymous_187 {	// Pred CombinedPred Or
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = [anonymous_34, anonymous_184, anonymous_186];
}
def anonymous_188 {	// Pred CombinedPred Or
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = [anonymous_175, anonymous_187];
}
def anonymous_189 {	// Pred CPred
  string predExpr = "(::llvm::isa<::mlir::LocationAttr>($_self))";
}
def anonymous_19 {	// Pred CPred
  string predExpr = "($_self.isSignlessInteger(128))";
}
def anonymous_190 {	// Pred CPred
  string predExpr = "(::llvm::isa<::mlir::BoolAttr>($_self))";
}
def anonymous_191 {	// Pred CPred
  string predExpr = "(::llvm::isa<::mlir::IntegerAttr>($_self))";
}
def anonymous_192 {	// Pred CPred
  string predExpr = "(::llvm::isa<::mlir::IndexType>(::llvm::cast<::mlir::IntegerAttr>($_self).getType()))";
}
def anonymous_193 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_191, anonymous_192];
}
def anonymous_194 {	// Pred CPred
  string predExpr = "(::llvm::cast<::mlir::IntegerAttr>($_self).getType().isInteger(1))";
}
def anonymous_195 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_191, anonymous_194];
}
def anonymous_196 {	// Pred CPred
  string predExpr = "(::llvm::cast<::mlir::IntegerAttr>($_self).getType().isInteger(8))";
}
def anonymous_197 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_191, anonymous_196];
}
def anonymous_198 {	// Pred CPred
  string predExpr = "(::llvm::cast<::mlir::IntegerAttr>($_self).getType().isInteger(16))";
}
def anonymous_199 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_191, anonymous_198];
}
def anonymous_2 {	// Pred CPred
  string predExpr = "(::llvm::cast<::mlir::VectorType>($_self).getScalableDims().back())";
}
def anonymous_20 {	// Pred CPred
  string predExpr = "($_self.isSignedInteger())";
}
def anonymous_200 {	// Pred CPred
  string predExpr = "(::llvm::cast<::mlir::IntegerAttr>($_self).getType().isInteger(32))";
}
def anonymous_201 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_191, anonymous_200];
}
def anonymous_202 {	// Pred CPred
  string predExpr = "(::llvm::cast<::mlir::IntegerAttr>($_self).getType().isInteger(64))";
}
def anonymous_203 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_191, anonymous_202];
}
def anonymous_204 {	// Pred CPred
  string predExpr = "(::llvm::cast<::mlir::IntegerAttr>($_self).getType().isSignlessInteger(1))";
}
def anonymous_205 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_191, anonymous_204];
}
def anonymous_206 {	// Pred CPred
  string predExpr = "(::llvm::cast<::mlir::IntegerAttr>($_self).getType().isSignlessInteger(8))";
}
def anonymous_207 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_191, anonymous_206];
}
def anonymous_208 {	// Pred CPred
  string predExpr = "(::llvm::cast<::mlir::IntegerAttr>($_self).getType().isSignlessInteger(16))";
}
def anonymous_209 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_191, anonymous_208];
}
def anonymous_21 {	// Pred CPred
  string predExpr = "($_self.isSignedInteger(1))";
}
def anonymous_210 {	// Pred CPred
  string predExpr = "(::llvm::cast<::mlir::IntegerAttr>($_self).getType().isSignlessInteger(32))";
}
def anonymous_211 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_191, anonymous_210];
}
def anonymous_212 {	// Pred CPred
  string predExpr = "(::llvm::cast<::mlir::IntegerAttr>($_self).getType().isSignlessInteger(64))";
}
def anonymous_213 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_191, anonymous_212];
}
def anonymous_214 {	// Pred CPred
  string predExpr = "(::llvm::cast<::mlir::IntegerAttr>($_self).getType().isSignedInteger(1))";
}
def anonymous_215 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_191, anonymous_214];
}
def anonymous_216 {	// Pred CPred
  string predExpr = "(::llvm::cast<::mlir::IntegerAttr>($_self).getType().isSignedInteger(8))";
}
def anonymous_217 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_191, anonymous_216];
}
def anonymous_218 {	// Pred CPred
  string predExpr = "(::llvm::cast<::mlir::IntegerAttr>($_self).getType().isSignedInteger(16))";
}
def anonymous_219 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_191, anonymous_218];
}
def anonymous_22 {	// Pred CPred
  string predExpr = "($_self.isSignedInteger(8))";
}
def anonymous_220 {	// Pred CPred
  string predExpr = "(::llvm::cast<::mlir::IntegerAttr>($_self).getType().isSignedInteger(32))";
}
def anonymous_221 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_191, anonymous_220];
}
def anonymous_222 {	// Pred CPred
  string predExpr = "(::llvm::cast<::mlir::IntegerAttr>($_self).getType().isSignedInteger(64))";
}
def anonymous_223 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_191, anonymous_222];
}
def anonymous_224 {	// Pred CPred
  string predExpr = "(::llvm::cast<::mlir::IntegerAttr>($_self).getType().isUnsignedInteger(1))";
}
def anonymous_225 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_191, anonymous_224];
}
def anonymous_226 {	// Pred CPred
  string predExpr = "(::llvm::cast<::mlir::IntegerAttr>($_self).getType().isUnsignedInteger(8))";
}
def anonymous_227 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_191, anonymous_226];
}
def anonymous_228 {	// Pred CPred
  string predExpr = "(::llvm::cast<::mlir::IntegerAttr>($_self).getType().isUnsignedInteger(16))";
}
def anonymous_229 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_191, anonymous_228];
}
def anonymous_23 {	// Pred CPred
  string predExpr = "($_self.isSignedInteger(16))";
}
def anonymous_230 {	// Pred CPred
  string predExpr = "(::llvm::cast<::mlir::IntegerAttr>($_self).getType().isUnsignedInteger(32))";
}
def anonymous_231 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_191, anonymous_230];
}
def anonymous_232 {	// Pred CPred
  string predExpr = "(::llvm::cast<::mlir::IntegerAttr>($_self).getType().isUnsignedInteger(64))";
}
def anonymous_233 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_191, anonymous_232];
}
def anonymous_234 {	// Pred CPred
  string predExpr = "(::llvm::isa<::mlir::FloatAttr>($_self))";
}
def anonymous_235 {	// Pred CPred
  string predExpr = "(::llvm::cast<::mlir::FloatAttr>($_self).getType().isF32())";
}
def anonymous_236 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_234, anonymous_235];
}
def anonymous_237 {	// Pred CPred
  string predExpr = "(::llvm::cast<::mlir::FloatAttr>($_self).getType().isF64())";
}
def anonymous_238 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_234, anonymous_237];
}
def anonymous_239 {	// Pred CPred
  string predExpr = "(::llvm::isa<::mlir::StringAttr>($_self))";
}
def anonymous_24 {	// Pred CPred
  string predExpr = "($_self.isSignedInteger(32))";
}
def anonymous_240 {	// Pred CPred
  string predExpr = "(::llvm::isa<::mlir::TypeAttr>($_self))";
}
def anonymous_241 {	// Pred CPred
  string predExpr = "(::llvm::isa<::mlir::Type>(::llvm::cast<::mlir::TypeAttr>($_self).getValue()))";
}
def anonymous_242 {	// Pred CombinedPred SubstLeaves
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [anonymous_5];
  string pattern = "$_self";
  string replacement = "::llvm::cast<::mlir::TypeAttr>($_self).getValue()";
}
def anonymous_243 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_240, anonymous_241, anonymous_242];
}
def anonymous_244 {	// Pred CPred
  string predExpr = "(::llvm::isa<::mlir::UnitAttr>($_self))";
}
def anonymous_245 {	// Pred CPred
  string predExpr = "(::llvm::isa<::mlir::DictionaryAttr>($_self))";
}
def anonymous_246 {	// Pred CPred
  string predExpr = "(::llvm::isa<::mlir::ElementsAttr>($_self))";
}
def anonymous_247 {	// Pred CPred
  string predExpr = "(::llvm::isa<::mlir::DenseIntElementsAttr>($_self))";
}
def anonymous_248 {	// Pred CPred
  string predExpr = "(::llvm::isa<::mlir::DenseBoolArrayAttr>($_self))";
}
def anonymous_249 {	// Pred CPred
  string predExpr = "(::llvm::isa<::mlir::DenseI8ArrayAttr>($_self))";
}
def anonymous_25 {	// Pred CPred
  string predExpr = "($_self.isSignedInteger(64))";
}
def anonymous_250 {	// Pred CPred
  string predExpr = "(::llvm::isa<::mlir::DenseI16ArrayAttr>($_self))";
}
def anonymous_251 {	// Pred CPred
  string predExpr = "(::llvm::isa<::mlir::DenseI32ArrayAttr>($_self))";
}
def anonymous_252 {	// Pred CPred
  string predExpr = "(::llvm::isa<::mlir::DenseI64ArrayAttr>($_self))";
}
def anonymous_253 {	// Pred CPred
  string predExpr = "(::llvm::isa<::mlir::DenseF32ArrayAttr>($_self))";
}
def anonymous_254 {	// Pred CPred
  string predExpr = "(::llvm::isa<::mlir::DenseF64ArrayAttr>($_self))";
}
def anonymous_255 {	// Pred CPred
  code predExpr = [{(::llvm::cast<::mlir::DenseIntElementsAttr>($_self)
                                      .getType()
                                      .getElementType()
                                      .isIndex())}];
}
def anonymous_256 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_247, anonymous_255];
}
def anonymous_257 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_247, anonymous_5];
}
def anonymous_258 {	// Pred CPred
  string predExpr = "(::llvm::cast<::mlir::DenseIntElementsAttr>($_self).getType().getElementType().isInteger(32))";
}
def anonymous_259 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_247, anonymous_258];
}
def anonymous_26 {	// Pred CPred
  string predExpr = "($_self.isUnsignedInteger())";
}
def anonymous_260 {	// Pred CPred
  string predExpr = "(::llvm::cast<::mlir::DenseIntElementsAttr>($_self).getType().getElementType().isInteger(64))";
}
def anonymous_261 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_247, anonymous_260];
}
def anonymous_262 {	// Pred CPred
  string predExpr = "(::llvm::cast<::mlir::DenseIntElementsAttr>($_self).getType().getElementType().isSignlessInteger(32))";
}
def anonymous_263 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_247, anonymous_262];
}
def anonymous_264 {	// Pred CPred
  string predExpr = "(::llvm::cast<::mlir::DenseIntElementsAttr>($_self).getType().getElementType().isSignlessInteger(64))";
}
def anonymous_265 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_247, anonymous_264];
}
def anonymous_266 {	// Constraint AttrConstraint Attr ElementsAttrBase IntElementsAttrBase SignlessIntElementsAttr
  Pred predicate = anonymous_263;
  string summary = "32-bit signless integer elements attribute";
  code storageType = [{ ::mlir::DenseIntElementsAttr }];
  code returnType = [{ ::mlir::DenseIntElementsAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = "::llvm::cast<::mlir::DenseIntElementsAttr>(::mlir::DenseElementsAttr::get(::mlir::RankedTensorType::get({}, $_builder.getIntegerType(32)), ::llvm::ArrayRef($0)))";
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def anonymous_267 {	// Constraint AttrConstraint Attr ElementsAttrBase IntElementsAttrBase SignlessIntElementsAttr
  Pred predicate = anonymous_265;
  string summary = "64-bit signless integer elements attribute";
  code storageType = [{ ::mlir::DenseIntElementsAttr }];
  code returnType = [{ ::mlir::DenseIntElementsAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = "::llvm::cast<::mlir::DenseIntElementsAttr>(::mlir::DenseElementsAttr::get(::mlir::RankedTensorType::get({}, $_builder.getIntegerType(64)), ::llvm::ArrayRef($0)))";
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def anonymous_268 {	// Pred CPred
  string predExpr = "(::llvm::isa<::mlir::DenseFPElementsAttr>($_self) &&::llvm::cast<::mlir::DenseElementsAttr>($_self).getType().getElementType().isF64())";
}
def anonymous_269 {	// Pred CPred
  string predExpr = "(::llvm::isa<::mlir::DenseStringElementsAttr>($_self))";
}
def anonymous_27 {	// Pred CPred
  string predExpr = "($_self.isUnsignedInteger(1))";
}
def anonymous_270 {	// Pred CPred
  string predExpr = "(::llvm::isa<::mlir::AffineMapAttr>($_self))";
}
def anonymous_271 {	// Pred CPred
  string predExpr = "(::llvm::isa<::mlir::ArrayAttr>($_self))";
}
def anonymous_272 {	// Pred CombinedPred SubstLeaves
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [anonymous_189];
  string pattern = "$_self";
  string replacement = "attr";
}
def anonymous_273 {	// Pred CombinedPred Concat
  PredCombinerKind kind = PredCombinerConcat;
  list<Pred> children = [anonymous_272];
  string prefix = "::llvm::all_of(::llvm::cast<::mlir::ArrayAttr>($_self), [&](::mlir::Attribute attr) { return attr && (";
  string suffix = "); })";
}
def anonymous_274 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_271, anonymous_273];
}
def anonymous_275 {	// Pred CombinedPred SubstLeaves
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [anonymous_270];
  string pattern = "$_self";
  string replacement = "attr";
}
def anonymous_276 {	// Pred CombinedPred Concat
  PredCombinerKind kind = PredCombinerConcat;
  list<Pred> children = [anonymous_275];
  string prefix = "::llvm::all_of(::llvm::cast<::mlir::ArrayAttr>($_self), [&](::mlir::Attribute attr) { return attr && (";
  string suffix = "); })";
}
def anonymous_277 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_271, anonymous_276];
}
def anonymous_278 {	// Pred CombinedPred SubstLeaves
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [anonymous_190];
  string pattern = "$_self";
  string replacement = "attr";
}
def anonymous_279 {	// Pred CombinedPred Concat
  PredCombinerKind kind = PredCombinerConcat;
  list<Pred> children = [anonymous_278];
  string prefix = "::llvm::all_of(::llvm::cast<::mlir::ArrayAttr>($_self), [&](::mlir::Attribute attr) { return attr && (";
  string suffix = "); })";
}
def anonymous_28 {	// Pred CPred
  string predExpr = "($_self.isUnsignedInteger(8))";
}
def anonymous_280 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_271, anonymous_279];
}
def anonymous_281 {	// Pred CombinedPred SubstLeaves
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [anonymous_211];
  string pattern = "$_self";
  string replacement = "attr";
}
def anonymous_282 {	// Pred CombinedPred Concat
  PredCombinerKind kind = PredCombinerConcat;
  list<Pred> children = [anonymous_281];
  string prefix = "::llvm::all_of(::llvm::cast<::mlir::ArrayAttr>($_self), [&](::mlir::Attribute attr) { return attr && (";
  string suffix = "); })";
}
def anonymous_283 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_271, anonymous_282];
}
def anonymous_284 {	// Pred CombinedPred SubstLeaves
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [anonymous_213];
  string pattern = "$_self";
  string replacement = "attr";
}
def anonymous_285 {	// Pred CombinedPred Concat
  PredCombinerKind kind = PredCombinerConcat;
  list<Pred> children = [anonymous_284];
  string prefix = "::llvm::all_of(::llvm::cast<::mlir::ArrayAttr>($_self), [&](::mlir::Attribute attr) { return attr && (";
  string suffix = "); })";
}
def anonymous_286 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_271, anonymous_285];
}
def anonymous_287 {	// Pred CombinedPred SubstLeaves
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [anonymous_236];
  string pattern = "$_self";
  string replacement = "attr";
}
def anonymous_288 {	// Pred CombinedPred Concat
  PredCombinerKind kind = PredCombinerConcat;
  list<Pred> children = [anonymous_287];
  string prefix = "::llvm::all_of(::llvm::cast<::mlir::ArrayAttr>($_self), [&](::mlir::Attribute attr) { return attr && (";
  string suffix = "); })";
}
def anonymous_289 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_271, anonymous_288];
}
def anonymous_29 {	// Pred CPred
  string predExpr = "($_self.isUnsignedInteger(16))";
}
def anonymous_290 {	// Pred CombinedPred SubstLeaves
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [anonymous_238];
  string pattern = "$_self";
  string replacement = "attr";
}
def anonymous_291 {	// Pred CombinedPred Concat
  PredCombinerKind kind = PredCombinerConcat;
  list<Pred> children = [anonymous_290];
  string prefix = "::llvm::all_of(::llvm::cast<::mlir::ArrayAttr>($_self), [&](::mlir::Attribute attr) { return attr && (";
  string suffix = "); })";
}
def anonymous_292 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_271, anonymous_291];
}
def anonymous_293 {	// Pred CombinedPred SubstLeaves
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [anonymous_239];
  string pattern = "$_self";
  string replacement = "attr";
}
def anonymous_294 {	// Pred CombinedPred Concat
  PredCombinerKind kind = PredCombinerConcat;
  list<Pred> children = [anonymous_293];
  string prefix = "::llvm::all_of(::llvm::cast<::mlir::ArrayAttr>($_self), [&](::mlir::Attribute attr) { return attr && (";
  string suffix = "); })";
}
def anonymous_295 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_271, anonymous_294];
}
def anonymous_296 {	// Pred CombinedPred SubstLeaves
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [anonymous_243];
  string pattern = "$_self";
  string replacement = "attr";
}
def anonymous_297 {	// Pred CombinedPred Concat
  PredCombinerKind kind = PredCombinerConcat;
  list<Pred> children = [anonymous_296];
  string prefix = "::llvm::all_of(::llvm::cast<::mlir::ArrayAttr>($_self), [&](::mlir::Attribute attr) { return attr && (";
  string suffix = "); })";
}
def anonymous_298 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_271, anonymous_297];
}
def anonymous_299 {	// Pred CombinedPred SubstLeaves
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [anonymous_286];
  string pattern = "$_self";
  string replacement = "attr";
}
def anonymous_3 {	// Pred CPred
  string predExpr = "(!llvm::is_contained(::llvm::cast<::mlir::VectorType>($_self).getScalableDims().drop_back(), true))";
}
def anonymous_30 {	// Pred CPred
  string predExpr = "($_self.isUnsignedInteger(32))";
}
def anonymous_300 {	// Pred CombinedPred Concat
  PredCombinerKind kind = PredCombinerConcat;
  list<Pred> children = [anonymous_299];
  string prefix = "::llvm::all_of(::llvm::cast<::mlir::ArrayAttr>($_self), [&](::mlir::Attribute attr) { return attr && (";
  string suffix = "); })";
}
def anonymous_301 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_271, anonymous_300];
}
def anonymous_302 {	// Pred CombinedPred SubstLeaves
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [anonymous_245];
  string pattern = "$_self";
  string replacement = "attr";
}
def anonymous_303 {	// Pred CombinedPred Concat
  PredCombinerKind kind = PredCombinerConcat;
  list<Pred> children = [anonymous_302];
  string prefix = "::llvm::all_of(::llvm::cast<::mlir::ArrayAttr>($_self), [&](::mlir::Attribute attr) { return attr && (";
  string suffix = "); })";
}
def anonymous_304 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_271, anonymous_303];
}
def anonymous_305 {	// Pred CPred
  string predExpr = "(::llvm::isa<::mlir::SymbolRefAttr>($_self))";
}
def anonymous_306 {	// Pred CPred
  string predExpr = "(::llvm::isa<::mlir::FlatSymbolRefAttr>($_self))";
}
def anonymous_307 {	// Pred CombinedPred SubstLeaves
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [anonymous_305];
  string pattern = "$_self";
  string replacement = "attr";
}
def anonymous_308 {	// Pred CombinedPred Concat
  PredCombinerKind kind = PredCombinerConcat;
  list<Pred> children = [anonymous_307];
  string prefix = "::llvm::all_of(::llvm::cast<::mlir::ArrayAttr>($_self), [&](::mlir::Attribute attr) { return attr && (";
  string suffix = "); })";
}
def anonymous_309 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_271, anonymous_308];
}
def anonymous_31 {	// Pred CPred
  string predExpr = "($_self.isUnsignedInteger(64))";
}
def anonymous_310 {	// Pred CombinedPred SubstLeaves
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [anonymous_306];
  string pattern = "$_self";
  string replacement = "attr";
}
def anonymous_311 {	// Pred CombinedPred Concat
  PredCombinerKind kind = PredCombinerConcat;
  list<Pred> children = [anonymous_310];
  string prefix = "::llvm::all_of(::llvm::cast<::mlir::ArrayAttr>($_self), [&](::mlir::Attribute attr) { return attr && (";
  string suffix = "); })";
}
def anonymous_312 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_271, anonymous_311];
}
def anonymous_313 {	// Pred CPred
  string predExpr = "($_self == $_builder.getBoolAttr(false))";
}
def anonymous_314 {	// Pred CPred
  string predExpr = "($_self == $_builder.getBoolAttr(true))";
}
def anonymous_315 {	// Pred CPred
  string predExpr = "($_self == ((true) ? $_builder.getUnitAttr() : nullptr))";
}
def anonymous_316 {	// Pred CPred
  string predExpr = "(!::llvm::cast<::mlir::IntegerAttr>($_self).getValue().isNegative())";
}
def anonymous_317 {	// Pred CPred
  string predExpr = "(::llvm::cast<::mlir::IntegerAttr>($_self).getValue().isStrictlyPositive())";
}
def anonymous_318 {	// Pred CPred
  string predExpr = "(!$_self)";
}
def anonymous_319 {	// Pred CPred
  string predExpr = "()";
}
def anonymous_32 {	// Pred CPred
  string predExpr = "(::llvm::isa<::mlir::IndexType>($_self))";
}
def anonymous_320 {	// StrFunc ElementCount
  string result = "llvm::cast<::mlir::ShapedType>($_self.getType()).getNumElements()";
}
def anonymous_321 {	// StrFunc ElementType
  string result = "getElementTypeOrSelf($_self)";
}
def anonymous_322 {	// StrFunc Rank
  string result = "::llvm::cast<::mlir::ShapedType>($_self.getType()).getRank()";
}
def anonymous_323 {	// StrFunc Shape
  string result = "::llvm::cast<::mlir::ShapedType>($_self.getType()).getShape()";
}
def anonymous_324 {	// InterfaceMethod
  string description = "Returns the name of this symbol.";
  string name = "getNameAttr";
  string returnType = "::mlir::StringAttr";
  dag arguments = (ins);
  code body = [{
        // Don't rely on the trait implementation as optional symbol operations
        // may override this.
        return mlir::SymbolTable::getSymbolName($_op);
      }];
  code defaultBody = [{
        return mlir::SymbolTable::getSymbolName(this->getOperation());
      }];
}
def anonymous_325 {	// InterfaceMethod
  string description = "Sets the name of this symbol.";
  string name = "setName";
  string returnType = "void";
  dag arguments = (ins "::mlir::StringAttr":$name);
  code body = [{}];
  code defaultBody = [{
        this->getOperation()->setAttr(
            mlir::SymbolTable::getSymbolAttrName(), name);
      }];
}
def anonymous_326 {	// InterfaceMethod
  string description = "Gets the visibility of this symbol.";
  string name = "getVisibility";
  string returnType = "mlir::SymbolTable::Visibility";
  dag arguments = (ins);
  code body = [{}];
  code defaultBody = [{
        return mlir::SymbolTable::getSymbolVisibility(this->getOperation());
      }];
}
def anonymous_327 {	// InterfaceMethod
  string description = "Returns true if this symbol has nested visibility.";
  string name = "isNested";
  string returnType = "bool";
  dag arguments = (ins);
  code body = [{}];
  code defaultBody = [{
        return getVisibility() == mlir::SymbolTable::Visibility::Nested;
      }];
}
def anonymous_328 {	// InterfaceMethod
  string description = "Returns true if this symbol has private visibility.";
  string name = "isPrivate";
  string returnType = "bool";
  dag arguments = (ins);
  code body = [{}];
  code defaultBody = [{
        return getVisibility() == mlir::SymbolTable::Visibility::Private;
      }];
}
def anonymous_329 {	// InterfaceMethod
  string description = "Returns true if this symbol has public visibility.";
  string name = "isPublic";
  string returnType = "bool";
  dag arguments = (ins);
  code body = [{}];
  code defaultBody = [{
        return getVisibility() == mlir::SymbolTable::Visibility::Public;
      }];
}
def anonymous_33 {	// Pred CPred
  string predExpr = "($_self.isSignlessIntOrIndex())";
}
def anonymous_330 {	// InterfaceMethod
  string description = "Sets the visibility of this symbol.";
  string name = "setVisibility";
  string returnType = "void";
  dag arguments = (ins "mlir::SymbolTable::Visibility":$vis);
  code body = [{}];
  code defaultBody = [{
        mlir::SymbolTable::setSymbolVisibility(this->getOperation(), vis);
      }];
}
def anonymous_331 {	// InterfaceMethod
  string description = "Sets the visibility of this symbol to be nested.";
  string name = "setNested";
  string returnType = "void";
  dag arguments = (ins);
  code body = [{}];
  code defaultBody = [{
        setVisibility(mlir::SymbolTable::Visibility::Nested);
      }];
}
def anonymous_332 {	// InterfaceMethod
  string description = "Sets the visibility of this symbol to be private.";
  string name = "setPrivate";
  string returnType = "void";
  dag arguments = (ins);
  code body = [{}];
  code defaultBody = [{
        setVisibility(mlir::SymbolTable::Visibility::Private);
      }];
}
def anonymous_333 {	// InterfaceMethod
  string description = "Sets the visibility of this symbol to be public.";
  string name = "setPublic";
  string returnType = "void";
  dag arguments = (ins);
  code body = [{}];
  code defaultBody = [{
        setVisibility(mlir::SymbolTable::Visibility::Public);
      }];
}
def anonymous_334 {	// InterfaceMethod
  code description = [{
        Get all of the uses of the current symbol that are nested within the
        given operation 'from'.
        Note: See mlir::SymbolTable::getSymbolUses for more details.
      }];
  string name = "getSymbolUses";
  string returnType = "::std::optional<::mlir::SymbolTable::UseRange>";
  dag arguments = (ins "::mlir::Operation *":$from);
  code body = [{}];
  code defaultBody = [{
        return ::mlir::SymbolTable::getSymbolUses(this->getOperation(), from);
      }];
}
def anonymous_335 {	// InterfaceMethod
  code description = [{
        Return if the current symbol is known to have no uses that are nested
        within the given operation 'from'.
        Note: See mlir::SymbolTable::symbolKnownUseEmpty for more details.
      }];
  string name = "symbolKnownUseEmpty";
  string returnType = "bool";
  dag arguments = (ins "::mlir::Operation *":$from);
  code body = [{}];
  code defaultBody = [{
        return ::mlir::SymbolTable::symbolKnownUseEmpty(this->getOperation(),
                                                        from);
      }];
}
def anonymous_336 {	// InterfaceMethod
  code description = [{
        Attempt to replace all uses of the current symbol with the provided
        symbol 'newSymbol' that are nested within the given operation 'from'.
        Note: See mlir::SymbolTable::replaceAllSymbolUses for more details.
      }];
  string name = "replaceAllSymbolUses";
  string returnType = "::mlir::LogicalResult";
  dag arguments = (ins "::mlir::StringAttr":$newSymbol, "::mlir::Operation *":$from);
  code body = [{}];
  code defaultBody = [{
        return ::mlir::SymbolTable::replaceAllSymbolUses(this->getOperation(),
                                                         newSymbol, from);
      }];
}
def anonymous_337 {	// InterfaceMethod
  code description = [{
        Returns true if this operation optionally defines a symbol based on the
        presence of the symbol name.
      }];
  string name = "isOptionalSymbol";
  string returnType = "bool";
  dag arguments = (ins);
  code body = [{}];
  code defaultBody = [{ return false; }];
}
def anonymous_338 {	// InterfaceMethod
  code description = [{
        Returns true if this operation can be discarded if it has no remaining
        symbol uses.
      }];
  string name = "canDiscardOnUseEmpty";
  string returnType = "bool";
  dag arguments = (ins);
  code body = [{}];
  code defaultBody = [{
        // By default, base this on the visibility alone. A symbol can be
        // discarded as long as it is not public. Only public symbols may be
        // visible from outside of the IR.
        return getVisibility() != ::mlir::SymbolTable::Visibility::Public;
      }];
}
def anonymous_339 {	// InterfaceMethod
  code description = [{
        Returns true if this operation is a declaration of a symbol (as opposed
        to a definition).
      }];
  string name = "isDeclaration";
  string returnType = "bool";
  dag arguments = (ins);
  code body = [{}];
  code defaultBody = [{
        // By default, assume that the operation defines a symbol.
        return false;
      }];
}
def anonymous_34 {	// Pred CPred
  string predExpr = "(::llvm::isa<::mlir::FloatType>($_self))";
}
def anonymous_340 {	// InterfaceMethod
  string description = "Verify the symbol uses held by this operation.";
  string name = "verifySymbolUses";
  string returnType = "::mlir::LogicalResult";
  dag arguments = (ins "::mlir::SymbolTableCollection &":$symbolTable);
  code body = [{}];
  code defaultBody = [{}];
}
def anonymous_341 {	// InterfaceMethod
  code description = [{
        Returns the callee of this call-like operation. A `callee` is either a
        reference to a symbol, via SymbolRefAttr, or a reference to a defined
        SSA value. If the reference is an SSA value, the SSA value corresponds
        to a region of a lambda-like operation.
      }];
  string name = "getCallableForCallee";
  string returnType = "::mlir::CallInterfaceCallable";
  dag arguments = (ins);
  code body = [{}];
  code defaultBody = [{}];
}
def anonymous_342 {	// InterfaceMethod
  code description = [{
        Sets the callee of this call-like operation. A `callee` is either a
        reference to a symbol, via SymbolRefAttr, or a reference to a defined
        SSA value. The type of the `callee` is expected to be the same as the
        return type of `getCallableForCallee`, e.g., `callee` should be
        SymbolRefAttr for `func.call`.
      }];
  string name = "setCalleeFromCallable";
  string returnType = "void";
  dag arguments = (ins "::mlir::CallInterfaceCallable":$callee);
  code body = [{}];
  code defaultBody = [{}];
}
def anonymous_343 {	// InterfaceMethod
  code description = [{
        Returns the operands within this call that are used as arguments to the
        callee.
      }];
  string name = "getArgOperands";
  string returnType = "::mlir::Operation::operand_range";
  dag arguments = (ins);
  code body = [{}];
  code defaultBody = [{}];
}
def anonymous_344 {	// InterfaceMethod
  code description = [{
        Returns the operands within this call that are used as arguments to the
        callee as a mutable range.
      }];
  string name = "getArgOperandsMutable";
  string returnType = "::mlir::MutableOperandRange";
  dag arguments = (ins);
  code body = [{}];
  code defaultBody = [{}];
}
def anonymous_345 {	// InterfaceMethod
  code description = [{
        Returns the region on the current operation that is callable. This may
        return null in the case of an external callable object, e.g. an external
        function.
      }];
  string name = "getCallableRegion";
  string returnType = "::mlir::Region *";
  dag arguments = (ins);
  code body = [{}];
  code defaultBody = [{}];
}
def anonymous_346 {	// InterfaceMethod
  code description = [{
      Returns the callable's argument types based exclusively on the type (to
      allow for this method may be called on function declarations).
    }];
  string name = "getArgumentTypes";
  string returnType = "::llvm::ArrayRef<::mlir::Type>";
  dag arguments = (ins);
  code body = [{}];
  code defaultBody = [{}];
}
def anonymous_347 {	// InterfaceMethod
  code description = [{
      Returns the callable's result types based exclusively on the type (to
      allow for this method may be called on function declarations).
    }];
  string name = "getResultTypes";
  string returnType = "::llvm::ArrayRef<::mlir::Type>";
  dag arguments = (ins);
  code body = [{}];
  code defaultBody = [{}];
}
def anonymous_348 {	// InterfaceMethod
  code description = [{
        Get the array of argument attribute dictionaries. The method should
        return an array attribute containing only dictionary attributes equal in
        number to the number of region arguments. Alternatively, the method can
        return null to indicate that the region has no argument attributes.
      }];
  string name = "getArgAttrsAttr";
  string returnType = "::mlir::ArrayAttr";
  dag arguments = (ins);
  code body = [{}];
  code defaultBody = [{ return nullptr; }];
}
def anonymous_349 {	// InterfaceMethod
  code description = [{
        Get the array of result attribute dictionaries. The method should return
        an array attribute containing only dictionary attributes equal in number
        to the number of region results. Alternatively, the method can return
        null to indicate that the region has no result attributes.
      }];
  string name = "getResAttrsAttr";
  string returnType = "::mlir::ArrayAttr";
  dag arguments = (ins);
  code body = [{}];
  code defaultBody = [{ return nullptr; }];
}
def anonymous_35 {	// Pred CPred
  string predExpr = "($_self.isF16())";
}
def anonymous_350 {	// InterfaceMethod
  code description = [{
      Set the array of argument attribute dictionaries.
    }];
  string name = "setArgAttrsAttr";
  string returnType = "void";
  dag arguments = (ins "::mlir::ArrayAttr":$attrs);
  code body = [{}];
  code defaultBody = [{ return; }];
}
def anonymous_351 {	// InterfaceMethod
  code description = [{
      Set the array of result attribute dictionaries.
    }];
  string name = "setResAttrsAttr";
  string returnType = "void";
  dag arguments = (ins "::mlir::ArrayAttr":$attrs);
  code body = [{}];
  code defaultBody = [{ return; }];
}
def anonymous_352 {	// InterfaceMethod
  code description = [{
      Remove the array of argument attribute dictionaries. This is the same as
      setting all argument attributes to an empty dictionary. The method should
      return the removed attribute.
    }];
  string name = "removeArgAttrsAttr";
  string returnType = "::mlir::Attribute";
  dag arguments = (ins);
  code body = [{}];
  code defaultBody = [{ return nullptr; }];
}
def anonymous_353 {	// InterfaceMethod
  code description = [{
      Remove the array of result attribute dictionaries. This is the same as
      setting all result attributes to an empty dictionary. The method should
      return the removed attribute.
    }];
  string name = "removeResAttrsAttr";
  string returnType = "::mlir::Attribute";
  dag arguments = (ins);
  code body = [{}];
  code defaultBody = [{ return nullptr; }];
}
def anonymous_354 {	// InterfaceMethod
  code description = [{
      Returns the type of the function.
    }];
  string name = "getFunctionType";
  string returnType = "::mlir::Type";
  dag arguments = (ins);
  code body = [{}];
  code defaultBody = [{}];
}
def anonymous_355 {	// InterfaceMethod
  code description = [{
      Set the type of the function. This method should perform an unsafe
      modification to the function type; it should not update argument or
      result attributes.
    }];
  string name = "setFunctionTypeAttr";
  string returnType = "void";
  dag arguments = (ins "::mlir::TypeAttr":$type);
  code body = [{}];
  code defaultBody = [{}];
}
def anonymous_356 {	// InterfaceMethod
  code description = [{
      Returns a clone of the function type with the given argument and
      result types.

      Note: The default implementation assumes the function type has
            an appropriate clone method:
              `Type clone(ArrayRef<Type> inputs, ArrayRef<Type> results)`
    }];
  string name = "cloneTypeWith";
  string returnType = "::mlir::Type";
  dag arguments = (ins "::mlir::TypeRange":$inputs, "::mlir::TypeRange":$results);
  code body = [{}];
  code defaultBody = [{
      return $_op.getFunctionType().clone(inputs, results);
    }];
}
def anonymous_357 {	// InterfaceMethod
  code description = [{
      Verify the contents of the body of this function.

      Note: The default implementation merely checks that if the entry block
      exists, it has the same number and type of arguments as the function type.
    }];
  string name = "verifyBody";
  string returnType = "::mlir::LogicalResult";
  dag arguments = (ins);
  code body = [{}];
  code defaultBody = [{
      if ($_op.isExternal())
        return success();
      ArrayRef<Type> fnInputTypes = $_op.getArgumentTypes();
      // NOTE: This should just be $_op.front() but access generically
      // because the interface methods defined here may be shadowed in
      // arbitrary ways. https://github.com/llvm/llvm-project/issues/54807
      Block &entryBlock = $_op->getRegion(0).front();

      unsigned numArguments = fnInputTypes.size();
      if (entryBlock.getNumArguments() != numArguments)
        return $_op.emitOpError("entry block must have ")
              << numArguments << " arguments to match function signature";

      for (unsigned i = 0, e = fnInputTypes.size(); i != e; ++i) {
        Type argType = entryBlock.getArgument(i).getType();
        if (fnInputTypes[i] != argType) {
          return $_op.emitOpError("type of entry block argument #")
                << i << '(' << argType
                << ") must match the type of the corresponding argument in "
                << "function signature(" << fnInputTypes[i] << ')';
        }
      }

      return success();
    }];
}
def anonymous_358 {	// InterfaceMethod
  code description = [{
      Verify the type attribute of the function for derived op-specific
      invariants.
    }];
  string name = "verifyType";
  string returnType = "::mlir::LogicalResult";
  dag arguments = (ins);
  code body = [{}];
  code defaultBody = [{
      return success();
    }];
}
def anonymous_359 {	// InterfaceMethod
  code description = [{
        Collects all of the operation's effects into `effects`.
      }];
  string name = "getEffects";
  string returnType = "void";
  dag arguments = (ins "::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &":$effects);
  code body = [{}];
  code defaultBody = [{}];
}
def anonymous_36 {	// Pred CPred
  string predExpr = "($_self.isF32())";
}
def anonymous_360 {	// InterfaceMethod
  code description = [{
        Returns value indicating whether the specific operation in question can
        be speculatively executed.  Please see the documentation on the
        Speculatability enum to know how to interpret the return value.
      }];
  string name = "getSpeculatability";
  string returnType = "::mlir::Speculation::Speculatability";
  dag arguments = (ins);
  code body = [{}];
  code defaultBody = [{}];
}
def anonymous_361 {	// OpBuilder
  dag dagParams = (ins "DenseElementsAttr":$value);
  code body = [{
      build($_builder, $_state, value.getType(), value);
    }];
}
def anonymous_362 {	// OpBuilder
  dag dagParams = (ins "StringRef":$table_name);
  code body = [{
      build($_builder, $_state, TableType::get($_builder.getContext()), $_builder.getStringAttr(table_name));
    }];
}
def anonymous_363 {	// OpBuilder
  dag dagParams = (ins "Value":$table, "ArrayRef<Attribute>":$conditions);
  code body = [{
      build($_builder, $_state, table.getType(), table, $_builder.getArrayAttr(conditions));
    }];
}
def anonymous_37 {	// Pred CPred
  string predExpr = "($_self.isF64())";
}
def anonymous_38 {	// Pred CPred
  string predExpr = "($_self.isF80())";
}
def anonymous_39 {	// Pred CPred
  string predExpr = "($_self.isF128())";
}
def anonymous_4 {	// Pred CPred
  code predExpr = [{(::llvm::cast<::mlir::VectorType>($_self).allDimsScalable())}];
}
def anonymous_40 {	// Pred CPred
  string predExpr = "($_self.isBF16())";
}
def anonymous_41 {	// Pred CPred
  string predExpr = "($_self.isTF32())";
}
def anonymous_42 {	// Pred CPred
  string predExpr = "($_self.isFloat8E4M3FN())";
}
def anonymous_43 {	// Pred CPred
  string predExpr = "($_self.isFloat8E5M2())";
}
def anonymous_44 {	// Pred CPred
  string predExpr = "($_self.isFloat8E4M3FNUZ())";
}
def anonymous_45 {	// Pred CPred
  string predExpr = "($_self.isFloat8E4M3B11FNUZ())";
}
def anonymous_46 {	// Pred CPred
  string predExpr = "($_self.isFloat8E5M2FNUZ())";
}
def anonymous_47 {	// Pred CPred
  string predExpr = "(::llvm::isa<::mlir::ComplexType>($_self))";
}
def anonymous_48 {	// Pred CPred
  string predExpr = "(::llvm::isa<::mlir::FunctionType>($_self))";
}
def anonymous_49 {	// Constraint TypeConstraint Type AnyTypeOf
  Pred predicate = anonymous_50;
  string summary = "any type";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
  list<Type> allowedTypes = [AnyType];
}
def anonymous_5 {	// Pred CPred
  string predExpr = "(true)";
}
def anonymous_50 {	// Pred CombinedPred Or
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = [anonymous_5];
}
def anonymous_51 {	// Pred CombinedPred SubstLeaves
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [anonymous_50];
  string pattern = "$_self";
  string replacement = "elementType";
}
def anonymous_52 {	// Pred CombinedPred Concat
  PredCombinerKind kind = PredCombinerConcat;
  list<Pred> children = [anonymous_51];
  string prefix = "[](::mlir::Type elementType) { return ";
  string suffix = "; }(::llvm::cast<::mlir::ShapedType>($_self).getElementType())";
}
def anonymous_53 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsVectorTypePred, anonymous_52];
}
def anonymous_54 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsVectorOfAnyRankTypePred, anonymous_52];
}
def anonymous_55 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsFixedVectorTypePred, anonymous_52];
}
def anonymous_56 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsVectorTypeWithAnyDimScalablePred, anonymous_52];
}
def anonymous_57 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsShapedTypePred, anonymous_52];
}
def anonymous_58 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsTensorTypePred];
}
def anonymous_59 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_58, anonymous_52];
}
def anonymous_6 {	// Pred CPred
  string predExpr = "(::llvm::isa<::mlir::NoneType>($_self))";
}
def anonymous_60 {	// Constraint TypeConstraint Type AnyTypeOf
  Pred predicate = anonymous_61;
  string summary = "1-bit signless integer";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
  list<Type> allowedTypes = [I1];
}
def anonymous_61 {	// Pred CombinedPred Or
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = [anonymous_14];
}
def anonymous_62 {	// Pred CombinedPred SubstLeaves
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [anonymous_61];
  string pattern = "$_self";
  string replacement = "elementType";
}
def anonymous_63 {	// Pred CombinedPred Concat
  PredCombinerKind kind = PredCombinerConcat;
  list<Pred> children = [anonymous_62];
  string prefix = "[](::mlir::Type elementType) { return ";
  string suffix = "; }(::llvm::cast<::mlir::ShapedType>($_self).getElementType())";
}
def anonymous_64 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_58, anonymous_63];
}
def anonymous_65 {	// Constraint TypeConstraint Type AnyTypeOf
  Pred predicate = anonymous_66;
  string summary = "8-bit signless integer";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
  list<Type> allowedTypes = [I8];
}
def anonymous_66 {	// Pred CombinedPred Or
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = [anonymous_15];
}
def anonymous_67 {	// Pred CombinedPred SubstLeaves
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [anonymous_66];
  string pattern = "$_self";
  string replacement = "elementType";
}
def anonymous_68 {	// Pred CombinedPred Concat
  PredCombinerKind kind = PredCombinerConcat;
  list<Pred> children = [anonymous_67];
  string prefix = "[](::mlir::Type elementType) { return ";
  string suffix = "; }(::llvm::cast<::mlir::ShapedType>($_self).getElementType())";
}
def anonymous_69 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_58, anonymous_68];
}
def anonymous_7 {	// Pred CPred
  string predExpr = "(::llvm::isa<::mlir::IntegerType>($_self))";
}
def anonymous_70 {	// Constraint TypeConstraint Type AnyTypeOf
  Pred predicate = anonymous_71;
  string summary = "16-bit signless integer";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
  list<Type> allowedTypes = [I16];
}
def anonymous_71 {	// Pred CombinedPred Or
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = [anonymous_16];
}
def anonymous_72 {	// Pred CombinedPred SubstLeaves
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [anonymous_71];
  string pattern = "$_self";
  string replacement = "elementType";
}
def anonymous_73 {	// Pred CombinedPred Concat
  PredCombinerKind kind = PredCombinerConcat;
  list<Pred> children = [anonymous_72];
  string prefix = "[](::mlir::Type elementType) { return ";
  string suffix = "; }(::llvm::cast<::mlir::ShapedType>($_self).getElementType())";
}
def anonymous_74 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_58, anonymous_73];
}
def anonymous_75 {	// Constraint TypeConstraint Type AnyTypeOf
  Pred predicate = anonymous_76;
  string summary = "32-bit signless integer";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
  list<Type> allowedTypes = [I32];
}
def anonymous_76 {	// Pred CombinedPred Or
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = [anonymous_17];
}
def anonymous_77 {	// Pred CombinedPred SubstLeaves
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [anonymous_76];
  string pattern = "$_self";
  string replacement = "elementType";
}
def anonymous_78 {	// Pred CombinedPred Concat
  PredCombinerKind kind = PredCombinerConcat;
  list<Pred> children = [anonymous_77];
  string prefix = "[](::mlir::Type elementType) { return ";
  string suffix = "; }(::llvm::cast<::mlir::ShapedType>($_self).getElementType())";
}
def anonymous_79 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_58, anonymous_78];
}
def anonymous_8 {	// Pred CPred
  string predExpr = "($_self.isInteger(1))";
}
def anonymous_80 {	// Constraint TypeConstraint Type AnyTypeOf
  Pred predicate = anonymous_81;
  string summary = "64-bit signless integer";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
  list<Type> allowedTypes = [I64];
}
def anonymous_81 {	// Pred CombinedPred Or
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = [anonymous_18];
}
def anonymous_82 {	// Pred CombinedPred SubstLeaves
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [anonymous_81];
  string pattern = "$_self";
  string replacement = "elementType";
}
def anonymous_83 {	// Pred CombinedPred Concat
  PredCombinerKind kind = PredCombinerConcat;
  list<Pred> children = [anonymous_82];
  string prefix = "[](::mlir::Type elementType) { return ";
  string suffix = "; }(::llvm::cast<::mlir::ShapedType>($_self).getElementType())";
}
def anonymous_84 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_58, anonymous_83];
}
def anonymous_85 {	// Constraint TypeConstraint Type AnyTypeOf
  Pred predicate = anonymous_86;
  string summary = "index";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
  list<Type> allowedTypes = [Index];
}
def anonymous_86 {	// Pred CombinedPred Or
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = [anonymous_32];
}
def anonymous_87 {	// Pred CombinedPred SubstLeaves
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [anonymous_86];
  string pattern = "$_self";
  string replacement = "elementType";
}
def anonymous_88 {	// Pred CombinedPred Concat
  PredCombinerKind kind = PredCombinerConcat;
  list<Pred> children = [anonymous_87];
  string prefix = "[](::mlir::Type elementType) { return ";
  string suffix = "; }(::llvm::cast<::mlir::ShapedType>($_self).getElementType())";
}
def anonymous_89 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_58, anonymous_88];
}
def anonymous_9 {	// Pred CPred
  string predExpr = "($_self.isInteger(8))";
}
def anonymous_90 {	// Constraint TypeConstraint Type AnyTypeOf
  Pred predicate = anonymous_91;
  string summary = "bfloat16 type";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
  list<Type> allowedTypes = [BF16];
}
def anonymous_91 {	// Pred CombinedPred Or
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = [anonymous_40];
}
def anonymous_92 {	// Pred CombinedPred SubstLeaves
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [anonymous_91];
  string pattern = "$_self";
  string replacement = "elementType";
}
def anonymous_93 {	// Pred CombinedPred Concat
  PredCombinerKind kind = PredCombinerConcat;
  list<Pred> children = [anonymous_92];
  string prefix = "[](::mlir::Type elementType) { return ";
  string suffix = "; }(::llvm::cast<::mlir::ShapedType>($_self).getElementType())";
}
def anonymous_94 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_58, anonymous_93];
}
def anonymous_95 {	// Constraint TypeConstraint Type AnyTypeOf
  Pred predicate = anonymous_96;
  string summary = "16-bit float";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
  list<Type> allowedTypes = [F16];
}
def anonymous_96 {	// Pred CombinedPred Or
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = [anonymous_35];
}
def anonymous_97 {	// Pred CombinedPred SubstLeaves
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [anonymous_96];
  string pattern = "$_self";
  string replacement = "elementType";
}
def anonymous_98 {	// Pred CombinedPred Concat
  PredCombinerKind kind = PredCombinerConcat;
  list<Pred> children = [anonymous_97];
  string prefix = "[](::mlir::Type elementType) { return ";
  string suffix = "; }(::llvm::cast<::mlir::ShapedType>($_self).getElementType())";
}
def anonymous_99 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_58, anonymous_98];
}
def ins {
}
def outs {
}
def region {
}
def successor {
}
