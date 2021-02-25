#include "definitions.h"

extern double *cell_u1,*cell_u2,*cell_u3;
extern double *cell_u1_old, *cell_u2_old, *cell_u3_old;
extern int N;

void copySolution(){


	for(int i=2;i<=N+1;i++){

		cell_u1_old[i] = cell_u1[i];
		cell_u2_old[i] = cell_u2[i];
		cell_u3_old[i] = cell_u3[i];

	}

}
