#include "table.h"

Table::Table()
{
    this->name = DEFAULT_TABLE_NAME;
    std::cout << "bezp: " << this->name << '\n';
    this->table = new int[DEFAULT_TABLE_LEN];
}

Table::Table(std::string name, int tableLen)
{
    this->name = name;
    std::cout << "parametr: " << this->name;
    this->table = new int[tableLen];
    this->tableLen = tableLen;
}

Table::Table(const Table &other)
{
    this->name = other.name + "_copy";
    this->tableLen = other.tableLen;
    this->table = new int[this->tableLen];
    for(int i = 0; i < this->tableLen; ++i)
    {
        this->table[i] = other.table[i];
    }
    std::cout << "kopiuj: " << this->name;
}

Table::~Table()
{
    std::cout << "usuwam: " << this->name;
}

void Table::setName(std::string name)
{
    this->name = name;
}

bool Table::setNewSize(int tableLen)
{
    if(tableLen <= 0) return false;
    this->table = new int [tableLen];
    return true;
}

Table *Table::clone()
{

}
