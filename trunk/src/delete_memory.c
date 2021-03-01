#include "definitions.h"
extern double *cell_xc,*cell_u1,*cell_u2,*cell_u3,*netflux[3];

void delete_memory()
{
	free(cell_xc);
	free(cell_u1);
	free(cell_u2);
	free(cell_u3);
	free(netflux[0]);
	free(netflux[1]);
	free(netflux[2]);
}
