#include "diffevol.h"

DiffEvol::DiffEvol()
{

}

DiffEvol::DiffEvol(MscnProblem *problem)
{
    this->problem = problem;
}

void DiffEvol::setProblem(MscnProblem *problem)
{
    this->problem = problem;
}

Table<double> DiffEvol::getBestFound() const
{
    return getBestFound(DEF_DIFF_EVOL_MAX_ITER);
}

Table<double> DiffEvol::getBestFound(int maxIteration) const
{
    Table<DiffIndividual> pop = initPopulation();
    int solLen = problem->getSolutionLength();
    while (maxIteration--) {

    }

}

Table<DiffIndividual> DiffEvol::initPopulation() const
{
    RandomSearch rs(problem);
    return NULL; // TODO
//    return rs.getBestFound();
}
