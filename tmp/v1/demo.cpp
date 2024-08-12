#include <iostream>
#include <fstream>
#include <sstream>
#include "hsql/SQLParser.h"


int main()
{
    std::cout << "Hello, World!" << std::endl;
    // Basic Usage Example
    const std::string query = "SELECT a, b FROM test_table WHERE c = 10;";
    hsql::SQLParserResult result;
    hsql::SQLParser::parse(query, &result);

    if (result.isValid() && result.size() > 0) {
        const hsql::SQLStatement* statement = result.getStatement(0);

        if (statement->isType(hsql::kStmtSelect)) {
            const auto* select = static_cast<const hsql::SelectStatement*>(statement);
            /* ... */
        }
    }
}