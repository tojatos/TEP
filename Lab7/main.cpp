#include <iostream>
#include "constants.h"
#include "mysmartpointer.h"

int* createInt()
{
    return new int;
}
int main()
{
    MySmartPointer<int> ptr = MySmartPointer<int>(createInt());
    MySmartPointer<int> other = ptr;
    MySmartPointer<int> other2 = MySmartPointer<int>(createInt());
    other = ptr;
    other2 = ptr;
    *ptr = 4;

    std::cout << *other << *other2;
    return 0;
}
