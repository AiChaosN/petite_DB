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

void printExpression(std::ostream& out, const hsql::Expr* expr, int level = 0);
void printTableRef(std::ostream& out, const hsql::TableRef* table, int level = 0);
void printSelectStatement(std::ostream& out, const hsql::SelectStatement* selectStmt, int level = 0);

void SqlToAst::printAst(const std::string& outputFilePath) {
    std::ofstream outFile(outputFilePath);
    if (!outFile.is_open()) {
        std::cerr << "Failed to open output file: " << outputFilePath << std::endl;
        return;
    }

    if (result_.isValid()) {
        outFile << "Parsed successfully!" << std::endl;

        for (auto i = 0u; i < result_.size(); ++i) {
            const hsql::SQLStatement* stmt = result_.getStatement(i);
            if (stmt->type() == hsql::kStmtSelect) {
                const hsql::SelectStatement* selectStmt = static_cast<const hsql::SelectStatement*>(stmt);
                outFile << "SELECT statement found" << std::endl;
                printSelectStatement(outFile, selectStmt, 1);
            }
        }
    } else {
        outFile << "No valid AST to print." << std::endl;
    }
}

void printExpression(std::ostream& out, const hsql::Expr* expr, int level) {
    if (!expr) return;

    for (int i = 0; i < level; ++i) {
        out << "  ";
    }

    switch (expr->type) {
        case hsql::kExprStar:
            out << "*";
            break;
        case hsql::kExprColumnRef:
            out << "Column: " << (expr->table ? std::string(expr->table) + "." : "") << expr->name;
            break;
        case hsql::kExprLiteralFloat:
            out << "Literal float: " << expr->fval;
            break;
        case hsql::kExprLiteralInt:
            out << "Literal int: " << expr->ival;
            break;
        case hsql::kExprLiteralString:
            out << "Literal string: " << expr->name;
            break;
        case hsql::kExprFunctionRef:
            out << "Function: " << expr->name;
            if (expr->exprList) {
                out << "(";
                for (size_t i = 0; i < expr->exprList->size(); ++i) {
                    if (i > 0) out << ", ";
                    printExpression(out, (*expr->exprList)[i], 0);
                }
                out << ")";
            }
            break;
        case hsql::kExprOperator:
            out << "Operator: " << expr->opType << std::endl;
            if (expr->expr) {
                printExpression(out, expr->expr, level + 1);
            }
            if (expr->expr2) {
                printExpression(out, expr->expr2, level + 1);
            }
            break;
        default:
            out << "Expression type: " << expr->type;
            break;
    }
    out << std::endl;

    if (expr->alias) {
        for (int i = 0; i < level + 1; ++i) {
            out << "  ";
        }
        out << "Alias: " << expr->alias << std::endl;
    }
}

void printTableRef(std::ostream& out, const hsql::TableRef* table, int level) {
    if (!table) return;

    for (int i = 0; i < level; ++i) {
        out << "  ";
    }

    switch (table->type) {
        case hsql::kTableName:
            out << "Table name: " << table->name;
            if (table->alias) {
                out << " Alias: " << table->alias;
            }
            break;
        case hsql::kTableSelect:
            out << "Table select:" << std::endl;
            if (table->select) {
                printSelectStatement(out, table->select, level + 1);
            }
            break;
        case hsql::kTableJoin:
            out << "Table join:" << std::endl;
            if (table->join) {
                out << "  Left: " << std::endl;
                printTableRef(out, table->join->left, level + 1);
                out << "  Right: " << std::endl;
                printTableRef(out, table->join->right, level + 1);
                out << "  Condition: " << std::endl;
                printExpression(out, table->join->condition, level + 1);
            }
            break;
        default:
            out << "Table type: " << table->type;
            break;
    }
    out << std::endl;
}

void printSelectStatement(std::ostream& out, const hsql::SelectStatement* selectStmt, int level) {
    if (!selectStmt) return;

    for (int i = 0; i < level; ++i) {
        out << "  ";
    }

    if (selectStmt->selectList) {
        out << "SELECT list:" << std::endl;
        for (const auto* expr : *selectStmt->selectList) {
            printExpression(out, expr, level + 1);
        }
    }

    if (selectStmt->fromTable) {
        out << "From table:" << std::endl;
        printTableRef(out, selectStmt->fromTable, level + 1);
    }

    if (selectStmt->whereClause) {
        out << "WHERE clause:" << std::endl;
        printExpression(out, selectStmt->whereClause, level + 1);
    }

    if (selectStmt->groupBy) {
        out << "GROUP BY:" << std::endl;
        for (const auto* expr : *selectStmt->groupBy->columns) {
            printExpression(out, expr, level + 1);
        }
        if (selectStmt->groupBy->having) {
            out << "HAVING:" << std::endl;
            printExpression(out, selectStmt->groupBy->having, level + 1);
        }
    }

    if (selectStmt->order) {
        out << "ORDER BY:" << std::endl;
        for (const auto* order : *selectStmt->order) {
            for (int i = 0; i < level + 1; ++i) {
                out << "  ";
            }
            printExpression(out, order->expr, 0);
            out << (order->type == hsql::kOrderAsc ? " ASC" : " DESC") << std::endl;
        }
    }

    if (selectStmt->limit) {
        out << "LIMIT:" << std::endl;
        if (selectStmt->limit->limit) {
            for (int i = 0; i < level + 1; ++i) {
                out << "  ";
            }
            out << "Limit: " << selectStmt->limit->limit->ival << std::endl;
        }
        if (selectStmt->limit->offset) {
            for (int i = 0; i < level + 1; ++i) {
                out << "  ";
            }
            out << "Offset: " << selectStmt->limit->offset->ival << std::endl;
        }
    }
}
