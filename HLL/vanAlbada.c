#include "definitions.h"

double vanAlbada(double rL, double rR, double h){
	double eps = pow((0.3*h),3.0);
	double va = 0.5*(sign(rL)*sign(rR)+1.0)*( (pow(rR,2.0)+eps)*rL+(pow(rL,2.0)+eps)*rR )/(pow(rL,2.0)+pow(rR,2.0)+2.0*eps);
	return(va);
	
}


