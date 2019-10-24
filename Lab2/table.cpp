#include "table.h"
#include "helper.h"

Table::Table()
{
    this->name = DEFAULT_TABLE_NAME;
    std::cout << "bezp: " << this->name << '\n';
    this->table = new int[DEFAULT_TABLE_LEN];
    this->tableLen = DEFAULT_TABLE_LEN;
}

Table::Table(std::string name, int tableLen)
{
    this->name = name;
    std::cout << "parametr: " << this->name << '\n';
    this->table = new int[tableLen];
    this->tableLen = tableLen;
}

Table::Table(const Table &other)
{
    this->name = other.name + "_copy";
    this->tableLen = other.tableLen;
    this->table = new int[this->tableLen];
    copy_table(other.table, this->table, this->tableLen);
    std::cout << "kopiuj: " << this->name << '\n';
}

Table::~Table()
{
    delete[] this->table;
    std::cout << "usuwam: " << this->name << '\n';
}

void Table::setName(std::string name)
{
    this->name = name;
}

bool Table::setNewSize(int tableLen)
{
    if(tableLen <= 0) return false;
    if(tableLen == this->tableLen) return true;
    int *newTable = new int [tableLen];
    if(this->tableLen >= tableLen)
    {
        copy_table(this->table, newTable, tableLen);
    }
    else
    {
        copy_table(this->table, newTable, this->tableLen);
    }
    delete[] this->table;
    this->table = newTable;
    this->tableLen = tableLen;
    return true;
}

Table *Table::clone()
{
    return new Table(*this);
}
