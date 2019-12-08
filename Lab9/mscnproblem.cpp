#include "mscnproblem.h"

MscnProblem::MscnProblem()
{
    dCount = DEF_MSCN_D;
    fCount = DEF_MSCN_F;
    mCount = DEF_MSCN_M;
    sCount = DEF_MSCN_S;

    cd = Matrix<double>(fCount, dCount);
    cf = Matrix<double>(mCount, fCount);
    cm = Matrix<double>(sCount, mCount);

    sd.resize(dCount);
    ud.resize(dCount);
    sf.resize(fCount);
    uf.resize(fCount);
    sm.resize(mCount);
    um.resize(mCount);
    ss.resize(sCount);
    ps.resize(sCount);
}

MscnProblem::MscnProblem(std::istream &is)
{
    int d, f, m, s;
    is >> d >> f >> m >> s;
    dCount = d;
    fCount = f;
    mCount = m;
    sCount = s;

    cd = Matrix<double>(is);
    cf = Matrix<double>(is);
    cm = Matrix<double>(is);

    sd = deserialize_vec<double>(is);
    sf = deserialize_vec<double>(is);
    sm = deserialize_vec<double>(is);
    ss = deserialize_vec<double>(is);
    ud = deserialize_vec<double>(is);
    uf = deserialize_vec<double>(is);
    um = deserialize_vec<double>(is);
    ps = deserialize_vec<double>(is);
}

bool MscnProblem::setDCount(int newCount)
{
    if (newCount < 0) return false;

    dCount = newCount;
    cd.resize(fCount, dCount);
    sd.resize(dCount);
    ud.resize(dCount);
    return true;
}
bool MscnProblem::setFCount(int newCount)
{
    if (newCount < 0) return false;

    fCount = newCount;
    cd.resize(fCount, dCount);
    cf.resize(mCount, fCount);
    sf.resize(fCount);
    uf.resize(fCount);
    return true;
}
bool MscnProblem::setMCount(int newCount)
{
    if (newCount < 0) return false;

    mCount = newCount;
    cf.resize(mCount, fCount);
    cm.resize(sCount, mCount);
    sm.resize(mCount);
    um.resize(mCount);
    return true;
}
bool MscnProblem::setSCount(int newCount)
{
    if (newCount < 0) return false;

    sCount = newCount;
    cm.resize(sCount, mCount);
    ss.resize(sCount);
    ps.resize(sCount);
    return true;
}

bool MscnProblem::setInMatrix(Matrix<double> &mat, double value, int i, int j)
{
    if(value < 0) return false;

    mat.set(value, i, j);
    return true;

}
bool MscnProblem::setInVector(std::vector<double> &vec, double value, int i)
{
    if(value < 0) return false;

    vec[i] = value;
    return true;

}

int MscnProblem::technicalCheck(double *solution, int arrSize)
{
    if(solution == NULL) return 1;

    int requiredSize = dCount * fCount + fCount * mCount + mCount * sCount;
    if(arrSize != requiredSize) return 2;

    for(int i = 0; i < arrSize; ++i)
    {
        if (solution[i] < 0) return 3;
    }
    return 0;
}

double MscnProblem::getKt(Matrix<double> &xd, Matrix<double> &xf, Matrix<double> &xm)
{
    double result = 0;

    for(int i = 0; i < dCount; ++i)
    {
      if(anyHigherThanZeroInARow(xd, i)) result += ud[i];
    }

    for(int i = 0; i < fCount; ++i)
    {
      if(anyHigherThanZeroInARow(xf, i)) result += uf[i];
    }

    for(int i = 0; i < mCount; ++i)
    {
      if(anyHigherThanZeroInARow(xm, i)) result += um[i];
    }

    return result;
}

double MscnProblem::getKu(Matrix<double> &xd, Matrix<double> &xf, Matrix<double> &xm)
{
    double result = 0;

    for(int i = 0; i < dCount; ++i)
      for(int j = 0; j < fCount; ++j)
          result += cd.get(i, j) * xd.get(i, j);

    for(int i = 0; i < fCount; ++i)
      for(int j = 0; j < mCount; ++j)
          result += cf.get(i, j) * xf.get(i, j);

    for(int i = 0; i < mCount; ++i)
      for(int j = 0; j < sCount; ++j)
          result += cm.get(i, j) * xm.get(i, j);

    return result;
}

double MscnProblem::getP(Matrix<double> &xm)
{
    double result = 0;
    for(int i = 0; i < mCount; ++i)
      for(int j = 0; j < sCount; ++j)
          result += ps[j] * xm.get(i, j);
    return result;
}

