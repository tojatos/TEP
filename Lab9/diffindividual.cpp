#include "diffindividual.h"

DiffIndividual::DiffIndividual()
{

}

DiffIndividual::DiffIndividual(double fitness, Table<double> &genotype)
{
    this->fitness = fitness;
    this->genotype = genotype;
}

double DiffIndividual::getFitness() const { return fitness; }
void DiffIndividual::setFitness(double value) { fitness = value; }
Table<double> DiffIndividual::getGenotype() const { return genotype; }
void DiffIndividual::setGenotype(const Table<double> &value) { genotype = value; }
void DiffIndividual::setGenotypeAt(const double value, const int offset) const
{
    this->genotype[offset] = value;
}
