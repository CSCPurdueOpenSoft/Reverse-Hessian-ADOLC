#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include <adolc/hessian/edge_main.h>
#include <adolc/hessian/edge_graph.h>
#include <adolc/hessian/edge_check.h>
#include <adolc/hessian/edge_tape.h>
#include <adolc/hessian/edge_b_tree.h>
#include "oplate.h"
#include <adolc/adolc.h>
#include "taping_p.h"

#define SYSMMETRIC_MATRIX 1
#define NO_PRE_ACC 1
#include "edge_uni5_push.cpp"
#undef SYSMMETRIC_MATRIX
#undef NO_PRE_ACC
