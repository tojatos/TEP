#ifndef MATRIX_H
#define MATRIX_H
#include "mysmartpointer.h"
#include "constants.h"
#include <string>
#include <sstream>

template <typename T>
class Matrix
{
public:
    Matrix()
    {
        resize(DEF_MAT_WIDTH, DEF_MAT_HEIGHT);
    }
    Matrix(int width, int height)
    {
        resize(width, height);
    }
    void resize(int width, int height)
    {
        this->width = width;
        this->height = height;
        T* ptr = new T[width*height];
        matrix = MySmartPointer<T>(ptr, true);
    }
    void set(T val, int i, int j)
    {
        matrix[i * width + j] = val;
    }
    T get(int i, int j)
    {
        return matrix[i * width + j];
    }

    std::string serialize()
    {
        std::ostringstream os;
        os << width << ' ' << height;
        os << '\n';
        for(int i = 0; i < height; ++i)
        {
            for(int j = 0; j < width; ++j)
            {
                os << get(i, j) << ' ';
            }
            os << '\n';
        }

        return os.str();
    }
    Matrix<T> deserialize(std::string str)
    {
        std::istringstream is(str);
        is >> width >> height;
        Matrix<T> newMatrix(width, height);
        for(int i = 0; i < height; ++i)
        {
            for(int j = 0; j < width; ++j)
            {
                T tmp;
                is >> tmp;
                newMatrix.set(tmp, i, j);
            }
        }
        return newMatrix;
    }
private:
    MySmartPointer<T> matrix = NULL;
    int width;
    int height;
};

#endif // MATRIX_H
