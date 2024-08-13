#include "Database.h"
#include <iostream>
#include <fstream>
#include <sstream>

// Row类的构造函数
Row::Row(const std::vector<DataType>& row_data) : data(row_data) {}

// Table类的构造函数
Table::Table(const std::vector<std::string>& col_names) : column_names(col_names) {}

// 向表中添加一行
void Table::addRow(const Row& row) {
    rows.push_back(row);
}

// 创建一个新表
void Database::createTable(const std::string& table_name, const std::vector<std::string>& column_names) {
    tables[table_name] = Table(column_names);
}

// 向指定表添加一行数据
void Database::addRowToTable(const std::string& table_name, const Row& row) {
    if (tables.find(table_name) != tables.end()) {
        tables[table_name].addRow(row);
    } else {
        std::cerr << "Table " << table_name << " does not exist!" << std::endl;
    }
}

// 从CSV文件加载数据到表
void Database::loadCSV(const std::string& table_name, const std::string& file_path) {
    std::ifstream file(file_path);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << file_path << std::endl;
        return;
    }

    std::string line;
    std::vector<std::string> column_names;
    bool is_header = true;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string cell;
        std::vector<DataType> row_data;

        while (std::getline(ss, cell, ',')) {
            if (is_header) {
                column_names.push_back(cell);
            } else {
                try {
                    if (cell.find('.') != std::string::npos) {
                        row_data.push_back(std::stof(cell)); // 浮点数
                    } else {
                        row_data.push_back(std::stoi(cell)); // 整数
                    }
                } catch (const std::invalid_argument&) {
                    std::cerr << "Invalid data encountered in the CSV file: " << cell << std::endl;
                    return;
                }
            }
        }

        if (is_header) {
            createTable(table_name, column_names);
            is_header = false;
        } else {
            addRowToTable(table_name, Row(row_data));
        }
    }

    file.close();
}

// 打印表的内容
void Database::printTable(const std::string& table_name) const {
    if (tables.find(table_name) != tables.end()) {
        const Table& table = tables.at(table_name);
        for (const auto& col_name : table.column_names) {
            std::cout << col_name << "\t";
        }
        std::cout << std::endl;

        for (const auto& row : table.rows) {
            for (const auto& data : row.data) {
                std::visit([](auto&& arg) { std::cout << arg << "\t"; }, data);
            }
            std::cout << std::endl;
        }
    } else {
        std::cerr << "Table " << table_name << " does not exist!" << std::endl;
    }
}
