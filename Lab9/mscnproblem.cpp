#include "mscnproblem.h"

MscnProblem::MscnProblem()
{
    dCount = DEF_MSCN_D;
    fCount = DEF_MSCN_F;
    mCount = DEF_MSCN_M;
    sCount = DEF_MSCN_S;

    cd = Matrix<double>(fCount, dCount);
    ef = Matrix<double>(mCount, fCount);
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
    ef = Matrix<double>(is);
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
    ef.resize(mCount, fCount);
    sf.resize(fCount);
    uf.resize(fCount);
    return true;
}
bool MscnProblem::setMCount(int newCount)
{
    if (newCount < 0) return false;

    mCount = newCount;
    ef.resize(mCount, fCount);
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

std::ostream& operator<<(std::ostream &os, const MscnProblem &p)
{
    os << p.dCount << ' ' << p.fCount << ' ' << p.mCount << ' ' << p.sCount;
    os << "\n";
    os << p.cd;
    os << "\n";
    os << p.ef;
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
    return setInMatrix(ef, value, i, j);
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

void MscnProblem::save(std::string const &path)
{
    std::ofstream file(path); //TODO: change to fopen
    file << *this;
    file.close();
}
