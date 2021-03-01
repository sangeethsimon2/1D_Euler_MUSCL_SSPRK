#include "definitions.h"

double minmod(double rL, double rR){
/*
        if(rL*rR<=0){
                return(0.0);
        }
        else{
                return(fmin(fabs(rL),fabs(rR)));

        }
*/
	int s = (sign(rL)+sign(rR))/2;

	if(fabs(s)==1){
		return(s*fmin(fabs(rL),fabs(rR)));
	}

	else{
		return(0.0);
	}

}


