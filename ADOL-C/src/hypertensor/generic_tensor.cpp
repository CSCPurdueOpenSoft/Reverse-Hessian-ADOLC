#include <vector>
#include <map>
#include <iostream>

#include <stdio.h>

#include <adolc/adolc.h>
#include <adolc/hypertensor/hyper_tape.h>
#include <adolc/hypertensor/opencomb.h>
#include <adolc/hypertensor/generic_reverse.h>

int generic_tensor(short tag,
                  int dep,
                  int indep,
                  const double* basepoint,
                  int d) {

  std::vector<locint> hyper_index;
  std::vector<double> hyper_value;
  std::map<locint, locint> ind_map;
  GenericDerivative<locint> generic_derivative(d);
  std::cout << "In generic_tensor" << std::endl;
  hyper_tape(tag, dep, indep, basepoint, ind_map, hyper_index, hyper_value);
  generic_reverse(tag, d, hyper_index, hyper_value, generic_derivative);
//  generic_derivative.debug();
}
