#include "definitions.h"
extern int N,problem;
extern double *cell_xc,*cell_u1_old,*cell_u2_old,*cell_u3_old;
void outputOldValues(int iteration)
{
	int i;
	double rho_temp,u_temp,a_temp,e_temp,pressure,sp_int_energy;

switch(problem) 
{
case 1:

{

	char str[50];
	//Convert the iteration(int) into string
	sprintf(str,"Density_OldValues%d.dat",iteration);

	FILE *outputOldValues;
	
	outputOldValues = fopen(str,"w");

	

	
	for(i=2;i<=N+1;i++)
	{
		rho_temp= cell_u1_old[i];
		u_temp=cell_u2_old[i]/cell_u1_old[i];
		e_temp=cell_u3_old[i];
		pressure = 0.4*(e_temp - 0.5 * rho_temp * u_temp * u_temp);
		sp_int_energy=(e_temp/rho_temp)-0.5*u_temp*u_temp;
		
		fprintf(outputOldValues,"%d\t%lf\n",i,rho_temp);
		
		
		//fprintf(output_hll_1,"%d\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n",i,cell_xc[i],u_temp,pressure,rho_temp,e_temp,sp_int_energy);
		
		

	}
	fclose(outputOldValues);
break;
}

case 2:
{
	char str[50];
	//Convert the iteration(int) into string
	sprintf(str,"Density_OldValues%d.dat",iteration);

	FILE *outputOldValues;
	
	outputOldValues = fopen(str,"w");



	for(i=2;i<=N+1;i++)
	{
		rho_temp= cell_u1_old[i];
		//u_temp=cell_u2[i]/cell_u1[i];
		//e_temp=cell_u3[i];
		//pressure = 0.4*(e_temp - 0.5 * rho_temp * u_temp * u_temp);
		//sp_int_energy=(e_temp/rho_temp)-0.5*u_temp*u_temp;
		
		fprintf(outputOldValues,"%d\t%lf\n",i,rho_temp);
		

	}
	fclose(outputOldValues);
break;
}

}

}
