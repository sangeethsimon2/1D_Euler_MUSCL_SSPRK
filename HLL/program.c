#include "definitions.h"

int N,problem;
double L,tmax,cfl;
double *cell_xc,dx,*cell_u1,*cell_u2,*cell_u3,*netflux[3];
double deltat;

int main()
{
	int i,j;
	int iter;
	double time;
	
	read_data();
	grid();
	initialize();
	
	deltat=0;
	time =0;
	iter=0;

	while(time<tmax)
	{
		flux();
		update();
		time=time+deltat;
		printf("%d\t%lf\t%lf\n",iter,time,deltat);
		iter++;



	}
	
	output();	
	delete_memory();
	return 0;
	
}

	
	

