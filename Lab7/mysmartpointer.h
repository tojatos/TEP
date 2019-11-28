#ifndef MYSMARTPOINTER_H
#define MYSMARTPOINTER_H
#include "refcounter.h"

template<typename T>
class MySmartPointer
{
public:
    MySmartPointer(T *pointer)
    {
        this->pointer = pointer;
        counter = new RefCounter();
        counter->add();
    }
    MySmartPointer(const MySmartPointer &other)
    {
        pointer = other.pointer;
        counter = other.counter;
        counter->add();
    }
    ~MySmartPointer()
    {
        if(counter->dec() == 0)
        {
            delete pointer;
            delete counter;
        }
    }

    T& operator*() { return(*pointer); }
    T* operator->() { return(pointer); }
    void operator=(const MySmartPointer &other)
    {
        if(counter->dec() == 0)
        {
            delete pointer;
            delete counter;
        }
        pointer = other.pointer;
        counter = other.counter;
        counter->add();
    }
private:
    T *pointer;
    RefCounter* counter;
};

#endif // MYSMARTPOINTER_H
