#include "definitions.h"

extern int N;
extern double *cell_xc,*cell_u1,*cell_u2,*cell_u3;
extern double dx;
extern int NQuad;


void computeError(double time){

	double l2Error=0.0;
	
	double quad_pts_temp1[] = {0.0, -1.0/sqrt(3.0), 1.0/sqrt(3.0), 0.0, -sqrt(3.0/5.0), sqrt(3.0/5.0), -0.339981, 0.339981, -0.861136, 0.861136 };
 	double quad_wts_temp1[] = {2.0, 1.0, 1.0, 8.0/9.0, 5.0/9.0, 5.0/9.0, 0.652145, 0.652145, 0.347855, 0.347855};

	int starting_index;

	double basis1, basis2;
	double cornerA, cornerB;
	double drhobydx;

	double quadCoord;
	double deltaX;
	double interpolatedRho;
	double error;
	double cellData[3];


	//printf("%lf\n",time);


	 if(NQuad==1){
		starting_index = 0;     
	 }
	 else if(NQuad==2){
		starting_index = 1;
	 }
	 else if(NQuad==3){
		starting_index = 3;
	 }
	 else if(NQuad==4){
		starting_index = 6;
	 }

  	for(unsigned int i=2;i<=N+1;i++) {
		
		drhobydx = (cell_u1[i+1]-cell_u1[i])/(dx);
			
//		printf("derivative:%lf\n",drhobydx);

	
		for(unsigned int iq=0;iq<NQuad;iq++){

			basis1 = 0.5*(1.0-quad_pts_temp1[starting_index+iq]);
			basis2 = 0.5*(1.0+quad_pts_temp1[starting_index+iq]);

			cornerA = cell_xc[i] - (dx/2.0);
			cornerB = cell_xc[i] + (dx/2.0);

			quadCoord = cornerA*basis1 + cornerB*basis2;
		
			//printf("cellcenter=%lf\n",cell_xc[i]);	
			//printf("A=%lf,B=%lf\n", cornerA, cornerB);
			//printf("quadCoord=%lf\n",quadCoord );


			deltaX = quadCoord - cell_xc[i];

			interpolatedRho = cell_u1[i]+drhobydx*deltaX;

			localizedCosine(quadCoord, cellData, time);
			//line(quadCoord, cellData, time);
			
	
	//		printf("interpolatedSol at iq=%d is :%lf\n",iq, interpolatedRho);
	//		printf("exactsol:%lf\n",cellData[0]);


			error = fabs(interpolatedRho- cellData[0]);

//			printf("%d,%d,%lf\n",i, iq, error);
			//printf("iq=%d, wts=%lf\n",iq, quad_wts_temp1[starting_index+iq]);
			l2Error += quad_wts_temp1[starting_index+iq]*error*error;
		}

  	}
	l2Error /= N;

	FILE *errorfile;
	
	errorfile = fopen("error.dat", "w");
	
	fprintf(errorfile,"Error= %lf",log(sqrt(l2Error)));

	printf("Sqrt Error is: %lf\n",sqrt(l2Error));

	fclose(errorfile);
}
