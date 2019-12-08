#ifndef STREAMHELPER_H
#define STREAMHELPER_H

#include<istream>
#include<vector>

template<class T>
T stream_get(std::istream& is){
  T result;
  is >> result;
  return result;
}

template<class T>
std::ostream& operator<< (std::ostream &os, const std::vector<T> &vec)
{
    size_t size = vec.size();
    os << size << '\n';
    for (size_t i = 0; i < size; ++i)
    {
        os << vec[i] << ' ';
    }
    os << '\n';
    return os;
}

template<class T>
std::vector<T> deserialize_vec(std::istream &is)
{
    size_t size = stream_get<size_t>(is);
    std::vector<T> vec(size);
    for (size_t i = 0; i < size; ++i)
    {
        vec[i] = stream_get<T>(is);
    }
    return std::move(vec);
}
#endif // STREAMHELPER_H
