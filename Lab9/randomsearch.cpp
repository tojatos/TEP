#include "randomsearch.h"

RandomSearch::RandomSearch()
{
}

RandomSearch::RandomSearch(MscnProblem *problem)
{
    setProblem(problem);
}

void RandomSearch::setProblem(MscnProblem *problem)
{
    this->problem = problem;
}

Table<double> RandomSearch::getBestFound() const
{
    return getBestFound(DEF_RANDOM_SEARCH_MAX_ITER);
}

Table<double> RandomSearch::getBestFound(int maxIteration) const
{
    MscnProblem p = *problem;
    int solutionSize = p.getSolutionLength();
    Table<double> solution(solutionSize);
    Table<double> bestSolution(solutionSize);
    double bestQuality = 0;
    Table<Table<double>> minMaxValues = p.getMinMaxValues();
    Random r;

    while(maxIteration--)
    {
        for(int i = 0; i < solutionSize; ++i)
            solution[i] = r.next(minMaxValues[i][0], minMaxValues[i][1]);

        int err;
        bool s = p.constraintsSatisfied(*solution, solutionSize, err);
        if(err==E_OK && s)
        {
            double quality = p.getQuality(*solution, solutionSize, err);
            if(err==E_OK && quality > bestQuality)
            {
                bestQuality = quality;
                bestSolution = solution;
            }
        }
    }
    return bestSolution;
}
