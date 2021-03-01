#include "definitions.h"
extern int N;
extern double dx,L,*cell_xc;

void grid()
{
	int i;
	dx = L/N;
	//printf("dx=%lf\n",dx);

	cell_xc=(double *)malloc((N+4)*sizeof(double));
	
	for(i=1;i<=N+2;i++)
	{
		cell_xc[i] = (i-1)*dx-dx/2.0; //x coordinate of cell centers
		

	}
}
	
