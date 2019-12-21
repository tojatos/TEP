#ifndef DIFFEVOL_H
#define DIFFEVOL_H
#include "mscnproblem.h"
#include "randomsearch.h"
#include "diffindividual.h"

class DiffEvol
{
public:
    DiffEvol();
    DiffEvol(MscnProblem *problem);
    void setProblem(MscnProblem *problem);
    Table<double> getBestFound() const;
    Table<double> getBestFound(int maxIteration) const;
private:
    Table<DiffIndividual> initPopulation() const;
    MscnProblem* problem = NULL;
};

#endif // DIFFEVOL_H
