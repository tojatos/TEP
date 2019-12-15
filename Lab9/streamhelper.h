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

#endif // STREAMHELPER_H
