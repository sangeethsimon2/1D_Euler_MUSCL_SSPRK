#include "definitions.h"

int N,problem, NQuad;
double L,tmax,cfl;
double *cell_xc;
double dx;
double *cell_u1,*cell_u2,*cell_u3,*netflux[3];
double *cell_u1_old, *cell_u2_old, *cell_u3_old;
double *drhobydx, *dubydx, *dPbydx;
double deltat;
int secondOrderFlag;
int itermax;

int main()
{
	int i,j;
	int iter;
	double time;

	//Read data from 'data' file	
	read_data();
	printf("L=%lf\n", L);
	printf("N=%d\n", N);
	printf("CFL=%lf\n", cfl);
	printf("itermax=%d\n",itermax);
	printf("tmax=%lf\n",tmax);
 	printf("secondOrderFlag=%d\n",secondOrderFlag);
	printf("NQuad=%d\n",NQuad);


	//prepapre the grid
	grid();
	//Initialize internal cells
	initialize();
	
	deltat=0;
	time =0;
	iter=0;
	int subiteration=0;



        //use this for printing output at any iteration level
	//output(iter);	
	//use this for printing inital and final output files
	outputForPrint(iter);

	//Intitialize a RK method variable 
  	int timeAccuracy=0;
  	
	//Time loop
	//while(iter<1) {
  	while(time<tmax){
        	//Increment the RK time step variable to 1 to indicate that we are about to deal with the first RK step
        	timeAccuracy +=1;

        	//Compute time step only for the first RK time step 
        	if(timeAccuracy==1){
              	
			//Both periodic and open boundary conditions available
			applyBoundaryCondition();

			computeTimeStep();

			//Compute limite derivatives, reconstructed solution and interface flux
			flux();

			//Copy the solution from cell_u1 var to cell_u1_old var before updating the former
			copySolution();
		
			//First stage RK update
			update();
					
			subiteration++;	
		
	        	//If we need only a first order accuracy
                	if(secondOrderFlag==0){
                        	timeAccuracy = 0;
				if(time+deltat>=tmax){
					deltat = tmax-time;
				}
                        	time+=deltat;
				iter++;
                	}

        	}

        	if(timeAccuracy==2){
           		
			applyBoundaryCondition();

			flux();

			//Second stage RK update
			updateSecondOrder();

                	//Reset the RK step counter
                	timeAccuracy = 0;

                	//Increment the time and iteration
			if(time+deltat>=tmax){
				deltat = tmax-time;
			}

			time+=deltat;

                	iter++;

			subiteration++;


        	}

           }

	printf("Final time is:%lf\n", time);

	
	//	output(iter);
	outputForPrint(iter);
	
	//Compute the L2 norm here. 
	computeError(time);

	delete_memory();
	return 0;
	
}

	
	

