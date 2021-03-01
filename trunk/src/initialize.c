#include "definitions.h"
extern int N,problem;
extern double tmax;
extern double *cell_xc;
extern double *cell_u1,*cell_u2,*cell_u3;
extern double *netflux[3];
extern double *cell_u1_old, *cell_u2_old, *cell_u3_old;
extern double *drhobydx, *dubydx, *dPbydx;



void initialize()
{
	int i;
	
//	double gamma;
	
	double rho_initial,u_initial,p_initial,e_initial;
	
//	gamma=1.4;
	
	cell_u1 = (double *)malloc((N+4)*sizeof(double));
	
	cell_u2 = (double *)malloc((N+4)*sizeof(double));
	
	cell_u3 = (double *)malloc((N+4)*sizeof(double));
	
	cell_u1_old = (double *)malloc((N+4)*sizeof(double));
	
	cell_u2_old = (double *)malloc((N+4)*sizeof(double));
	
	cell_u3_old = (double *)malloc((N+4)*sizeof(double));
	
	drhobydx = (double *)malloc((N+4)*sizeof(double));
	
	dubydx  = (double *)malloc((N+4)*sizeof(double));
	
	dPbydx  = (double *)malloc((N+4)*sizeof(double));
	

	for(i=0;i<3;i++)
	{
		netflux[i] = (double *)malloc((N+4)*sizeof(double));
	}

	for(i=0;i<N+4;i++){
		cell_u1[i] =0.0;
		cell_u2[i] =0.0;
		cell_u3[i] =0.0;

		cell_u1_old[i] =0.0;
		cell_u2_old[i] =0.0;
		cell_u3_old[i] =0.0;

		drhobydx[i] =0.0;
		dubydx[i] =0.0;
		dPbydx[i] = 0.0;



	}	
	
	problem=1;	

	
switch(problem) 
{
case 1:
{	
double cellData[3];
	
//tmax=0.2;


for(i = 2;i<=N+1;i++)
	{

		localizedCosine( cell_xc[i],cellData,0.0);
	

		cell_u1[i] = cellData[0];                      /*Conserved variable 1*/    
		
		cell_u2[i] = cellData[1];         /*Conserved variable 1*/  
		
		cell_u3[i] = cellData[2];                        /*Conserved variable 1*/  

	}
break;
}

case 2:
{

double cellData[3];

for(i = 2;i<=N+1;i++)
	{

		line( cell_xc[i],cellData,0.0);
	
		cell_u1[i] = cellData[0];                      /*Conserved variable 1*/    
		
		cell_u2[i] = cellData[1];         /*Conserved variable 1*/  
		
		cell_u3[i] = cellData[2]; 


	}
break;
}


}//end switch loop//
}//end main loo//
