#ifndef RANDOMSEARCH_H
#define RANDOMSEARCH_H
#include "mscnproblem.h"
#include "random.h"

class RandomSearch
{
public:
    RandomSearch();
    RandomSearch(MscnProblem *problem);
    void setProblem(MscnProblem *problem);
    Table<double> getBestFound() const;
private:
    MySmartPointer<MscnProblem> problem = NULL;
};

#endif // RANDOMSEARCH_H
