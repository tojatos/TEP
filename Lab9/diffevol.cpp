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

DiffIndividual DiffEvol::getBestFound() const
{
    return getBestFound(DEF_DIFF_EVOL_MAX_ITER, DEF_DIFF_EVOL_POP_NUMBER);
}

DiffIndividual DiffEvol::getBestFound(const int maxIteration, const int populationNumber) const
{
    Table<DiffIndividual> pop = initPopulation(populationNumber);
    Random r;
    int solLen = problem->getSolutionLength();
    int baseIndex, addIndex0, addIndex1;
    for (int i = 0; i < maxIteration; ++i) {
        Table<double> solNew(solLen);
        for(int j = 0; j < populationNumber; ++j)
        {
            do {
              baseIndex = r.next(0, populationNumber-1);
              addIndex0 = r.next(0, populationNumber-1);
              addIndex1 = r.next(0, populationNumber-1);
            } while(!areDifferent(j, baseIndex, addIndex0, addIndex1));
            for(int geneOffset = 0; geneOffset < solLen; ++geneOffset)
            {
                if(r.next(0.0, 1.0) < DEF_DIFF_EVOL_CROSS_PROB)
                {
                    solNew[geneOffset] = pop[baseIndex].getGenotype()[geneOffset] + DEF_DIFF_EVOL_DIFF_WEIGHT *
                            (pop[addIndex0].getGenotype()[geneOffset] - pop[addIndex1].getGenotype()[geneOffset]);
                }
                else
                    solNew[geneOffset] = pop[j].getGenotype()[geneOffset];
            }
            int err;
            bool cs = problem->constraintsSatisfied(*solNew, solLen, err);
            if(err==E_OK && cs)
            {
              double newQuality = problem->getQuality(*solNew, solLen, err);
              if(err==E_OK && (newQuality - DEF_DIFF_EVOL_EPSILON) >= pop[j].getFitness())
              {
                  pop[j] = DiffIndividual(newQuality, solNew);
                  std::cerr << "Fitness: " << newQuality << '\n';
  //                std::cerr << "Solution: " << solNew << '\n';
              }
            }
        }
    }
    DiffIndividual bestInd = pop[0];
    for(int i = 1; i < populationNumber; ++i)
    {
        if(pop[i].getFitness() > bestInd.getFitness())
            bestInd = pop[i];
    }
    return bestInd;
}

Table<DiffIndividual> DiffEvol::initPopulation(const int populationNumber) const
{
    RandomSearch rs(problem);
//    int solLen = problem->getSolutionLength();
    Table<DiffIndividual> res(populationNumber);
    for(int i = 0; i < populationNumber; ++i)
    {
//        Table<double> sol = rs.getBestFound(1); // get first valid value
        int err;
        Table<double> sol = rs.getNextValid();
//        Table<double> sol(solLen);
//        for(int j = 0; j < solLen; )
        double val = problem->getQuality(*sol, sol.size(), err);
        res[i] = DiffIndividual(val, sol);
        std::cerr << "Initializing: " << sol << '\n';
    }
    return res;
}
