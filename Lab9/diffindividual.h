#ifndef DIFFINDIVIDUAL_H
#define DIFFINDIVIDUAL_H
#include "mscnproblem.h"


class DiffIndividual
{
public:
    DiffIndividual();
    DiffIndividual(double fitness, Table<double> &genotype);
    double getFitness() const;
    void setFitness(double value);

    Table<double> getGenotype() const;
    void setGenotype(const Table<double> &value);
    void setGenotypeAt(const double value, const int offset) const;

private:
    Table<double> genotype;
    double fitness;
};

#endif // DIFFINDIVIDUAL_H
