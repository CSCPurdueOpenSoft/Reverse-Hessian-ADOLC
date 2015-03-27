#ifndef HYPER_PUSHING_H_
#define HYPER_PUSHING_H_
#include <adolc/adolc.h>
#include "VectorGraph.h"
#include "MatrixGraph.h"
#include "HyperGraph.h"
#include "hyper_common.h"
#include "hyper_derivative.h"

void hyper_third(DerivativeInfo<locint>& info,
                VectorGraph<locint>* adjoints,
                MatrixGraph<locint>* hessian,
                HyperGraph<locint>* tensor,
                double w,
                VectorGraph<locint>* r,
                MatrixGraph<locint>* e);

void hyper_hessian(DerivativeInfo<locint>& info,
                  VectorGraph<locint>* adjoints,
                  MatrixGraph<locint>* hessian,
                  double w,
                  VectorGraph<locint>* r);

void hyper_adjoints(DerivativeInfo<locint>& info,
                   VectorGraph<locint>* adjoints,
                   double w);

void hyper_process_sac(DerivativeInfo<locint>& info,
                      HyperDerivative<locint>& global_gd);
#endif // HYPER_PUSHING_H_
