#include "definitions.h"
extern int N,problem;
extern double *cell_xc,*cell_u1,*cell_u2,*cell_u3;


void output(int iteration)
{
	int i;
	double rho_temp,u_temp,a_temp,e_temp,pressure,sp_int_energy;

switch(problem) 
{
case 1:
{

	char str[50];
	//Convert the iteration(int) into string
	sprintf(str,"density%d.dat",iteration);

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
	//Convert the iteration(int) into string
	sprintf(str,"density%d.dat",iteration);

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

case 3:
{
	FILE *output_hll_3;
	
	output_hll_3 = fopen("output_hll_3.dat","w");
	

	
	for(i=1;i<=N;i++)
	{
		rho_temp= cell_u1[i];
		u_temp=cell_u2[i]/cell_u1[i];
		e_temp=cell_u3[i];
		pressure = 0.4*(e_temp - 0.5 * rho_temp * u_temp * u_temp);
		sp_int_energy=(e_temp/rho_temp)-0.5*u_temp*u_temp;
		fprintf(output_hll_3,"%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n",cell_xc[i],u_temp,pressure,rho_temp,e_temp,sp_int_energy);
		
		

	}
	fclose(output_hll_3);
break;
}

case 4:
{
	FILE *output_hll_4;
	
	output_hll_4 = fopen("output_hll_4.dat","w");
	

	
	for(i=1;i<=N;i++)
	{
		rho_temp= cell_u1[i];
		u_temp=cell_u2[i]/cell_u1[i];
		e_temp=cell_u3[i];
		pressure = 0.4*(e_temp - 0.5 * rho_temp * u_temp * u_temp);
		sp_int_energy=(e_temp/rho_temp)-0.5*u_temp*u_temp;
		fprintf(output_hll_4,"%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n",cell_xc[i],u_temp,pressure,rho_temp,e_temp,sp_int_energy);
		
		

	}
	fclose(output_hll_4);
break;
}

case 5:
{
	FILE *output_hll_5;
	
	output_hll_5 = fopen("output_hll_5.dat","w");
	

	
	for(i=1;i<=N;i++)
	{
		rho_temp= cell_u1[i];
		u_temp=cell_u2[i]/cell_u1[i];
		e_temp=cell_u3[i];
		pressure = 0.4*(e_temp - 0.5 * rho_temp * u_temp * u_temp);
		sp_int_energy=(e_temp/rho_temp)-0.5*u_temp*u_temp;
		fprintf(output_hll_5,"%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n",cell_xc[i],u_temp,pressure,rho_temp,e_temp,sp_int_energy);
		
		

	}
	fclose(output_hll_5);
break;
}

case 6:
{
	FILE *output_hll_6;
	
	output_hll_6 = fopen("output_hll_6.dat","w");
	

	
	for(i=1;i<=N;i++)
	{
		rho_temp= cell_u1[i];
		u_temp=cell_u2[i]/cell_u1[i];
		e_temp=cell_u3[i];
		pressure = 0.4*(e_temp - 0.5 * rho_temp * u_temp * u_temp);
		sp_int_energy=(e_temp/rho_temp)-0.5*u_temp*u_temp;
		fprintf(output_hll_6,"%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n",cell_xc[i],u_temp,pressure,rho_temp,e_temp,sp_int_energy);
		
		

	}
	fclose(output_hll_6);
break;
}


case 7:
{
	FILE *output_hll_7;
	
	output_hll_7 = fopen("output_hll_7.dat","w");
	

	
	for(i=1;i<=N;i++)
	{
		rho_temp= cell_u1[i];
		u_temp=cell_u2[i]/cell_u1[i];
		e_temp=cell_u3[i];
		pressure = 0.4*(e_temp - 0.5 * rho_temp * u_temp * u_temp);
		sp_int_energy=(e_temp/rho_temp)-0.5*u_temp*u_temp;
		fprintf(output_hll_7,"%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n",cell_xc[i],u_temp,pressure,rho_temp,e_temp,sp_int_energy);
		
		

	}
	fclose(output_hll_7);
break;
}
case 8:
{
	FILE *output_hll_8;
	
	output_hll_8 = fopen("output_hll_8.dat","w");
	

	
	for(i=1;i<=N;i++)
	{
		rho_temp= cell_u1[i];
		u_temp=cell_u2[i]/cell_u1[i];
		e_temp=cell_u3[i];
		pressure = 0.4*(e_temp - 0.5 * rho_temp * u_temp * u_temp);
		sp_int_energy=(e_temp/rho_temp)-0.5*u_temp*u_temp;
		fprintf(output_hll_8,"%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n",cell_xc[i],u_temp,pressure,rho_temp,e_temp,sp_int_energy);
		
		

	}
	fclose(output_hll_8);
break;
}	
}
}
