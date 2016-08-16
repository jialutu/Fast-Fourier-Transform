#include<malloc.h>
#include <stdlib.h>
double *make_vector(int N);

double *vec_sub(double *B, double *C, int n)
{
	double *A;
	int i;

	A=make_vector(n);

	for (i=0;i<=n;i++)
		A[i]=B[i]-C[i];

	return(A);
}