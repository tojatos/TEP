#ifndef DIFFEVOL_H
#define DIFFEVOL_H
#include "mscnproblem.h"
#include "randomsearch.h"
#include "diffindividual.h"
#include "diffhelper.h"
#include "optimizer.h"

class DiffEvol : Optimizer
{
public:
    DiffEvol() {}
    DiffEvol(Problem *p) { this->problem = p; }
    DiffIndividual getBestFound() const override;
    DiffIndividual getBestFound(const int maxIteration) const override;
private:
    Table<DiffIndividual> initPopulation(const int populationNumber) const;
    int getIndexFromTournament(int size, Table<DiffIndividual> &pop, Random &r) const;
    Table<double> getMutatedGenotype(const Table<double> &base, const Table<double> &addInd0, const Table<double> &addInd1, const Table<Table<double> > &minmax, Random &r) const;
    int populationNumber = DEF_DIFF_EVOL_POP_NUMBER;
};

#endif // DIFFEVOL_H
