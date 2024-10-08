#ifndef SQL_TO_AST_H
#define SQL_TO_AST_H

#include <string>
#include "SQLParser.h"
#include "sql/SQLStatement.h"

class SqlToAst {
public:
    SqlToAst(const std::string& filePath);
    bool parseSql();
    void printAst(const std::string& outputFilePath);

private:
    std::string filePath_;
    hsql::SQLParserResult result_;
};

#endif // SQL_TO_AST_H
