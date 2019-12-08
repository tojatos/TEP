#ifndef MATRIXHELPER_H
#define MATRIXHELPER_H

#include "matrix.h"

template <typename T>
bool anyHigherThanZeroInARow(Matrix<T> &mat, int row)
{
    bool found = false;
    int width = mat.getWidth();

    for(int j = 0; j < width && !found; ++j)
    {
        if(mat.get(row, j) > 0) found = true;
    }

    return found;
}

template <typename T>
T sumInARow(Matrix<T> &mat, int row)
{
    T res = 0;
    int width = mat.getWidth();

    for(int j = 0; j < width; ++j)
    {
        res += mat.get(row, j);
    }

    return res;
}

template <typename T>
T sumInAColumn(Matrix<T> &mat, int column)
{
    T res = 0;
    int height = mat.getHeight();

    for(int i = 0; i < height; ++i)
    {
        res += mat.get(i, column);
    }

    return res;
}

#endif // MATRIXHELPER_H
