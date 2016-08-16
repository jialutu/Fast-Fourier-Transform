#include<malloc.h>
#include<stdlib.h>
#include<math.h>
double **make_matrix(int NR, int NC);

double **MakeP(int N)
{
	double **P;
	int i,j,k=0;

	P=make_matrix(N,N);
	for (i=0;i<=N;i++)
	{
		for (j=0;j<=N;j++)
			P[j][i]=0;
		P[k][i]=1;
		k+=2;
		if (k>N)
			k=1;
	}
	return(P);
}