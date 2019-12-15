#ifndef MSCNPROBLEM_H
#define MSCNPROBLEM_H
#include <string>
#include <array>
#include <fstream>
#include <sstream>
#include "matrix.h"
#include "table.h"
#include "matrixhelper.h"
#include "streamhelper.h"
#include "tablehelper.h"

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
    bool setInCf(double value, int i, int j);
    bool setInCm(double value, int i, int j);

    bool setInSd(double value, int i);
    bool setInSf(double value, int i);
    bool setInSm(double value, int i);
    bool setInSs(double value, int i);
    bool setInUd(double value, int i);
    bool setInUf(double value, int i);
    bool setInUm(double value, int i);
    bool setInPs(double value, int i);

    bool setInXdminmax(double value, int i, int j, int k);
    bool setInXfminmax(double value, int i, int j, int k);
    bool setInXmminmax(double value, int i, int j, int k);

    Table<Table<double>> getMinMaxValues();
    double getQuality(double const * solution, int arrSize, int &errorCode);
    bool constraintsSatisfied(double const * solution, int arrSize, int &errorCode);

    void generateInstance(int intanceSeed);

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

    Table<double> sd;
    Table<double> sf;
    Table<double> sm;
    Table<double> ss;
    Table<double> ud;
    Table<double> uf;
    Table<double> um;
    Table<double> ps;

    Matrix<Table<double>> xdminmax;
    Matrix<Table<double>> xfminmax;
    Matrix<Table<double>> xmminmax;

    void specialRead(Matrix<Table<double>> &mat, std::istream &is, int width, int height);
    void specialResize(Matrix<Table<double>> &mat, int width, int height);
    int technicalCheck(double const * solution, int arrSize);
    double getKt(Matrix<double> &xd, Matrix<double> &xf, Matrix<double> &xm);
    double getKu(Matrix<double> &xd, Matrix<double> &xf, Matrix<double> &xm);
    double getP(Matrix<double> &xm);
    double getProfit(Matrix<double> &xd, Matrix<double> &xf, Matrix<double> &xm);
    MscnSolution parseSolution(double const * solution);
};

#endif // MSCNPROBLEM_H
