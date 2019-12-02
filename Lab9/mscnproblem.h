#ifndef MSCNPROBLEM_H
#define MSCNPROBLEM_H
#include <string>


class MscnProblem
{
public:
    MscnProblem();

    bool setDCount(int newCount);
    bool setFCount(int newCount);
    bool setMCount(int newCount);
    bool setSCount(int newCount);

    std::string serialize();
    MscnProblem deserialize(std::string str);
private:
    int dCount;
    int fCount;
    int mCount;
    int sCount;
};

struct MscmQualityResult
{
    int errorCode;
    double result;
};

struct MscmConstraintsResult
{
    int errorCode;
    bool areSatisfied;
};

#endif // MSCNPROBLEM_H
