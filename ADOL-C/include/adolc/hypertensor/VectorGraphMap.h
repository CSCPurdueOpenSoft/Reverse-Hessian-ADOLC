#ifndef __VECTOR_GRAPH_MAP_H__
#define __VECTOR_GRAPH_MAP_H__

#include <map>

#include "VectorGraph.h"

template <typename T>
class VectorGraphMap : public VectorGraph<T> {
 public:
  VectorGraphMap();
  VectorGraphMap(char* buf);
  VectorGraphMap(std::map<T, double>& source);
  VectorGraphMap(std::map<T, double>&& source);

  ~VectorGraphMap();

  void increase(T x, double v);
  double get_and_erase(T x);
  double get(T x);
  int get_size() const;

  bool has_live(T target) const;
  int byte_size() const;
  void write_to_byte(char* buf) const;
  void debug() const;

  class iterator : public VectorGraph<T>::iterator {
   public:
    iterator(VectorGraphMap<T>::iterator* c_iter):_data(c_iter->_data),
        iter(c_iter->iter) {};
    iterator(std::map<T, double>* _data_p):_data(_data_p) {};
    virtual ~iterator();
    bool reset();
    bool get_next(T& x, double& w);
    typename VectorGraphMap<T>::iterator* copy_iter();
   private:
    const std::map<T, double>* const _data;
    typename std::map<T, double>::const_iterator iter;
  };

  typename VectorGraph<T>::iterator* get_iterator();

 private:
  std::map<T, double> data;
};

template <typename T>
typename VectorGraphMap<T>::iterator* VectorGraphMap<T>::iterator::copy_iter() {
  return new VectorGraphMap<T>::iterator(this);
}

template <typename T>
typename VectorGraph<T>::iterator* VectorGraphMap<T>::get_iterator() {
  typename VectorGraph<T>::iterator* ret = new VectorGraphMap<T>::iterator(&data);
  return ret;
}

template <typename T>
VectorGraphMap<T>::iterator::~iterator() {

}

template <typename T>
bool VectorGraphMap<T>::iterator::reset() {
  iter = _data->begin();
  if (iter == _data->end()) {
    return false;
  }
  return true;
}

template <typename T>
bool VectorGraphMap<T>::iterator::get_next(T&x, double& w){
  x = iter->first;
  w = iter->second;
  ++iter;
  if (iter == _data->end()) {
    return false;
  }
  return true;
}

template <typename T>
VectorGraphMap<T>::VectorGraphMap() {
  data.clear();
}

// L-value c-tor
template <typename T>
VectorGraphMap<T>::VectorGraphMap(std::map<T, double>& source) {
  std::cout << "VectorGraph (L-ctor)" << std::endl;
  data = source;
}

// R-value c-tor
template <typename T>
VectorGraphMap<T>::VectorGraphMap(std::map<T, double>&& source) {
//  std::cout << "VectorGraph (R-ctor)" << std::endl;
  data = std::move(source);
}

// D-tor
template <typename T>
VectorGraphMap<T>::~VectorGraphMap() {
  data.clear();
}


template <typename T>
void VectorGraphMap<T>::increase(T x, double v) {
  data[x]+=v;
}

template <typename T>
double VectorGraphMap<T>::get_and_erase(T x) {
  double ret = data[x];
  data.erase(x);
  return ret;
}

template <typename T>
double VectorGraphMap<T>::get(T x) {
  return data[x];
}

template <typename T>
int VectorGraphMap<T>::get_size() const {
  return data.size();
}

template <typename T>
void VectorGraphMap<T>::debug() const {
  typename std::map<T, double>::const_iterator t_iter;
  t_iter = data.begin();
  while(t_iter != data.end()) {
    std::cout << "A[" << t_iter->first << "]=" << t_iter->second << std::endl;
    ++t_iter;
  }
}

template <typename T>
int VectorGraphMap<T>::byte_size() const {
  return data.size() * (sizeof(T) + sizeof(double)) + sizeof(int);
}

template <typename T>
void VectorGraphMap<T>::write_to_byte(char* buf) const {
  char* p = buf;
  *((int*)p) = data.size();
  p += sizeof(int);
 typename std::map<T, double>::const_iterator t_iter;
  t_iter = data.begin();
  while(t_iter != data.end()) {
    *((T*)p) = t_iter->first;
    p += sizeof(T);
    *((double*)p) = t_iter->second;
    p += sizeof(double);
    ++t_iter;
  }
}

template <typename T>
VectorGraphMap<T>::VectorGraphMap(char* buf) {
  data.clear();
  char* p = buf;
  T loc;
  double w;
  int size = *((int*)p);
  p += sizeof(int);
  for(int i = 0; i < size; i++) {
    loc = *((T*)p);
    p += sizeof(T);
    w = *((double*)p);
    p += sizeof(double);
    data[loc] = w;
  }
}

template <typename T>
bool VectorGraphMap<T>::has_live(T target) const {
  if (data.find(target) != data.end()) {
    return true;
  }
  return false;
}
#endif // __VECTOR_GRAPH_MAP_H__
