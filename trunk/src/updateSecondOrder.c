#include "definitions.h"
extern int N;
extern double *cell_u1,*cell_u2,*cell_u3;
extern double *cell_u1_old,*cell_u2_old,*cell_u3_old;
extern double *netflux[3],dx;
extern double deltat;
void updateSecondOrder()
{
	int i;
	
	for(i=2;i<=N+1;i++)
	{
		cell_u1[i] = 0.5*cell_u1[i] + 0.5*cell_u1_old[i] - 0.5* (deltat)*(netflux[0][i]);
		cell_u2[i] = 0.5*cell_u2[i] + 0.5*cell_u2_old[i] - 0.5* (deltat)*(netflux[1][i]);
 		cell_u3[i] = 0.5*cell_u3[i] + 0.5*cell_u3_old[i] - 0.5* (deltat)*(netflux[2][i]);



	}

}

