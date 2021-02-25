#include "definitions.h"
extern int N;
extern double *cell_u1,*cell_u2,*cell_u3,*netflux[3];
extern double *drhobydx, *dubydx, *dPbydx;
extern double dx;
extern int secondOrderFlag;


int sign(int x){
	if (x > 0) return 1;
	if (x < 0) return -1;
	return 0;
}


/*
double vanAlbada(double rL, double rR, double h){
	double eps = pow((0.3*h),3.0);
	double va = 0.5*(sign(rL)*sign(rR)+1.0)*( (pow(rR,2.0)+eps)*rL+(pow(rL,2.0)+eps)*rR )/(pow(rL,2.0)+pow(rR,2.0)+2.0*eps);
	return(va);
	
}
*/


double minmod(double rL, double rR){
int s = (sign(rL)+sign(rR))/2;

	if(fabs(s)==1){
		return(s*fmin(fabs(rL),fabs(rR)));
	}

	else{
		return(0.0);
	}

}


void flux()
{

	int i,j;
	
	double rhol,rhor,ul,ur,el,er,pl,pr,r,uroe,hroe,aroe,temp,temp1,temp2,sl,sr,sm,flux[3],u1hllc,u2hllc,u3hllc;
	double hl,hr,al,ar;
	double rhol_old,rhor_old,ul_old,ur_old,el_old,er_old,pl_old,pr_old;
	double rhoc,uc,ec,pc;
	double drhoL, drhoR, duL, duR, dPL, dPR;

	for(i=0;i<3;i++)
	{
		for(j=2;j<=N+1;j++)
		{
			netflux[i][j]=0;
		}
	}

	for(i=1;i<=N+2;i++)
	{
		drhobydx[i]=0.0;
		dubydx[i]=0.0;
		dPbydx[i]=0.0;


	}
	
	//Compute derivatives
	for(i=1;i<=N+2;i++)
	{
		if(secondOrderFlag==0){

			drhobydx[i] = 0.0;
			dubydx[i]   = 0.0;
			dPbydx[i]   = 0.0;

		//	printf("But first I am here\n");


		}

		else{
			
			//Obtain the left, cell and right states
			rhol = cell_u1[i-1];       rhoc = cell_u1[i];	     rhor = cell_u1[i+1];
			ul   = cell_u2[i-1]/rhol;  uc   = cell_u2[i]/rhoc;   ur   = cell_u2[i+1]/rhor;
			el   = cell_u3[i-1];	   ec   = cell_u3[i];	     er   = cell_u3[i+1];
			
			pl = 0.4 * (el - 0.5*rhol * (ul * ul));	
			pc = 0.4 * (ec - 0.5*rhoc * (uc * uc));	
			pr = 0.4 * (er - 0.5*rhor * (ur * ur));


			//Compute left and right slopes
			drhoL = (rhoc - rhol);// /dx;
			drhoR = (rhor - rhoc);// /dx;

			duL = (uc - ul); // /dx;
			duR = (ur - uc); // /dx;

			dPL = (pc-pl); // /dx;
			dPR = (pr-pc); // /dx;

			
			drhobydx[i] = minmod(drhoL, drhoR);
			dubydx[i]   = minmod(duL, duR);
			dPbydx[i]   = minmod(dPL, dPR);
			
			
			/*
			drhobydx[i] = fmax(drhoL, drhoR);
			dubydx[i]   = fmax(duL,duR);
			dPbydx[i]   = fmax(dPL, dPR);
			*/

			/*
			drhobydx[i] = vanAlbada(drhoL, drhoR,dx);
			dubydx[i]   = vanAlbada(duL, duR,dx);
			dPbydx[i]   = vanAlbada(dPL, dPR,dx);
			*/


	}	

		
	}//At this point we should have the derivatives at all the cells from 1 to Nx+2
		


	//Method 1
	
	for(i=1;i<=N+1;i++)//use this for computing fluxes on all interfaces of all cells from cell 2 to cell 11.
	{	
	
		computeFlux(i,i+1,flux);
	
		for(j=0;j<3;j++)
		{
			netflux[j][i]=netflux[j][i] + flux[j];
			netflux[j][i+1]=netflux[j][i+1] - flux[j];
		}
	}


	/*
	//Method 2
	
	for(i=2;i<=N;i++)//Use this for computing fluxes on all interfaces except left face of cell 2 and right face of cell 11.
	{
	
		computeFlux(i,i+1,flux);
	
		for(j=0;j<3;j++)
		{
			netflux[j][i]=netflux[j][i] + flux[j];
			netflux[j][i+1]=netflux[j][i+1] - flux[j];
		}
	}

	//Compute flux between the cells 1 and 2
	*/			
	
}
