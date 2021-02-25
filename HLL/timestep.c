#include "definitions.h"

extern int N;
extern double cfl,deltat;
extern double *cell_u1,*cell_u2,*cell_u3;
extern double dx;


void computeTimeStep(){
	
	double maxwavespeed=0.0;
	double rhol,rhor,ul,ur,el,er,pl,pr,r,uroe,hroe,aroe,temp,temp1,temp2,sl,sr,sm,flux[3],u1hllc,u2hllc,u3hllc;
	double hl,hr,al,ar;
	double rhoc, uc, ec, pc, ac;

//	double gamma=1.4;
//
	for(int i=2;i<=N+1;i++){
		rhoc = cell_u1[i];
		uc = cell_u2[i]/rhoc;
		ec = cell_u3[i];
		pc = 0.4 * (ec - 0.5*rhoc * (uc * uc));
		ac = sqrt(gamma*pc/rhoc);
		
		if(i==2){
			maxwavespeed = fabs(uc) + ac;
		}

		else{
			if(maxwavespeed>=(fabs(uc)+ac)){
				maxwavespeed = fabs(uc) + ac;

			}
		}	
			
	}	
/*
	for(int i=1;i<=N+1;i++){


		rhol=cell_u1[i];	rhor=cell_u1[i+1];
		
		ul=cell_u2[i]/rhol;	ur=cell_u2[i+1]/rhor;
		
		el=cell_u3[i];		er=cell_u3[i+1];
		
		pl = 0.4 * (el - 0.5*rhol * (ul * ul));	pr = 0.4 * (er - 0.5*rhor * (ur * ur));

		el = (pl/(gamma-1.0)) + 0.5*rhol*(ul*ul);	
		er = (pr/(gamma-1.0)) + 0.5*rhor*(ur*ur);

		hl = (el+pl)/rhol;	
		hr = (er+pr)/rhor;
	
		al = sqrt(1.4*pl/rhol);	
		ar = sqrt(1.4*pr/rhor);

		r = sqrt(rhor/rhol);

		uroe = (ul + r * ur)/(1+r);
		
		hroe = (hl + r * hr)/(1+r);
		
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
	

		if(maxwavespeed<sqrt(sl*sl))
		{				
			maxwavespeed = sqrt(sl*sl);
		}
			
		if(maxwavespeed<sqrt(sr*sr))
		{				
			maxwavespeed = sqrt(sr*sr);
		}


	}
*/

	deltat=dx * cfl /maxwavespeed;
	
}
