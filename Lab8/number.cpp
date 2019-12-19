#include "number.h"

Number::Number(double number)
{
    val = new double(number);

    std::cout << "Default\n";
}

Number::Number(const Number &other)
{
    val = new double(*other.val);
    std::cout << "Copy\n";
}

Number::Number(Number &&other)
{
    val = other.val;
    other.val = NULL;
    std::cout << "Move\n";
}

Number::~Number()
{
    std::cout << "Dest\n";
    delete val;
}

Number& Number::operator=(const Number &other)
{
    std::cout << "Copy OP\n";
    delete val;
    val = new double(*other.val);
    return *this;
}

Number& Number::operator=(Number &&other)
{
    std::cout << "Move OP\n";
    delete val;
    val = other.val;
    other.val = NULL;
    return *this;
}
