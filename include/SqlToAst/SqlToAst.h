#ifndef PETITE_AST_H
#define PETITE_AST_H

#include <string>
#include "SQLParser.h"
#include "sql/SQLStatement.h"

class SqlToAst {
public:
    SqlToAst(const std::string& filePath);
    bool parseSql();
    void printAst(const std::string& outputFilePath);
    hsql::SQLParserResult getResult() const;
private:
    std::string filePath_;
    hsql::SQLParserResult result_;
};

#endif // PETITE_AST_H
