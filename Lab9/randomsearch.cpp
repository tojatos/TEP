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
    this->problem = MySmartPointer<MscnProblem>(problem);
}

Table<double> RandomSearch::getBestFound() const
{
    MscnProblem p = *problem.get();
    int solutionSize = p.getSolutionLength();
    Table<double> solution(solutionSize);
    Table<double> bestSolution(solutionSize);
    int bestQuality;
    bool firstQualitySet = false;
    Table<Table<double>> minMaxValues = p.getMinMaxValues();
    Random r;

    for(int i = 0; i < solutionSize; ++i)
       solution[i] = r.next(minMaxValues[i][0], minMaxValues[i][1]);

    int err;
    bool s = p.constraintsSatisfied(*solution, solutionSize, err);
    if(err==E_OK && s)
    {
        int quality = p.getQuality(*solution, solutionSize, err);
        if(err==E_OK)
        {
            if(!firstQualitySet)
            {
                bestQuality = quality;
                bestSolution = solution;
                firstQualitySet = true;
            }
            else if (quality > bestQuality) {
                bestQuality = quality;
                bestSolution = solution;
            }
        }

    }




}
