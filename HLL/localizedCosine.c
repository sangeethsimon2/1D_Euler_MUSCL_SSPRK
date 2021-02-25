#include "definitions.h"


void localizedCosine(double coords,double *data,double t)
{
  double x = coords-UInit*t;
  //double y = coords[1]-VInit*t;
  x -= floor(x)+0.5;
  //y -= floor(y)+0.5;
  double r = sqrt(x*x);
  double rho = 1.0+((r>0.25)?0.0:pow(cos(2*M_PI*r),4));
  
  
  data[0] = rho;
  data[1] = rho*UInit;
  data[2] = PInit/(gamma-1.0)+0.5*rho*(UInit*UInit);
}

