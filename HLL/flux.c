#include "definitions.h"
extern int N;
extern double *cell_u1,*cell_u2,*cell_u3,dx,*netflux[3],cfl,deltat;

void flux()
{

	int i,j;
	
	double rhol,rhor,ul,ur,el,er,pl,pr,r,uroe,hroe,aroe,temp,temp1,temp2,sl,sr,sm,flux[3],u1hllc,u2hllc,u3hllc;
	double hl,hr,al,ar;
	double maxwavespeed;
	
	maxwavespeed = 0;

	for(i=0;i<3;i++)
	{
		for(j=1;j<=N;j++)
		{
			netflux[i][j]=0;
		}
	}
		
	for(i=0;i<=N;i++)
	{
		
		rhol=cell_u1[i];	rhor=cell_u1[i+1];
		
		ul=cell_u2[i]/rhol;	ur=cell_u2[i+1]/rhor;
		
		el=cell_u3[i];		er=cell_u3[i+1];
		
		pl = 0.4 * (el - 0.5*rhol * (ul * ul));	pr = 0.4 * (er - 0.5*rhor * (ur * ur));

		hl=(el+pl)/rhol;	hr=(er+pr)/rhor;
	
		al = sqrt(1.4*pl/rhol);	ar=sqrt(1.4*pr/rhor);
		/*Step 1: Calculate the roe averages*/
		
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
		
				
		/*End Step 1*****------------*****----------*****----------*/

		
		/*Step2:Calculate HLL Flux*/
		
		if(sl>=0)
		{
			flux[0] = rhol * ul;
			
			flux[1] = rhol * ul * ul + pl;
			
			flux[2] = (el + pl) * ul;
		}
		
		if(sl<0 && sr>0)
		{
			flux[0] = (sr*rhol*ul-sl*rhor*ur + sl*sr*(rhor-rhol))/(sr-sl);
			
			flux[1] = (sr*(rhol*ul*ul+pl)-sl*(rhor*ur*ur+pr) + sl*sr*(rhor*ur-rhol*ul))/(sr-sl);
			
			flux[2] = (sr*(el+pl)*ul-sl*(er+pr)*ur + sl*sr*(er-el))/(sr-sl);
		}
		
		if(sr<=0)
		{
			flux[0] = rhor * ur;
			
			flux[1] = rhor * ur * ur + pr;
			
			flux[2] = (er + pr) * ur;
		}
		
		
		for(j=0;j<3;j++)
		{
			netflux[j][i]=netflux[j][i] + flux[j];
			netflux[j][i+1]=netflux[j][i+1] - flux[j];
		}
		
		
		/*End Step2:*****------------*****----------*****----------*/
		if(maxwavespeed<sqrt(sl*sl))
		{				
			maxwavespeed = sqrt(sl*sl);
		}
			
		if(maxwavespeed<sqrt(sr*sr))
		{				
			maxwavespeed = sqrt(sr*sr);
		}	
	/*printf("%d\t%lf\t%lf\t%lf\t%lf\n",i,ul-al,uroe-aroe,ur+ar,uroe+aroe);*/
	}	
	
	deltat=dx * cfl /maxwavespeed;
	
	

	

}
