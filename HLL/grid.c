#include "definitions.h"
extern int N;
extern double dx,L,*cell_xc;

void grid()
{
	int i;
	dx = L/N;
	cell_xc=(double *)malloc((N+4)*sizeof(double));
	
	for(i=0;i<=N+3;i++)
	{
		cell_xc[i] = i*dx-dx/2; //x coordinate of cell centers
		

	}
}
	