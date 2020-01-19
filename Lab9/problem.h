#ifndef PROBLEM_H
#define PROBLEM_H
#include "table.h"

class Problem
{
public:
    virtual Table<Table<double>> getMinMaxValues() const = 0;
    virtual double getQuality(double const * solution, int arrSize, int &errorCode) const = 0;
    virtual int getSolutionLength() const = 0;
    virtual ~Problem() {}
};

#endif // PROBLEM_H
