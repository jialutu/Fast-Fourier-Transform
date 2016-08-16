#include<malloc.h>
#include<stdlib.h>

double *make_vector(int N)
{
	double *M; int n;

	M=(double *)malloc((N+1)*sizeof(double));
	for (n=1; n<=N; n++) M[n]=M[n-1]+N+1;

	return(M);
}