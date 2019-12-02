#ifndef MSCNPROBLEM_H
#define MSCNPROBLEM_H
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "matrix.h"

class MscnProblem
{
public:
    MscnProblem();

    bool setDCount(int newCount);
    bool setFCount(int newCount);
    bool setMCount(int newCount);
    bool setSCount(int newCount);

    bool setInCd(double value, int i, int j);
    bool setInEf(double value, int i, int j);
    bool setInCm(double value, int i, int j);

    std::string serialize();
    MscnProblem deserialize(std::string const &str);

    void save(std::string const &path);
    MscnProblem load(std::string const &path);
private:
    int dCount;
    int fCount;
    int mCount;
    int sCount;
    Matrix<double> cd;
    Matrix<double> ef;
    Matrix<double> cm;

    std::vector<double> sd;
    std::vector<double> sf;
    std::vector<double> sm;
    std::vector<double> ss;

    //TODO: vectors ud, uf, um, ps?

    std::string serialize(std::vector<double> const &vec);
    bool setInMatrix(Matrix<double> &mat, double value, int i, int j);
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
