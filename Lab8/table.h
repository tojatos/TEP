#ifndef TABLE_H
#define TABLE_H
#include <string>
#include <iostream>
#include <vector>
#include <cstring>
#include "constants.h"
#include "helper.h"

class Table
{
public:
    Table();
    Table(std::string name, int tableLen);
    Table(const Table &other);
    Table(Table &&other);
    ~Table();
    void setName(std::string name);
    bool setNewSize(int tableLen);
    Table *clone();
    Table operator+(Table &other);
    Table operator-(Table &other);
    Table& operator=(const Table &other);
    bool acc(Table &other);
    void printTable();
    int getValue(int offset);
    void setValue(int offset, int value);
private:
    std::string name;
    int *table;
    int tableLen;
};

#endif // TABLE_H
