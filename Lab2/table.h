#ifndef TABLE_H
#define TABLE_H
#include <string>
#include <iostream>
#include "constants.h"

class Table
{
public:
    Table();
    Table(std::string name, int tableLen);
    Table(const Table &other);
    ~Table();
    void setName(std::string name);
    bool setNewSize(int tableLen);
    Table *clone();
private:
    std::string name;
    int *table;
    int tableLen;
};

#endif // TABLE_H
