#include "definitions.h"

extern int N;
extern double L,tmax,cfl;
extern double secondOrderFlag;

void read_data()
{
	int i;
	char comment[100];
	FILE *read;
	read=fopen("data","r");
	
	fscanf(read,"%lf%s",&L,comment);
	fscanf(read,"%d%s",&N,comment);
	/*fscanf(read,"%lf%s",&tmax,comment);*/
	fscanf(read,"%lf%s",&cfl,comment);
	fscanf(read,"%lf%s",&secondOrderFlag,comment);
	

	fclose(read);
}
