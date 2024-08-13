#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include <string>
#include <unordered_map>
#include <variant>

// 定义数据类型，可以是int或float
using DataType = std::vector<int, float>;

// 行类，表示一行数据
class Row {
public:
    std::vector<DataType> data;

    Row() = default;
    explicit Row(const std::vector<DataType>& row_data);
};

// 表类，表示一个表
class Table {
public:
    std::vector<std::string> column_names;
    std::vector<Row> rows;

    Table() = default;
    Table(const std::vector<std::string>& col_names);

    void addRow(const Row& row);
};

// 数据库类，管理多个表
class Database {
private:
    std::unordered_map<std::string, Table> tables;

public:
    Database() = default;

    void createTable(const std::string& table_name, const std::vector<std::string>& column_names);
    void addRowToTable(const std::string& table_name, const Row& row);
    void loadCSV(const std::string& table_name, const std::string& file_path);
    void printTable(const std::string& table_name) const;
};

#endif // DATABASE_H
