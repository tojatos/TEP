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

    bool setInSd(double value, int i);
    bool setInSf(double value, int i);
    bool setInSm(double value, int i);
    bool setInSs(double value, int i);
    bool setInUd(double value, int i);
    bool setInUf(double value, int i);
    bool setInUm(double value, int i);
    bool setInPs(double value, int i);

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
    std::vector<double> ud;
    std::vector<double> uf;
    std::vector<double> um;
    std::vector<double> ps;

    std::string serialize(std::vector<double> const &vec);
    bool setInMatrix(Matrix<double> &mat, double value, int i, int j);
    bool setInVector(std::vector<double> &vec, double value, int i);
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
