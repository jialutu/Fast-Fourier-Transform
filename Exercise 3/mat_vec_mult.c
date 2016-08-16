#include<malloc.h>
#include <stdlib.h>
double *make_vector(int N);

double *mat_vec_mult(double **M, double *N, int n)
{
	double *A;
	int i,j;

	A=make_vector(n);
	for (i=0;i<=n;i++)
	{
		A[i]=0;
		for (j=0;j<=n;j++)
			A[i]=A[i]+N[j]*M[i][j];
	}
	return(A);
}