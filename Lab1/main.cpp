#include <iostream>
#include "constants.h"

void print_table(int *table, int size)
{
    for(int i = 0; i < size; ++i)
    {
        std::cout << table[i] << ' ';
    }
    std::cout << '\n';
}
void print_table(int **table, int sizeX, int sizeY)
{
    for(int i = 0; i < sizeX; ++i)
    {
        for(int j = 0; j < sizeY; ++j)
        {
            std::cout << table[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

void alloc_table_add_5(int size)
{
    if(size <= 0) return;

    int *table = new int[size];
    for(int i = 0; i < size; ++i)
    {
        table[i] = i+5;
    }
    delete [] table;
}

bool alloc_table_2_dim(int ***table, int sizeX, int sizeY)
{
    if(sizeX <= 0 || sizeY <= 0) return false;

    *table = new int *[sizeX];
    for(int i = 0; i < sizeX; ++i)
    {
        (*table)[i] = new int[sizeY];
    }
    return true;
}

bool dealloc_table_2_dim(int **table, int sizeX)
{
    if(sizeX <= 0) return false;

    for(int i = 0; i < sizeX; ++i)
    {
        delete[] table[i];
    }
    delete[] table;
    return true;
}

bool alloc_triangle_mat(double ***mat, int size)
{
    if(size <= 0) return false;

    *mat = new double *[size];

    for(int i = 0; i < size; ++i)
    {
        (*mat)[i] = new double[i+1];
    }
    return true;
}

bool dealloc_triangle_mat(double **mat, int size)
{
    if(size <= 0) return false;

    for(int i = 0; i < size; ++i)
    {
        delete[] mat[i];
    }
    delete[] mat;
    return true;
}

int main()
{
    alloc_table_add_5(Z1_TABLE_SIZE);
    int ** table;

    bool isAllocated = alloc_table_2_dim(&table, Z2_TABLE_SIZE_X, Z2_TABLE_SIZE_Y);
//    std::cout << "Is Allocated: " << isAllocated << '\n';
    if(isAllocated)
    {
        dealloc_table_2_dim(table, Z2_TABLE_SIZE_X);
//        bool isDeallocated = dealloc_table_2_dim(table, Z2_TABLE_SIZE_X);
//        std::cout << "Is Deallocated: " << isDeallocated << '\n';
    }

    double ** triangleMat;
    bool isTriAllocated = alloc_triangle_mat(&triangleMat, TRI_MAT_SIZE);
    if(isTriAllocated)
    {
        dealloc_triangle_mat(triangleMat, TRI_MAT_SIZE);
    }

    return 0;
}
