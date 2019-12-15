#ifndef TABLE_H
#define TABLE_H
#include "mysmartpointer.h"
#include "constants.h"
#include "streamhelper.h"
#include <string>
#include <sstream>

template <typename T>
class Table
{
public:
    Table()
    {
        resize(DEF_MAT_WIDTH);
    }
    Table(int width)
    {
        resize(width);
    }
    Table(std::istream &is, int width)
    {
        resize(width);
        for(int i = 0; i < width; ++i)
        {
            set(stream_get<T>(is), i);
        }
    }
    void resize(int width)
    {
        this->width = width;
        table = MySmartPointer<T>(new T[width](), true);
    }
    void set(T val, int i)
    {
        table[i] = val;
    }
    T get(int i) const
    {
        return table[i];
    }

    T& operator[](int i) const
    {
        return table[i];
    }

    int size() { return width; }

    friend std::ostream& operator<< (std::ostream &os, const Table &table)
    {
        for(int i = 0; i < table.width; ++i)
        {
            os << table.get(i) << ' ';
        }
        os << '\n';
        return os;
    }
private:
    MySmartPointer<T> table = NULL;
    int width;
};

#endif // TABLE_H
