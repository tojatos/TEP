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

std::string MscnProblem::serialize()
{
    std::stringstream os;
    os << dCount << ' ' << fCount << ' ' << mCount << ' ' << sCount;
    os << "\n\n";
    os << cd.serialize();
    os << "\n\n";
    os << ef.serialize();
    os << "\n\n";
    os << cm.serialize();
    os << "\n\n";
    os << serialize(sd);
    os << "\n\n";
    os << serialize(sf);
    os << "\n\n";
    os << serialize(sm);
    os << "\n\n";
    os << serialize(ss);
    os << "\n\n";
    os << serialize(ud);
    os << "\n\n";
    os << serialize(uf);
    os << "\n\n";
    os << serialize(um);
    os << "\n\n";
    os << serialize(ps);
    os << "\n\n";

    return os.str();
}

MscnProblem MscnProblem::deserialize(std::string const &str)
{
    //TODO: deserialize
    throw;

}

void MscnProblem::save(std::string const &path)
{
    std::ofstream file(path);
    file << serialize();
    file.close();
}

MscnProblem MscnProblem::load(std::string const &path)
{
    std::ifstream file(path);
    std::ostringstream buffer;
    buffer << file.rdbuf();
    std::string res = buffer.str();
    return deserialize(res);
}

std::string MscnProblem::serialize(const std::vector<double> &vec)
{
    std::ostringstream buffer;
    size_t size = vec.size();
    for (size_t i = 0; i < size; ++i)
    {
        buffer << vec[i] << ' ';
    }
    return buffer.str();
}
