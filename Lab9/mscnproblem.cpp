#include "mscnproblem.h"

MscnProblem::MscnProblem()
{
    dCount = DEF_MSCN_D;
    fCount = DEF_MSCN_F;
    mCount = DEF_MSCN_M;
    sCount = DEF_MSCN_S;

    cd.resize(fCount, dCount);
    cf.resize(mCount, fCount);
    cm.resize(sCount, mCount);
    sd.resize(dCount);
    ud.resize(dCount);
    sf.resize(fCount);
    uf.resize(fCount);
    sm.resize(mCount);
    um.resize(mCount);
    ss.resize(sCount);
    ps.resize(sCount);

    specialResize(xdminmax, fCount, dCount);
    specialResize(xfminmax, mCount, fCount);
    specialResize(xmminmax, sCount, mCount);
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

    stream_get<std::string>(is);
    specialRead(xdminmax, is, fCount, dCount);
    stream_get<std::string>(is);
    specialRead(xfminmax, is, mCount, fCount);
    stream_get<std::string>(is);
    specialRead(xmminmax, is, sCount, mCount);
}

bool MscnProblem::setDCount(int newCount)
{
    if (newCount < 0) return false;

    dCount = newCount;
    cd.resize(fCount, dCount);
    sd.resize(dCount);
    ud.resize(dCount);
    specialResize(xdminmax, fCount, dCount);
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
    specialResize(xdminmax, fCount, dCount);
    specialResize(xfminmax, mCount, fCount);
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
    specialResize(xfminmax, mCount, fCount);
    specialResize(xmminmax, sCount, mCount);
    return true;
}
bool MscnProblem::setSCount(int newCount)
{
    if (newCount < 0) return false;

    sCount = newCount;
    cm.resize(sCount, mCount);
    ss.resize(sCount);
    ps.resize(sCount);
    specialResize(xmminmax, sCount, mCount);
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
    os << "\n";
    os << "sf";
    os << "\n";
    os << p.sf;
    os << "\n";
    os << "sm";
    os << "\n";
    os << p.sm;
    os << "\n";
    os << "ss";
    os << "\n";
    os << p.ss;
    os << "\n";
    os << "cd";
    os << "\n";
    os << p.cd;
    os << "\n";
    os << "cf";
    os << "\n";
    os << p.cf;
    os << "\n";
    os << "cm";
    os << "\n";
    os << p.cm;
    os << "\n";
    os << "ud";
    os << "\n";
    os << p.ud;
    os << "\n";
    os << "uf";
    os << "\n";
    os << p.uf;
    os << "\n";
    os << "um";
    os << "\n";
    os << p.um;
    os << "\n";
    os << "p";
    os << "\n";
    os << p.ps;
    os << "\n";
    os << "xdminmax";
    os << "\n";
    os << p.xdminmax;
    os << "\n";
    os << "xfminmax";
    os << "\n";
    os << p.xfminmax;
    os << "\n";
    os << "xmminmax";
    os << "\n";
    os << p.xmminmax;
    os << "\n";

    return os;
}

bool MscnProblem::setInCd(double value, int i, int j)
{
    return setInMatrix(cd, value, i, j);
}
bool MscnProblem::setInCf(double value, int i, int j)
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

bool MscnProblem::setInXdminmax(double value, int i, int j, int k)
{
    return setInMatrix(xdminmax, value, i, j, k);
}

bool MscnProblem::setInXfminmax(double value, int i, int j, int k)
{
    return setInMatrix(xfminmax, value, i, j, k);
}

bool MscnProblem::setInXmminmax(double value, int i, int j, int k)
{
    return setInMatrix(xmminmax, value, i, j, k);
}

Table<Table<double>> MscnProblem::getMinMaxValues()
{
    int tablen = dCount*fCount+fCount*mCount+mCount*sCount;
    Table<Table<double>> tab(tablen);
    for(int i = 0; i < tablen; ++i)
        tab[i] = Table<double>(2);

    for(int i = 0; i < dCount; ++i)
        for(int j = 0; j < fCount; ++j)
          for(int k = 0; k < 2; ++k)
            tab[i*fCount + j][k] = xdminmax.get(i, j)[k];

    for(int i = 0; i < fCount; ++i)
        for(int j = 0; j < mCount; ++j)
          for(int k = 0; k < 2; ++k)
            tab[dCount*fCount + i*dCount + j][k] = xfminmax.get(i, j)[k];

    for(int i = 0; i < mCount; ++i)
        for(int j = 0; j < sCount; ++j)
          for(int k = 0; k < 2; ++k)
            tab[dCount*fCount + fCount * mCount + i*sCount + j][k] = xmminmax.get(i, j)[k];

    return tab;
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
    std::ofstream file(path);
    file << *this;
    file.close();
}

void MscnProblem::specialRead(Matrix<Table<double>> &mat, std::istream &is, int width, int height)
{
    specialResize(mat, width, height);

    for(int i = 0; i < height; ++i)
        for(int j = 0; j < width; ++j)
        {
            mat.get(i, j)[0] = stream_get<double>(is);
            mat.get(i, j)[1] = stream_get<double>(is);
        }
}

void MscnProblem::specialResize(Matrix<Table<double>> &mat, int width, int height)
{
    mat.resize(width, height);
    for(int i = 0; i < height; ++i)
        for(int j = 0; j < width; ++j)
            mat.set(Table<double>(2), i, j);
}
