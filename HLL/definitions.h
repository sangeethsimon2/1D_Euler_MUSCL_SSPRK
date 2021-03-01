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
void output(int);
void flux();
void localizedCosine(double , double *, double);
void line(double , double *, double);
void computeError(double);
void computeFlux(int, int, double*);
void computeFluxAtBoundary(int, int, double*, char);
void outputOldValues(int);


/*
template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
};*/




#define gamma 1.4

#define UInit	1.0
#define PInit	1.0
