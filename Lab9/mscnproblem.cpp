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
    stream_get<std::string>(is);
    dCount = stream_get<int>(is);
    stream_get<std::string>(is);
    fCount = stream_get<int>(is);
    stream_get<std::string>(is);
    mCount = stream_get<int>(is);
    stream_get<std::string>(is);
    sCount = stream_get<int>(is);

    stream_get<std::string>(is);
    sd = Table<double>(is, dCount);
    stream_get<std::string>(is);
    sf = Table<double>(is, fCount);
    stream_get<std::string>(is);
    sm = Table<double>(is, mCount);
    stream_get<std::string>(is);
    ss = Table<double>(is, sCount);

    stream_get<std::string>(is);
    cd = Matrix<double>(is, fCount, dCount);
    stream_get<std::string>(is);
    cf = Matrix<double>(is, mCount, fCount);
    stream_get<std::string>(is);
    cm = Matrix<double>(is, sCount, mCount);

    stream_get<std::string>(is);
    ud = Table<double>(is, dCount);
    stream_get<std::string>(is);
    uf = Table<double>(is, fCount);
    stream_get<std::string>(is);
    um = Table<double>(is, mCount);
    stream_get<std::string>(is);
    ps = Table<double>(is, sCount);
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

int MscnProblem::technicalCheck(double const * const solution, int arrSize)
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

MscnSolution MscnProblem::parseSolution(double const * const solution)
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
    os << 'D' << ' ' << p.dCount << '\n';
    os << 'F' << ' ' << p.fCount << '\n';
    os << 'M' << ' ' << p.mCount << '\n';
    os << 'S' << ' ' << p.sCount << '\n';
    os << "sd";
    os << "\n";
    os << p.sd;
    os << "sf";
    os << "\n";
    os << p.sf;
    os << "sm";
    os << "\n";
    os << p.sm;
    os << "ss";
    os << "\n";
    os << p.ss;
    os << "cd";
    os << "\n";
    os << p.cd;
    os << "cf";
    os << "\n";
    os << p.cf;
    os << "cm";
    os << "\n";
    os << p.cm;
    os << "ud";
    os << "\n";
    os << p.ud;
    os << "uf";
    os << "\n";
    os << p.uf;
    os << "um";
    os << "\n";
    os << p.um;
    os << "p";
    os << "\n";
    os << p.ps;

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
    return setInTable(sd, value, i);
}
bool MscnProblem::setInSf(double value, int i)
{
    return setInTable(sf, value, i);
}
bool MscnProblem::setInSm(double value, int i)
{
    return setInTable(sm, value, i);
}
bool MscnProblem::setInSs(double value, int i)
{
    return setInTable(ss, value, i);
}
bool MscnProblem::setInUd(double value, int i)
{
    return setInTable(ud, value, i);
}
bool MscnProblem::setInUf(double value, int i)
{
    return setInTable(uf, value, i);
}
bool MscnProblem::setInUm(double value, int i)
{
    return setInTable(um, value, i);
}
bool MscnProblem::setInPs(double value, int i)
{
    return setInTable(ps, value, i);
}

std::vector<std::array<double, 2>> MscnProblem::getMinMaxValues()
{
    std::vector<std::array<double, 2>> res;

    for(int i = 0; i < dCount; ++i)
        for(int j = 0; j < fCount; ++j)
            res.push_back({0, sd[i]});

    for(int i = 0; i < fCount; ++i)
        for(int j = 0; j < mCount; ++j)
            res.push_back({0, sf[i]});

    for(int i = 0; i < mCount; ++i)
        for(int j = 0; j < sCount; ++j)
            res.push_back({0, std::max(sm[i], ss[i])});

    return res;
}

double MscnProblem::getQuality(double const * const solution, int arrSize, int &errorCode)
{
    if((errorCode = technicalCheck(solution, arrSize)) != 0) return 0;

    MscnSolution s = parseSolution(solution);

    return getProfit(s.xd, s.xf, s.xm);
}

bool MscnProblem::constraintsSatisfied(double const * const solution, int arrSize, int &errorCode)
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
