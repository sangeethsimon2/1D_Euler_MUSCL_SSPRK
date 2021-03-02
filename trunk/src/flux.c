#include "definitions.h"
extern int N;
extern double *cell_u1,*cell_u2,*cell_u3,*netflux[3];
extern double *drhobydx, *dubydx, *dPbydx;
extern double dx;
extern int secondOrderFlag;


int sign(int x){
	if (x >= 0) return 1;
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

  double mm;
  double min = fmin(rL,rR);
  double max = fmax(rL,rR);
  double minabs = fmin(fabs(rL),fabs(rR));
  if (min * max < 0.){
    mm = 0.;
  }
  else {
    if (min > 0 ){
      mm = minabs;
    }
    else {
      mm = -minabs;
    }
  }
  return mm;
}

void computeSlopes(){

  int i;
	
  double rhol,rhor,ul,ur,el,er,pl,pr;
  double rhoc,uc,ec,pc;
  double drhoL, drhoR, duL, duR, dPL, dPR;

  //Initialize arrays to 0
  for(i=1;i<=N+2;i++)
    {
      drhobydx[i]=0.0;
      dubydx[i]=0.0;
      dPbydx[i]=0.0;
    }
	
  
  //Compute derivatives
  for(i=1;i<=N+2;i++)
    {
      //If we need a first order solution, then set derivatives to 0
      if(secondOrderFlag==0){

	drhobydx[i] = 0.0;
	dubydx[i]   = 0.0;
	dPbydx[i]   = 0.0;

		
      }

      else{
			
	//Obtain the left, cell and right states
	rhol = cell_u1[i-1];       rhoc = cell_u1[i];	     rhor = cell_u1[i+1];
	ul   = cell_u2[i-1]/rhol;  uc   = cell_u2[i]/rhoc;   ur   = cell_u2[i+1]/rhor;
	el   = cell_u3[i-1];	   ec   = cell_u3[i];	     er   = cell_u3[i+1];
			
	pl = (gamma-1.) * (el - 0.5*rhol * (ul * ul));	
	pc = (gamma-1.) * (ec - 0.5*rhoc * (uc * uc));	
	pr = (gamma-1.) * (er - 0.5*rhor * (ur * ur));


	//Compute left and right slopes
	drhoL = (rhoc - rhol)/dx;
	drhoR = (rhor - rhoc)/dx;

	duL = (uc - ul)/dx;
	duR = (ur - uc)/dx;

	dPL = (pc-pl)/dx;
	dPR = (pr-pc)/dx;

	/*
	//Use minmod to limit the function
	drhobydx[i] = minmod(drhoL, drhoR);
	dubydx[i]   = minmod(duL, duR);
	dPbydx[i]   = minmod(dPL, dPR);
	*/
	
	//use central difference to compute the function. Use only for smooth solutions.
	drhobydx[i] = 0.5 * (drhoL+ drhoR);
	dubydx[i]   = 0.5 * (duL+duR);
	dPbydx[i]   = 0.5 * (dPL+ dPR);
	
			
	/*
	  drhobydx[i] = vanAlbada(drhoL, drhoR,dx);
	  dubydx[i]   = vanAlbada(duL, duR,dx);
	  dPbydx[i]   = vanAlbada(dPL, dPR,dx);
	*/


      }	

		
    }//At this point we should have the derivatives at all the cells from 1 to Nx+2

}


void flux()
{
	int i,j;
	
	double flux[3];

	//Initialize arrays to 0
	for(i=0;i<3;i++)
	{
		for(j=2;j<=N+1;j++)
		{
			netflux[i][j]=0;
		}
	}

	//Method 1
	computeSlopes();
	for(i=1;i<=N+1;i++)//use this for computing fluxes on all interfaces of all cells from cell 2 to cell 11.
	{	
	
		computeFlux(i,i+1,flux);
	
		for(j=0;j<3;j++)
		{
			netflux[j][i]=netflux[j][i] + flux[j]/dx;
			netflux[j][i+1]=netflux[j][i+1] - flux[j]/dx;
		}
	}

	

				
	
}
