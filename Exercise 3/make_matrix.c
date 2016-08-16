#include<malloc.h>
#include<stdlib.h>

double **make_matrix(int NR, int NC)
{
	double **M; int n;

	M=(double **)malloc((NR+1)*sizeof(double *));
	M[0]=(double *)malloc(((NR+1)*(NC+1))*sizeof(double));
	for (n=1; n<=NR; n++) M[n]=M[n-1]+NC+1;

	return(M);
}