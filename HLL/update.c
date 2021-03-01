#include "definitions.h"
extern int N;
extern double *cell_u1,*cell_u2,*cell_u3,*netflux[3],dx;
extern double deltat;
void update()
{
	int i;
	
	for(i=2;i<=N+1;i++)
	{
	//	printf("before\n");
	//	printf("%d\t%lf\n",i,cell_u1[i]);
		cell_u1[i] = cell_u1[i] - (deltat)*(netflux[0][i]);

		cell_u2[i] = cell_u2[i] - (deltat)*(netflux[1][i]);

		cell_u3[i] = cell_u3[i] - (deltat)*(netflux[2][i]);
	//	printf("after\n");
	//	printf("%d\t%lf\n",i,cell_u1[i]);

	}

}

