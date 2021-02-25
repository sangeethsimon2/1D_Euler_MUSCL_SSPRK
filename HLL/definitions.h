#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void read_data();
void grid();
void delete_memory();
void initialize();
void update();
void applyBoundaryCondition();
void copySolution();
void updateSecondOrder();
void computeTimeStep();
void output();
void flux();
void localizedCosine(double , double *, double);
void line(double , double *, double);
void computeError(double);
void computeFlux(int, int, double*);


/*
template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
};*/




#define gamma 1.4

#define UInit	1.0
#define PInit	1.0
