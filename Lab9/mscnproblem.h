#ifndef MSCNPROBLEM_H
#define MSCNPROBLEM_H
#include <string>
#include <vector>
#include <array>
#include <fstream>
#include <sstream>
#include "matrix.h"
#include "matrixhelper.h"

struct MscnSolution
{
    Matrix<double> xd;
    Matrix<double> xf;
    Matrix<double> xm;
};

class MscnProblem
{
public:
    MscnProblem();
    MscnProblem(std::istream &is);

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

    std::vector<std::array<double, 2>> getMinMaxValues();
    double getQuality(double *solution, int arrSize, int &errorCode);
    bool constraintsSatisfied(double *solution, int arrSize, int &errorCode);

    std::string serialize();

    void save(std::string const &path);

    friend std::ostream& operator<< (std::ostream &os, const MscnProblem &problem);
private:
    int dCount;
    int fCount;
    int mCount;
    int sCount;
    Matrix<double> cd;
    Matrix<double> cf;
    Matrix<double> cm;

    std::vector<double> sd;
    std::vector<double> sf;
    std::vector<double> sm;
    std::vector<double> ss;
    std::vector<double> ud;
    std::vector<double> uf;
    std::vector<double> um;
    std::vector<double> ps;

    bool setInMatrix(Matrix<double> &mat, double value, int i, int j);
    bool setInVector(std::vector<double> &vec, double value, int i);
    int technicalCheck(double *solution, int arrSize);
    double getKt(Matrix<double> &xd, Matrix<double> &xf, Matrix<double> &xm);
    double getKu(Matrix<double> &xd, Matrix<double> &xf, Matrix<double> &xm);
    double getP(Matrix<double> &xm);
    double getProfit(Matrix<double> &xd, Matrix<double> &xf, Matrix<double> &xm);
    MscnSolution parseSolution(double *solution);
};

#endif // MSCNPROBLEM_H
