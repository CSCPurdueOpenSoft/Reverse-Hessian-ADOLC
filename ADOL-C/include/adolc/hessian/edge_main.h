#ifndef __EDGE_MAIN_H__
#define __EDGE_MAIN_H__
#include <iostream>
#include <vector>
#include <map>
#include <adolc/common.h>
using namespace std;

/* timing utility */
extern struct timeval tv1,tv2;

#define NOT_IMPLEMENTED_YET fprintf(stderr,"not implemented yet\n");fflush(stderr);

#define NO_ASSIGN_BYPASS

#define NULLLOC -1

class derivative_info{
  public:
    unsigned char opcode;
    int r,x,y;
    double dx,dy;
    double px,py,pxy;

    derivative_info(){
      opcode=-1;
      r=NULLLOC;x=NULLLOC;y=NULLLOC;
      dx=0.0;dy=0.0;
      px=0.0;py=0.0;pxy=0.0;
    };
    ~derivative_info(){};
};

class global_trace{
  public:
    int r;
    map<int, double> *first;
    map<int, map<int, double> > *second;
    global_trace(){
      r=NULLLOC;
      first=NULL;
      second=NULL;
    };
    ~global_trace(){
    }
};


/*  edge_main.cpp */
int edge_hess(
    short          tag,        /* tape identification                     */
    int            dep,        /* consistency chk on # of dependents      */
    int            indep,      /* number of independent variables         */
    const double  *basepoint,  /* independant variable values             */
    int           *nnz,        /* number of nonzeros                      */
    unsigned int **rind,       /* row index                               */
    unsigned int **cind,       /* column index                            */
    double       **values,     /* non-zero values                         */
    int           *options     /* control options                         */
);
void edge_retrive(map<int, map<int, double> > *graph, unsigned int *indmap, int *nnz, unsigned int **rind, unsigned int **cind, double **values);

void increase_edge_a(int i,int j,double w,map<int, map<int,double> > *graph);
void increase_edge_s(int i,int j,double w,map<int, map<int,double> > *graph);


#endif
