#ifndef __HYPER_GRAPH_MAP_H__
#define __HYPER_GRAPH_MAP_H__

#include <map>

#include "MatrixGraph.h"
#include "MatrixGraphMap.h"
#include "HyperGraph.h"


template <typename T>
class HyperGraphMap : public HyperGraph<T> {
 public:
  HyperGraphMap();
  HyperGraphMap(char* buf);
  ~HyperGraphMap();
  void increase(T x, T y, T z, double v);
  MatrixGraph<T>* get_and_erase(T x);
  MatrixGraph<T>* get(T x);
  int byte_size();
  void write_to_byte(char* buf);
  bool reset();
  bool get_next(T& x, T& y, T& z, double& w);
  int get_size();
  void debug();
// private:
  std::map<T, std::map<T, std::map<T, double> > > data;
  typename std::map<T, std::map<T, std::map<T, double> > >::iterator iter;
  typename std::map<T, std::map<T, double> >::iterator iter2;
  typename std::map<T, double>::iterator iter3;
};

template <typename T>
HyperGraphMap<T>::HyperGraphMap() {
  data.clear();
}

template <typename T>
HyperGraphMap<T>::~HyperGraphMap() {
  data.clear();
}

template <typename T>
HyperGraphMap<T>::HyperGraphMap(char* buf) {
  char* p = buf;
  int size = *((int*)p);
  p += sizeof(int);
  T x,y,z;
  double w;
  for(int i = 0; i < size; i++) {
    x = *((T*)p);
    p += sizeof(T);
    y = *((T*)p);
    p += sizeof(T);
    z = *((T*)p);
    p += sizeof(T);
    w = *((double*)p);
    p += sizeof(w);
    data[x][y][z] = w;
  }  
}

template <typename T>
int HyperGraphMap<T>::byte_size() {
  return get_size() * (sizeof(T)*3+sizeof(double)) + sizeof(int);
}

template <typename T>
void HyperGraphMap<T>::write_to_byte(char* buf) {
  char* p = buf;
  *((int*)p) = get_size();
  p += sizeof(int);
  typename std::map<T, std::map<T, std::map<T, double> > >::const_iterator t_iter;
  typename std::map<T, std::map<T, double> >::const_iterator m_iter;
  typename std::map<T, double>::const_iterator v_iter;
  t_iter = data.begin();
  while(t_iter != data.end()) {
    m_iter = t_iter->second.begin();
    while(m_iter != t_iter->second.end()) {
      v_iter = m_iter->second.begin();
      while(v_iter != m_iter->second.end()) {
        *((T*)p) = t_iter->first;
        p += sizeof(T);
        *((T*)p) = m_iter->first;
        p += sizeof(T);
        *((T*)p) = v_iter->first;
        p += sizeof(T);
        *((double*)p) = v_iter->second;
        p += sizeof(double);
        ++v_iter;
      }
      ++m_iter;
    }
    ++t_iter;
  }  
}

template <typename T>
void HyperGraphMap<T>::increase(T x, T y, T z, double v) {
  if (v == 0.0) {return;}
  MAX_SWAP(x, y);
  MAX_SWAP(y, z);
  MAX_SWAP(x, y);
  data[x][y][z]+=v;
}

template <typename T>
MatrixGraph<T>* HyperGraphMap<T>::get_and_erase(T x) {
  MatrixGraph<T>* ret = new MatrixGraphMap<T>(std::move(data[x]));
  data.erase(x);
  return ret;
}

template <typename T>
MatrixGraph<T>* HyperGraphMap<T>::get(T x) {
  MatrixGraph<T>* ret = new MatrixGraphMap<T>(data[x]);
  return ret;
}

template <typename T>
bool HyperGraphMap<T>::reset() {
  iter = data.begin();
  while(iter != data.end()) {
    iter2 = iter->second.begin();
    while(iter2 != iter->second.end()) {
      iter3 = iter2->second.begin();
      if (iter3 != iter2->second.end()) {
        return true;
      }
      ++iter2;
    }
    ++iter;
  }
  return false;
}
template <typename T>
bool HyperGraphMap<T>::get_next(T& x, T& y, T& z, double& w) {
  x = iter->first;
  y = iter2->first;
  z = iter3->first;
  w = iter3->second;
  ++iter3;
  while(iter != data.end()) {
    while(iter2 != iter->second.end()) {
      if (iter3 != iter2->second.end()) {
        return true;
      }
      ++iter2;
      if (iter2 != iter->second.end()) {
        iter3 = iter2->second.begin();
      }
    }
    ++iter;
    if (iter != data.end()) {
      iter2 = iter->second.begin();
      while (iter2 != iter->second.end()) {
        iter3 = iter2->second.begin();
        if (iter3 != iter2->second.end()) {
          return true;
        }
        ++iter2;
      }
    }
  }
  return false;
}

template <typename T>
int HyperGraphMap<T>::get_size() {
  int size_count = 0;
  typename std::map<T, std::map<T, std::map<T, double> > >::iterator t_iter;
  typename std::map<T, std::map<T, double> >::iterator t_iter2;
  t_iter = data.begin();
  while(t_iter != data.end() ){
    t_iter2 = t_iter->second.begin();
    while(t_iter2 != t_iter->second.end()) {
      size_count += t_iter2->second.size();
      ++t_iter2;
    }
    ++t_iter;
  }
  return size_count;
}

template <typename T>
void HyperGraphMap<T>::debug() {
  typename std::map<T, std::map<T, std::map<T, double> > >::iterator t_iter;
  typename std::map<T, std::map<T, double> >::iterator t_iter2;
  typename std::map<T, double>::iterator t_iter3;
  t_iter = data.begin();
  while(t_iter != data.end() ){
    t_iter2 = t_iter->second.begin();
    while(t_iter2 != t_iter->second.end()) {
      t_iter3 = t_iter2->second.begin();
      while(t_iter3 != t_iter2->second.end()) {
        std::cout << "T[" << t_iter->first << ","
                  << t_iter2->first << ","
                  << t_iter3->first << "] = " << t_iter3->second << std::endl;
        ++t_iter3;
      }
      ++t_iter2;
    }
    ++t_iter;
  }
}

#endif // __HYPER_GRAPH_MAP_H__