double MscnProblem::getProfit(Matrix<double> &xd, Matrix<double> &xf, Matrix<double> &xm)
{
    return getP(xm) - getKt(xd, xf, xm) - getKu(xd, xf, xm);
}

MscnSolution MscnProblem::parseSolution(double *solution)
{
    Matrix<double> xd(fCount, dCount);
    Matrix<double> xf(mCount, fCount);
    Matrix<double> xm(sCount, mCount);

    for(int i = 0; i < dCount; ++i)
        for(int j = 0; j < fCount; ++j)
            xd.set(solution[i*dCount+j], i, j);

    int xdSize = xd.size();

    for(int i = 0; i < fCount; ++i)
        for(int j = 0; j < mCount; ++j)
            xf.set(solution[xdSize + i*fCount+j], i, j);

    int xfSize = xf.size();

    for(int i = 0; i < mCount; ++i)
        for(int j = 0; j < sCount; ++j)
            xm.set(solution[xdSize + xfSize + i*mCount+j], i, j);

    return { xd, xf, xm };
}

std::ostream& operator<<(std::ostream &os, const MscnProblem &p)
{
    os << p.dCount << ' ' << p.fCount << ' ' << p.mCount << ' ' << p.sCount;
    os << "\n";
    os << p.cd;
    os << "\n";
    os << p.cf;
    os << "\n";
    os << p.cm;
    os << "\n";
    os << p.sd;
    os << "\n";
    os << p.sf;
    os << "\n";
    os << p.sm;
    os << "\n";
    os << p.ss;
    os << "\n";
    os << p.ud;
    os << "\n";
    os << p.uf;
    os << "\n";
    os << p.um;
    os << "\n";
    os << p.ps;
    os << "\n";

    return os;
}

bool MscnProblem::setInCd(double value, int i, int j)
{
    return setInMatrix(cd, value, i, j);
}
bool MscnProblem::setInEf(double value, int i, int j)
{
    return setInMatrix(cf, value, i, j);
}
bool MscnProblem::setInCm(double value, int i, int j)
{
    return setInMatrix(cm, value, i, j);
}

bool MscnProblem::setInSd(double value, int i)
{
    return setInVector(sd, value, i);
}
bool MscnProblem::setInSf(double value, int i)
{
    return setInVector(sf, value, i);
}
bool MscnProblem::setInSm(double value, int i)
{
    return setInVector(sm, value, i);
}
bool MscnProblem::setInSs(double value, int i)
{
    return setInVector(ss, value, i);
}
bool MscnProblem::setInUd(double value, int i)
{
    return setInVector(ud, value, i);
}
bool MscnProblem::setInUf(double value, int i)
{
    return setInVector(uf, value, i);
}
bool MscnProblem::setInUm(double value, int i)
{
    return setInVector(um, value, i);
}
bool MscnProblem::setInPs(double value, int i)
{
    return setInVector(ps, value, i);
}

double MscnProblem::getQuality(double *solution, int arrSize, int &errorCode)
{
    if((errorCode = technicalCheck(solution, arrSize)) != 0) return 0;

    MscnSolution s = parseSolution(solution);

    return getProfit(s.xd, s.xf, s.xm);
}

bool MscnProblem::constraintsSatisfied(double *solution, int arrSize, int &errorCode)
{
    if((errorCode = technicalCheck(solution, arrSize)) != 0) return false;

    MscnSolution s = parseSolution(solution);

    for(int i = 0; i < dCount; ++i)
    {
        if(sumInARow(s.xd, i) > sd[i]) return false;
    }

    for(int i = 0; i < fCount; ++i)
    {
        if(sumInARow(s.xf, i) > sf[i]) return false;
    }

    for(int i = 0; i < mCount; ++i)
    {
        if(sumInARow(s.xm, i) > sm[i]) return false;
    }

    for(int i = 0; i < sCount; ++i)
    {
        if(sumInAColumn(s.xm, i) > ss[i]) return false;
    }

    for(int i = 0; i < fCount; ++i)
    {
        if(sumInAColumn(s.xd, i) < sumInARow(s.xf, i)) return false;
    }

    for(int i = 0; i < mCount; ++i)
    {
        if(sumInAColumn(s.xf, i) < sumInARow(s.xm, i)) return false;
    }

    return true;
}

void MscnProblem::save(std::string const &path)
{
    std::ofstream file(path); //TODO: change to fopen
    file << *this;
    file.close();
}
