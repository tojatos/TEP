#ifndef STREAMHELPER_H
#define STREAMHELPER_H
#include<istream>

template<class T>
T stream_get(std::istream& is){
  T result;
  is >> result;
  return result;
}

#endif // STREAMHELPER_H
