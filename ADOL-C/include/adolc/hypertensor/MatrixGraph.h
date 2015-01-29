#ifndef __MATRIX_GRAPH_H__
#define __MATRIX_GRAPH_H__

template <typename T> class VectorGraph;

template <typename T>
class MatrixGraph {
 public:
  virtual void increase(T x, T y, double v) = 0;
  virtual VectorGraph<T>* get_and_erase(T x) = 0;
  virtual VectorGraph<T>* get(T x) = 0;
  virtual bool reset() = 0;
  virtual bool get_next(T& x, T& y, double& w) = 0;
};

#endif // __MATRIX_GRAPH_H__
