#include "definitions.h"
extern double *cell_u1,*cell_u2,*cell_u3;
extern double *drhobydx, *dubydx, *dPbydx;


void computeFluxAtBoundary(int L, int R, double *Flux, char tag ){

	
	double rhol,rhor,ul,ur,el,er,pl,pr,r,uroe,hroe,aroe,temp,temp1,temp2,sl,sr,sm,u1hllc,u2hllc,u3hllc;
	double hl,hr,al,ar;
	double rhol_old,rhor_old,ul_old,ur_old,el_old,er_old,pl_old,pr_old;
	double rhoc,uc,ec,pc;
	double drhoL, drhoR, duL, duR, dPL, dPR;

	if(tag=='L'){

		//Obtain the old solution from the interior cell 2
		rhor_old=cell_u1[R];
		
		ur_old=cell_u2[R]/rhor_old;
		
		er_old=cell_u3[R];
		
		pr_old = 0.4 * (er_old - 0.5*rhor_old * (ur_old * ur_old));


		//Obtain the reconstructed solution with limited slopes
	//	rhol = rhol_old + drhobydx[L]/2.0; // *(dx/2.0);
		rhor = rhor_old - drhobydx[R]/2.0; //*(dx/2.0);
		rhol = rhor;

		//printf("%d\t%lf\t%lf\n",i,rhol, rhor);
		//ul = ul_old + dubydx[L]/2.0;  //*(dx/2.0);
		ur = ur_old - dubydx[R]/2.0; //*(dx/2.0);
		ul = ur;

	//	printf("%d\t%lf\t%lf\n",i,ul, ur);

		//pl = pl_old + dPbydx[L]/2.0;//*(dx/2.0);
		pr = pr_old - dPbydx[R]/2.0;  //*(dx/2.0);
		pl = pr;

		//printf("%d\t%lf\t%lf\n",i,pl, pr);
	}

	else if(tag=='R'){

		//Obtain the old solution from the interior cell N+1
		rhol_old=cell_u1[L];				
		
		ul_old=cell_u2[L]/rhol_old;			
		
		el_old=cell_u3[L];				
		
		pl_old = 0.4 * (el_old - 0.5*rhol_old * (ul_old * ul_old));


		//Obtain the reconstructed solution with limited slopes
		rhol = rhol_old + drhobydx[L]/2.0; // *(dx/2.0);
		//rhor = rhor_old - drhobydx[R]/2.0; //*(dx/2.0);
		rhor = rhol;

		//printf("%d\t%lf\t%lf\n",i,rhol, rhor);
	
		ul = ul_old + dubydx[L]/2.0;  //*(dx/2.0);
		//ur = ur_old - dubydx[R]/2.0; //*(dx/2.0);
		ur = ul;

	//	printf("%d\t%lf\t%lf\n",i,ul, ur);

		pl = pl_old + dPbydx[L]/2.0;//*(dx/2.0);
		//pr = pr_old - dPbydx[R]/2.0;  //*(dx/2.0);
		pr = pl;

		//printf("%d\t%lf\t%lf\n",i,pl, pr);


	}

		
		//Obtain other reconstructed derived quantities
		el = (pl/(gamma-1.0)) + 0.5*rhol*(ul*ul);	
		er = (pr/(gamma-1.0)) + 0.5*rhor*(ur*ur);

		hl = (el+pl)/rhol;	
		hr = (er+pr)/rhor;
	
		al = sqrt(1.4*pl/rhol);	
		ar = sqrt(1.4*pr/rhor);


		/*Step 1: Calculate the roe averages*/
		
		r = sqrt(rhor/rhol);

		uroe = (ul + r * ur)/(1.0+r);
		
		hroe = (hl + r * hr)/(1.0+r);
		
		aroe = sqrt(0.4 * (hroe - 0.5 * (uroe * uroe )));
		
		
		temp1 = ul - al;
		
		temp2 = uroe - aroe;
		
		if(temp1<temp2)
		{
			sl = temp1;
		}
		else
		{
			sl = temp2;
		}
		
		temp1 = ur + ar;
		
		temp2 = uroe + aroe;
		
		if(temp1>temp2)
		{
			sr = temp1;
		}
		else
		{
			sr = temp2;
		}
		
					
		/*Step2:Calculate HLL Flux*/
		
		if(sl>=0)
		{
			Flux[0] = rhol * ul;
			
			Flux[1] = rhol * ul * ul + pl;
			
			Flux[2] = (el + pl) * ul;
		}
		
		if(sl<0 && sr>0)
		{
			Flux[0] = (sr*rhol*ul-sl*rhor*ur + sl*sr*(rhor-rhol))/(sr-sl);
			
			Flux[1] = (sr*(rhol*ul*ul+pl)-sl*(rhor*ur*ur+pr) + sl*sr*(rhor*ur-rhol*ul))/(sr-sl);
			
			Flux[2] = (sr*(el+pl)*ul-sl*(er+pr)*ur + sl*sr*(er-el))/(sr-sl);
		}
		
		if(sr<=0)
		{
			Flux[0] = rhor * ur;
			
			Flux[1] = rhor * ur * ur + pr;
			
			Flux[2] = (er + pr) * ur;
		}
		


}
