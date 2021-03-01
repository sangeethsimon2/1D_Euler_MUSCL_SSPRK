#include "definitions.h"
extern int N,problem;
extern double *cell_xc,*cell_u1,*cell_u2,*cell_u3;


void outputForPrint(int iteration)
{
	int i;
	double rho_temp,u_temp,a_temp,e_temp,pressure,sp_int_energy;

switch(problem) 
{
case 1:
{

	char str[50];
	//Convert the iteration(int) into string
	
	if(iteration==0){

		sprintf(str,"density_initial.dat");
	}
	else{
		sprintf(str,"density_final.dat");

	}

	FILE *output_hll_1;
	
	output_hll_1 = fopen(str, "w");
	

	
	for(i=2;i<=N+1;i++)
	{
		rho_temp= cell_u1[i];
		u_temp=cell_u2[i]/cell_u1[i];
		e_temp=cell_u3[i];
		pressure = 0.4*(e_temp - 0.5 * rho_temp * u_temp * u_temp);
		sp_int_energy=(e_temp/rho_temp)-0.5*u_temp*u_temp;
		
		fprintf(output_hll_1,"%d\t%lf\n",i,rho_temp);
		
		
		//fprintf(output_hll_1,"%d\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n",i,cell_xc[i],u_temp,pressure,rho_temp,e_temp,sp_int_energy);
		
		

	}
	fclose(output_hll_1);
break;
}

case 2:
{
	char str[50];
	if(iteration==0){

		sprintf(str,"density_initial.dat");
	}
	else{
		sprintf(str,"density_final.dat");

	}

	FILE *output_hll_2;
	
	output_hll_2 = fopen(str, "w");
	
	for(i=2;i<=N+1;i++)
	{
		rho_temp= cell_u1[i];
		//u_temp=cell_u2[i]/cell_u1[i];
		//e_temp=cell_u3[i];
		//pressure = 0.4*(e_temp - 0.5 * rho_temp * u_temp * u_temp);
		//sp_int_energy=(e_temp/rho_temp)-0.5*u_temp*u_temp;
		
		fprintf(output_hll_2,"%d\t%lf\n",i,rho_temp);
		

	}
	fclose(output_hll_2);
break;
}

}
}
