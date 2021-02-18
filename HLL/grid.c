#include "definitions.h"
extern int N;
extern double dx,L,*cell_xc;

void grid()
{
	int i;
	dx = L/N;
	cell_xc=(double *)malloc((N+2)*sizeof(double));
	
	for(i=0;i<=N+1;i++)
	{
		cell_xc[i] = i*dx-dx/2; //x coordinate of cell centers
		

	}
}
	
