#include "SqlToAst/SqlToAst.h"
#include <fstream>
#include <iostream>
#include <sstream>

SqlToAst::SqlToAst(const std::string& filePath) : filePath_(filePath) {}

bool SqlToAst::parseSql() {
    std::ifstream sqlFile(filePath_);
    if (!sqlFile.is_open()) {
        std::cerr << "Failed to open SQL file: " << filePath_ << std::endl;
        return false;
    }

    std::stringstream buffer;
    buffer << sqlFile.rdbuf();
    std::string sql = buffer.str();

    hsql::SQLParser::parse(sql, &result_);

    if (!result_.isValid()) {
        std::cerr << "Failed to parse SQL: " << sql << std::endl;
        return false;
    }

    return true;
}

void SqlToAst::printAst() {
    if (result_.isValid()) {
        std::cout << "Parsed successfully!" << std::endl;

        for (auto i = 0u; i < result_.size(); ++i) {
            const hsql::SQLStatement* stmt = result_.getStatement(i);
            if (stmt->type() == hsql::kStmtSelect) {
                const hsql::SelectStatement* selectStmt = (const hsql::SelectStatement*)stmt;
                std::cout << "SELECT statement found" << std::endl;

                if (selectStmt->fromTable) {
                    std::cout << "Table: " << selectStmt->fromTable->getName() << std::endl;
                }

                if (selectStmt->whereClause) {
                    std::cout << "WHERE clause exists" << std::endl;
                }
            }
        }
    } else {
        std::cerr << "No valid AST to print." << std::endl;
    }
}
