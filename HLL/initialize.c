#include "definitions.h"
extern int N,problem;
extern double *cell_xc,*cell_u1,*cell_u2,*cell_u3,*netflux[3],tmax;



void initialize()
{
	int i;
	
	double gamma;
	
	double rho_initial,u_initial,p_initial,e_initial;
	
	gamma=1.4;
	
	cell_u1 = (double *)malloc((N+2)*sizeof(double));
	
	cell_u2 = (double *)malloc((N+2)*sizeof(double));
	
	cell_u3 = (double *)malloc((N+2)*sizeof(double));
	
	for(i=0;i<3;i++)
	{
		netflux[i] = (double *)malloc((N+2)*sizeof(double));
	}
	
	
	problem=1;
	/*
	printf("\nEnter Toro problem no from 1 to 8\n");
	scanf("%d",& problem);
	printf("\n Problem = %d\n",problem);
	*/

	

	
switch(problem) 
{
case 1:
{	
tmax=0.2;
for(i = 2;i<=N+1;i++)
	{
	
		if(cell_xc[i]<0.30)                    
		{
			rho_initial = 1;    p_initial = 1;             
			u_initial = 0.75;                       
			  
           
		}

		else                                   
		{
			rho_initial = 0.125;  p_initial = 0.1;                        
			u_initial = 0;                        
			
                     
		}
e_initial = 0.5 * rho_initial * u_initial * u_initial + p_initial/(gamma-1);      /*Energy*/
		 
		cell_u1[i] = rho_initial;                      /*Conserved variable 1*/    
		
		cell_u2[i] = rho_initial * u_initial;         /*Conserved variable 1*/  
		
		cell_u3[i] = e_initial;                        /*Conserved variable 1*/  

	}
break;
}
/*
case 2:
{
tmax=0.15;
for(i = 0;i<=N+1;i++)
	{
		
		if(cell_xc[i]<0.50)                    
		{
			rho_initial = 1;  
			p_initial = 0.4;             
			u_initial = -2;                       
			 
           
		}

		else                                   
		{
			rho_initial = 1;
			p_initial = 0.4;                      
			u_initial = 2;                        
			
                     
		}
e_initial = 0.5 * rho_initial * u_initial * u_initial + p_initial/(gamma-1);      //Energy
		 
		cell_u1[i] = rho_initial;                      //Conserved variable 1//    
		
		cell_u2[i] = rho_initial * u_initial;         //Conserved variable 1/  
		
		cell_u3[i] = e_initial;                        //Conserved variable 1/  
}
break;
}

case 3:
{
tmax=0.012;
for(i = 0;i<=N+1;i++)
	{		
		
		if(cell_xc[i]<0.50)                    
		{
			rho_initial = 1;                 
			u_initial = 0;                       
			p_initial = 1000;  
           
		}

		else                                   
		{
			rho_initial = 1;                         
			u_initial = 0;                        
			p_initial = 0.01; 
                     
		}
e_initial = 0.5 * rho_initial * u_initial * u_initial + p_initial/(gamma-1);      //Energy/
		 
		cell_u1[i] = rho_initial;                      //Conserved variable 1//    
		
		cell_u2[i] = rho_initial * u_initial;         //Conserved variable 1/  
		
		cell_u3[i] = e_initial;                        //Conserved variable 1//  
}
break;
}

case 4:
{	
tmax=0.035;
for(i = 0;i<=N+1;i++)
	{	
		
		if(cell_xc[i]<0.40)                    
		{
			rho_initial = 5.99924;    p_initial = 460.894;              
			u_initial = 19.5975;                       
			 
           
		}

		else                                   
		{
			rho_initial = 5.99242;   p_initial = 46.095;                       
			u_initial = -6.19633;                        
			
                     
		}
e_initial = 0.5 * rho_initial * u_initial * u_initial + p_initial/(gamma-1);      //Energy/
		 
		cell_u1[i] = rho_initial;                      //Conserved variable 1//    
		
		cell_u2[i] = rho_initial * u_initial;         //Conserved variable 1/  
		
		cell_u3[i] = e_initial;                        //Conserved variable 1//  
}
break;
}

case 5:
{	
tmax=0.012;
for(i = 0;i<=N+1;i++)
	{	
		
		if(cell_xc[i]<0.80)                    
		{
			rho_initial = 1;                 
			u_initial = -19.59745;                       
			p_initial = 1000;  
           
		}

		else                                   
		{
			rho_initial = 1;                         
			u_initial = -19.59745;                        
			p_initial = 0.01; 
                     
		}
e_initial = 0.5 * rho_initial * u_initial * u_initial + p_initial/(gamma-1);      //Energy//
		 
		cell_u1[i] = rho_initial;                      //Conserved variable 1//    
		
		cell_u2[i] = rho_initial * u_initial;         //Conserved variable 1//  
		
		cell_u3[i] = e_initial;                        //Conserved variable 1//  
}
break;
}

case 6:
{	
tmax=2;
for(i = 0;i<=N+1;i++)
	{	
		

		if(cell_xc[i]<0.50)                    
		{
			rho_initial  = 1.4;                 
			u_initial = 0;                       
			p_initial = 1;  
           
		}

		else                                   
		{
			rho_initial = 1;                         
			u_initial = 0;                        
			p_initial = 1; 
                     
		}
e_initial = 0.5 * rho_initial * u_initial * u_initial + p_initial/(gamma-1);      //Energy//
		 
		cell_u1[i] = rho_initial;                      //Conserved variable 1//    
		
		cell_u2[i] = rho_initial * u_initial;         //Conserved variable 1//  
		
		cell_u3[i] = e_initial;                        //Conserved variable 1//  
}
break;
}

case 7:
{	
tmax=2;
for(i = 0;i<=N+1;i++)
	{
		
		if(cell_xc[i]<0.50)                    
		{
			rho_initial = 1.4;                 
			u_initial = 0.1;                       
			p_initial = 1;  
           
		}

		else                                   
		{
			rho_initial = 1;                         
			u_initial = 0.1;                        
			p_initial = 1; 
                     
		}
e_initial = 0.5 * rho_initial * u_initial * u_initial + p_initial/(gamma-1);      //Energy//
		 
		cell_u1[i] = rho_initial;                      //Conserved variable 1/    
		
		cell_u2[i] = rho_initial * u_initial;         //Conserved variable 1/  
		
		cell_u3[i] = e_initial;                        //Conserved variable 1/  
}
break;
}
case 8:
{	
tmax=0.8;
for(i = 0;i<=N+1;i++)
	{
		
		if(cell_xc[i]<0.50)                    
		{
			rho_initial = 1.0;                 
			u_initial = 2.0;                       
			p_initial = 0.1;  
           
		}

		else                                   
		{
			rho_initial = 1.0;                         
			u_initial = -2.0;                        
			p_initial = 0.1; 
                     
		}
e_initial = 0.5 * rho_initial * u_initial * u_initial + p_initial/(gamma-1);      //Energy//
		 
		cell_u1[i] = rho_initial;                      //Conserved variable 1//    
		
		cell_u2[i] = rho_initial * u_initial;         //Conserved variable 1//  
		
		cell_u3[i] = e_initial;                        //Conserved variable 1//  
}
break;
}
*/


}//end switch loop//
}//end main loo//
