#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <adolc/hessian/edge_main.h>
#include <adolc/hessian/edge_graph.h>
#include <adolc/hessian/edge_check.h>
#include <adolc/hessian/edge_tape.h>
#include <adolc/hessian/edge_local_graph.h>
#include <cmath>
#include "oplate.h"
#include <adolc/adolc.h>
#include "taping_p.h"

#ifdef PREACC

#define PRE_ACC
#include "edge_uni5_push.cpp"
#undef PRE_ACC
#endif
