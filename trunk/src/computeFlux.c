#include "definitions.h"
extern double *cell_u1,*cell_u2,*cell_u3;
extern double *drhobydx, *dubydx, *dPbydx;
extern double dx;

void primitiveToConservative(double *Y, double *W){
  double e=(Y[2]/(gamma-1.0)) + 0.5*Y[0]*Y[1]*Y[1];
  W[0]=Y[0];
  W[1]=Y[0]*Y[1];
  W[2]=e;
}

void fluxRusanov(double *YL, double *YR, double *flux){
  double WL[3],WR[3];
  primitiveToConservative(YL,WL);
  primitiveToConservative(YR,WR);
			  
  double aL = sqrt(gamma*YL[2]/YL[0]);	
  double aR = sqrt(gamma*YR[2]/YR[0]);
  double lam = fmax( fabs(YL[1])+aL, fabs(YR[1])+aR);

  flux[0]= 0.5 * (WL[1] + WR[1]) - 0.5 * lam * (WR[0] - WL[0]) ;
  flux[1]= 0.5 * (WL[1] * YL[1] + YL[2] + WR[1] * YR[1] + YR[2]) - 0.5 * lam * (WR[1] - WL[1]) ;
  flux[2]= 0.5 * ((WL[2] + YL[2])*YL[1] + (WR[2] + YR[2])*YR[1]) - 0.5 * lam * (WR[2] - WL[2]) ;
  
}


