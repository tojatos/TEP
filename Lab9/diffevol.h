#ifndef DIFFEVOL_H
#define DIFFEVOL_H
#include "mscnproblem.h"
#include "randomsearch.h"
#include "diffindividual.h"
#include "diffhelper.h"

class DiffEvol
{
public:
    DiffEvol();
    DiffEvol(MscnProblem *problem);
    void setProblem(MscnProblem *problem);
    DiffIndividual getBestFound() const;
    DiffIndividual getBestFound(const int maxIteration, const int populationNumber) const;
private:
    Table<DiffIndividual> initPopulation(const int populationNumber) const;
    MscnProblem* problem = NULL;
};

#endif // DIFFEVOL_H
