#include <iostream>
#include "constants.h"
#include "mysmartpointer.h"

int* createInt()
{
    return new int;
}
int* createIntArr()
{
    return new int[6];
}
int main()
{
    MySmartPointer<int> ptr = MySmartPointer<int>(createInt());
    MySmartPointer<int> other = ptr;
    MySmartPointer<int> other2 = MySmartPointer<int>(createInt());
    other = ptr;
    other2 = ptr;
    *ptr = 4;

//    other.at(5);

    std::cout << *other << *other2 << '\n';

    MySmartPointer<int> arrPoint = MySmartPointer<int>(createIntArr(), true);
    *(&*arrPoint+0) = 61;
    *(&*arrPoint+1) = 68;
    *(&*arrPoint+2) = 69;

    std::cout << arrPoint.at(1) << '\n';
    std::cout << arrPoint.at(2) << '\n';
    std::cout << arrPoint.at(0) << '\n';
    return 0;
}