void fluxHLL(double *YL, double *YR, double *Flux){
  double rhol,rhor,ul,ur,el,er,pl,pr,r,uroe,hroe,aroe,temp,temp1,temp2,sl,sr,sm,u1hllc,u2hllc,u3hllc;
  double hl,hr,al,ar;
  double rhol_old,rhor_old,ul_old,ur_old,el_old,er_old,pl_old,pr_old;
  double rhoc,uc,ec,pc;
  double drhoL, drhoR, duL, duR, dPL, dPR;

  rhol=YL[0];
  rhor=YR[0];
  ul=YL[1];
  ur=YR[1];
  pl=YL[2];
  pr=YR[2];
  
  
  //Obtain other reconstructed derived quantities
  el = (pl/(gamma-1.0)) + 0.5*rhol*(ul*ul);	
  er = (pr/(gamma-1.0)) + 0.5*rhor*(ur*ur);

  hl = (el+pl)/rhol;	
  hr = (er+pr)/rhor;
	
  al = sqrt(1.4*pl/rhol);	
  ar = sqrt(1.4*pr/rhor);


  //Step 1: Calculate the roe averages
		
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
		
				
	
  //Step2:Calculate HLL Flux
		
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

void fluxHLLC(double *YL, double *YR, double *flux){
  /* Implementation of the HLLC flux of Bouchut */
  double rhoL = YL[0];
  double uL   = YL[1];
  double pL   = YL[2];
  
  double rhoR = YR[0];
  double uR   = YR[1];
  double pR   = YR[2];
  
  double aL = sqrt(gamma*pL/rhoL);
  double aR = sqrt(gamma*pR/rhoR);
  double alpha = 0.5 * (gamma + 1.);
  double cL,cR;
  if (YR[2]-YL[2] >= 0){
    cL  = aL + alpha * fmax( (pR-pL)/(rhoR*aR) + uL-uR,0);
    cL *= rhoL;
    cR  = aR + alpha * fmax( (pL-pR)/cL + uL-uR,0);
    cR *= rhoR;
  }
  else {
    cR  = aR + alpha * fmax( (pL-pR)/(rhoL*aL) + uL-uR,0);
    cR *= rhoR;
    cL  = aL + alpha * fmax( (pR-pL)/cR + uL-uR,0);
    cL *= rhoL;
  }

  
  double ustar = (pL-pR + cL * uL + cR * uR)/(cL+cR);
  double pstar = (cL * pR + cR * pL + cL*cR *(uL-uR))/(cL+cR);
  double tauLstar = 1./rhoL + (cR*(uR-uL)+pL-pR)/(cL+cR)/cL;
  double tauRstar = 1./rhoR + (cL*(uR-uL)+pR-pL)/(cL+cR)/cR;
  double rhoLstar = 1./tauLstar;
  double rhoRstar = 1./tauRstar;
  double eL = pL/(gamma-1.)/rhoL;
  double eR = pR/(gamma-1.)/rhoR;
  double eLstar   = eL - 0.5 * (pL*pL - pstar*pstar)/cL/cL;
  double eRstar   = eR - 0.5 * (pR*pR - pstar*pstar)/cR/cR;

  if (uL-cL/rhoL > 0.){
    flux[0]= rhoL * uL;
    flux[1]= rhoL * uL * uL + pL;
    flux[2]= (pL/(gamma-1.)+ 0.5*rhoL*uL*uL +pL) * uL;
  }
  else if (ustar > 0.){
    flux[0]= rhoLstar * ustar;
    flux[1]= rhoLstar * ustar * ustar + pstar;
    flux[2]= rhoLstar * (eLstar + 0.5 * ustar*ustar ) * ustar + pstar * ustar;
  }
  else if (uR+cR/rhoR > 0.){
    flux[0]= rhoRstar * ustar;
    flux[1]= rhoRstar * ustar * ustar + pstar;
    flux[2]= rhoRstar * (eRstar + 0.5 * ustar*ustar ) * ustar + pstar * ustar;
  }
  else{
    flux[0]= rhoR * uR;
    flux[1]= rhoR * uR * uR + pR;
    flux[2]= (pR/(gamma-1.)+ 0.5*rhoR*uR*uR +pR) * uR;
  }
  
}


void computeFlux(int L, int R, double *Flux ){

  
  double YL[3],YR[3];
  double rhol_old,rhor_old,ul_old,ur_old,el_old,er_old,pl_old,pr_old;
	
  //Obtain the old solution
  rhol_old=cell_u1[L];				rhor_old=cell_u1[R];
	
  ul_old=cell_u2[L]/rhol_old;			ur_old=cell_u2[R]/rhor_old;
	
  el_old=cell_u3[L];				er_old=cell_u3[R];
	
  pl_old = (gamma-1.) * (el_old - 0.5*rhol_old * (ul_old * ul_old));	pr_old = (gamma-1.) * (er_old - 0.5*rhor_old * (ur_old * ur_old));

  //Obtain the reconstructed solution with limited slopes
  YL[0] = rhol_old + 0.5 * dx * drhobydx[L];
  YR[0] = rhor_old - 0.5 * dx * drhobydx[R];
	
  YL[1] = ul_old + 0.5 * dx * dubydx[L];
  YR[1] = ur_old - 0.5 * dx * dubydx[R];
	
  YL[2] = pl_old + 0.5 * dx * dPbydx[L];
  YR[2] = pr_old - 0.5 * dx * dPbydx[R];

  /*
  printf("drhobydxL = %lf \t dubydxL = %lf \t dPbydxL = %lf\n",drhobydx[L],dubydx[L],dPbydx[L]);
  printf("drhobydxR = %lf \t dubydxR = %lf \t dPbydxR = %lf\n",drhobydx[R],dubydx[R],dPbydx[R]);
  printf("rhoLold = %lf \t uLold=%lf \t pLold= %lf\n",rhol_old,ul_old,pl_old);
  printf("rhoRold = %lf \t uRold=%lf \t pRold= %lf\n",rhor_old,ur_old,pr_old);
  printf("rhoL = %lf \t uL=%lf \t pL= %lf\n",YL[0],YL[1],YL[2]);
  printf("rhoR = %lf \t uR=%lf \t pR= %lf\n",YR[0],YR[1],YR[2]);
  */
  
  fluxHLLC(YL,YR,Flux);
		
}
