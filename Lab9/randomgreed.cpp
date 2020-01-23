#include "randomgreed.h"

void RandomGreed::iterate()
{
  int solutionLength = problem->getSolutionLength();
  RandomSearch rs(problem);
  DiffIndividual candidateSolution = rs.getNextInd();
  double lambda;
  Table<Table<double>> minmax = problem->getMinMaxValues();
  Table<double> base = candidateSolution.getGenotype();
  for(int i = 0; i < solutionLength; ++i)
  {
    lambda = r.next(RAND_GREED_LAMBDA_START, RAND_GREED_LAMBDA_END);
    Table<double> candA(base);
    Table<double> candB(base);
    candA.set(clamp(base[i] - lambda, minmax[i][0], minmax[i][1]), i);
    candB.set(clamp(base[i] + lambda, minmax[i][0], minmax[i][1]), i);

    while(getQuality(candA) > getQuality(base))
    {
      base = candA;
      candA.set(clamp(base[i] - lambda, minmax[i][0], minmax[i][1]), i);
    }
    while(getQuality(candB) > getQuality(base))
    {
      base = candB;
      candB.set(clamp(base[i] + lambda, minmax[i][0], minmax[i][1]), i);
    }
  }
  candidateSolution.setGenotype(base);
  candidateSolution.setFitness(getQuality(base));
  if(candidateSolution.getFitness() > best.getFitness())
  {
    std::cerr << "Fitness: " << candidateSolution.getFitness() << '\n';
    best = candidateSolution;
  }
}

double RandomGreed::getQuality(Table<double> sol)
{
  int err;
  double quality = problem->getQuality(*sol, sol.size(), err);
  return (err == E_OK) ? quality : -1;
}
