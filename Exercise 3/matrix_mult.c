#include<malloc.h>
#include <stdlib.h>
#include<omp.h>
double **make_matrix(int NR, int NC);

double **matrix_mult
	(double **B, double **C, int L, int M)
{
	double **A;
	int i,j,k;

	A=make_matrix(L,M);
	for (i=1;i<=L;i++)
	{
		for (j=1;j<=M;j++)
			A[i][j]=0;
	}
	for (i=1;i<=L;i++)
	{
		for (j=1;j<=M;j++)
		{
			for (k=1;k<=L;k++)
				A[i][j]=A[i][j]+B[i][k]*C[k][j];
		}
	}
	return(A);
}