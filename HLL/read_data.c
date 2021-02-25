#include "definitions.h"

extern int N,NQuad;
extern double L,tmax,cfl;
extern int secondOrderFlag;
extern int itermax;

void read_data()
{
	int i;
	char comment[100];
	FILE *read;
	read=fopen("data","r");
	
	fscanf(read,"%lf%s",&L,comment);
	fscanf(read,"%d%s",&N,comment);
	fscanf(read,"%lf%s",&cfl,comment);

	fscanf(read,"%d%s",&itermax,comment);
	fscanf(read,"%lf%s",&tmax,comment);
	fscanf(read,"%d%s",&secondOrderFlag,comment);
	fscanf(read,"%d%s",&NQuad,comment);
	

	fclose(read);
}
