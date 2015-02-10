/*----------------------------------------------------------------------------
 ADOL-C -- Automatic Differentiation by Overloading in C++
 File:     oplate.h
 Revision: $Id$
 Contents: Numeric values for the various opcodes used by ADOL-C.
 
 Copyright (c) Andrea Walther, Andreas Griewank, Andreas Kowarz, 
               Hristo Mitev, Sebastian Schlenkrich, Jean Utke, Olaf Vogel,
               Kshitij Kulshreshtha
  
 This file is part of ADOL-C. This software is provided as open source.
 Any use, reproduction, or distribution of the software constitutes 
 recipient's acceptance of the terms of the accompanying license file.
           
----------------------------------------------------------------------------*/

#if !defined(ADOLC_OPLATE_P_H)
#define ADOLC_OPLATE_P_H 1

/****************************************************************************/
/* opcodes */

enum OPCODES {
  death_not,  // 0
  assign_ind,
  assign_dep,
  assign_a,
  assign_d,
  eq_plus_d,
  eq_plus_a,
  eq_min_d,
  eq_min_a,
  eq_mult_d,
  eq_mult_a,  // 10
  plus_a_a,
  plus_d_a,
  min_a_a,
  min_d_a,
  mult_a_a,
  mult_d_a,
  div_a_a,
  div_d_a,
  exp_op,
  cos_op,  // 20
  sin_op,
  atan_op,
  log_op,
  pow_op,
  asin_op,
  acos_op,
  sqrt_op,
  asinh_op,
  acosh_op,
  atanh_op,  // 30
  gen_quad,
  end_of_tape,
  start_of_tape,
  end_of_op,
  end_of_int,
  end_of_val,
  cond_assign,
  cond_assign_s,
  take_stock_op,
  assign_d_one,   // 40
  assign_d_zero,
  incr_a,
  decr_a,
  neg_sign_a,
  pos_sign_a,
  min_op,
  abs_val,
  eq_zero,
  neq_zero,
  le_zero, // 50
  gt_zero,
  ge_zero,
  lt_zero,
  eq_plus_prod,
  eq_min_prod,
  erf_op,
  ceil_op,
  floor_op,
  ext_diff,
  ext_diff_iArr, // 60
  ignore_me,
  subscript = 80,
  subscript_ref,
  ref_assign_d_zero,
  ref_assign_d_one,
  ref_assign_d,
  ref_assign_a,
  ref_assign_ind,
  ref_incr_a,
  ref_decr_a,
  ref_eq_plus_d,
  ref_eq_min_d,
  ref_eq_plus_a,
  ref_eq_min_a,
  ref_eq_mult_d,
  ref_eq_mult_a,
  ref_copyout,
  ref_cond_assign,
  ref_cond_assign_s,
  assign_p = 98,
  eq_plus_p,
  eq_min_p,
  eq_mult_p,
  ref_assign_p,
  ref_eq_plus_p,
  ref_eq_min_p,
  ref_eq_mult_p,
  plus_a_p,
  min_a_p,
  mult_a_p,
  div_p_a,
  pow_op_p,
  neg_sign_p,
  recipr_p,
  eq_a_p = 119,
  neq_a_p,
  le_a_p,
  gt_a_p,
  ge_a_p,
  lt_a_p,
  eq_a_a = 125,
  neq_a_a,
  le_a_a,
  gt_a_a,
  ge_a_a,
  lt_a_a,
  ampi_send = 131,
  ampi_recv,
  ampi_isend,
  ampi_irecv,
  ampi_wait,
  ampi_barrier,
  ampi_gather,
  ampi_scatter,
  ampi_allgather,
  ampi_gatherv,
  ampi_scatterv,
  ampi_allgatherv,
  ampi_bcast,
  ampi_reduce,
  ampi_allreduce
};

/****************************************************************************/
#endif
