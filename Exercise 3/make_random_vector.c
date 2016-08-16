#include<malloc.h>
#include<stdlib.h>
double *make_vector(int N);

double *make_random_vector(int N)
{
	double *M; int i;

	M=make_vector(N);
	for (i=0; i<=N; i++)
		M[i]=(double)rand()/(double)RAND_MAX;

	return(M);
}