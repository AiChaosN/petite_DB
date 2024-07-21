#include <iostream>
#include "SqlToAst/SqlToAst.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <path_to_sql_file> <path_to_output_file>" << std::endl;
        return 1;
    }

    std::string sqlFilePath = argv[1];
    std::string outputFilePath = argv[2];
    SqlToAst sqlToAst(sqlFilePath);

    if (sqlToAst.parseSql()) {
        sqlToAst.printAst(outputFilePath);
    } else {
        std::cerr << "Failed to parse SQL file." << std::endl;
        return 1;
    }

    return 0;
}
