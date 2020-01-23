#ifndef RANDDOMGREED_H
#define RANDDOMGREED_H
#include "problem.h"
#include "randomsearch.h"
#include "diffindividual.h"
#include "diffhelper.h"
#include "optimizer.h"
#include <iostream>

class RandomGreed : public Optimizer
{
public:
  RandomGreed(Problem *p)
  {
    this->problem = p;
    RandomSearch rs(problem);
    best = rs.getNextInd();
  }
  void iterate() override;

  DiffIndividual getBestFound() const override { return best; }

private:
  Random r;
  DiffIndividual best;
  double getQuality(Table<double> sol);
};

#endif // RANDDOMGREED_H
