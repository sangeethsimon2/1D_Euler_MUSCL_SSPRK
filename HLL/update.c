#include "definitions.h"
extern int N;
extern double *cell_u1,*cell_u2,*cell_u3,*netflux[3],dx;
extern double deltat;
void update()
{
	int i;
	
	for(i=1;i<=N;i++)
	{
		cell_u1[i] = cell_u1[i] - (deltat/dx)*(netflux[0][i]);

		cell_u2[i] = cell_u2[i] - (deltat/dx)*(netflux[1][i]);

		cell_u3[i] = cell_u3[i] - (deltat/dx)*(netflux[2][i]);

	}
		cell_u1[0]=cell_u1[1];
		cell_u2[0]=cell_u2[1];
		cell_u3[0]=cell_u3[1];
		cell_u1[N+1]=cell_u1[N];
		cell_u2[N+1]=cell_u2[N];
		cell_u3[N+1]=cell_u3[N];
	
}

