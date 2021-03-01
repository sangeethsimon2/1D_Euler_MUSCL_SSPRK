#include "definitions.h"

extern int N;
extern double *cell_u1,*cell_u2,*cell_u3;

void applyBoundaryCondition(){

	
	//Periodic
	
	//Left boundary
	cell_u1[0] = cell_u1[N];
	cell_u2[0] = cell_u2[N];
        cell_u3[0] = cell_u3[N];

	cell_u1[1] = cell_u1[N+1];
	cell_u2[1] = cell_u2[N+1];
	cell_u3[1] = cell_u3[N+1];


	//Right boundary
	cell_u1[N+2] = cell_u1[2];
	cell_u2[N+2] = cell_u2[2];
	cell_u3[N+2] = cell_u3[2];

	cell_u1[N+3] = cell_u1[3];
	cell_u2[N+3] = cell_u2[3];
	cell_u3[N+3] = cell_u3[3];


/*	
	//Zero gradient
	//Left boundary
	cell_u1[0] = cell_u1[3];
	cell_u2[0] = cell_u2[3];
        cell_u3[0] = cell_u3[3];

	cell_u1[1] = cell_u1[2];
	cell_u2[1] = cell_u2[2];
	cell_u3[1] = cell_u3[2];


	//Right boundary
	cell_u1[N+2] = cell_u1[N+1];
	cell_u2[N+2] = cell_u2[N+1];
	cell_u3[N+2] = cell_u3[N+1];

	cell_u1[N+3] = cell_u1[N];
	cell_u2[N+3] = cell_u2[N];
	cell_u3[N+3] = cell_u3[N];
*/	


}
