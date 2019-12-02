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
    return true;
}

bool MscnProblem::setFCount(int newCount)
{
    if (newCount < 0) return false;

    fCount = newCount;
    cd.resize(fCount, dCount);
    ef.resize(mCount, fCount);
    return true;
}
bool MscnProblem::setMCount(int newCount)
{
    if (newCount < 0) return false;

    mCount = newCount;
    ef.resize(mCount, fCount);
    cm.resize(sCount, mCount);
    return true;
}
bool MscnProblem::setSCount(int newCount)
{
    if (newCount < 0) return false;

    sCount = newCount;
    cm.resize(sCount, mCount);
    return true;
}

bool MscnProblem::setInMatrix(Matrix<double> &mat, double value, int i, int j)
{
    if(value < 0) return false;

    mat.set(value, i, j);
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
