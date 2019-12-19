#ifndef NUMBER_H
#define NUMBER_H

#include<iostream>

class Number
{
public:
    Number(double number);
    Number(const Number &other);
    Number(Number &&other);
    ~Number();

    Number& operator=(const Number &other);
    Number& operator=(Number &&other);
private:
    double *val;
};

#endif // NUMBER_H
