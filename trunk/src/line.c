#include "definitions.h"


void line(double coords,double *data,double t)
{

  double A, B, C;
  //Eqn of line = Ax + By + z + D = 0 or z = -(Ax + By + D)
  //Eqn of line = Ax + By + C = 0
  //Slope of the plane = -A/C, -B/C with C=1.0 in this special case.
  A=2.0, B=1, C=4;
     
  double rho = (A*coords+C);
 
  data[0] = rho;
  data[1] = rho*UInit;
  data[2] = PInit/(gamma-1.0)+0.5*rho*(UInit*UInit);
}

