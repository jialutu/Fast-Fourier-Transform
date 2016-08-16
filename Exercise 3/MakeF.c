#include<malloc.h>
#include<stdlib.h>
#include<math.h>
double **make_matrix(int NR, int NC);

double **MakeF(int N)
{
	double **F;
	int i,j,k=0;

	F=make_matrix(N,N);
	for (i=0;i<=N;i++)
	{
		for (j=0;j<=N;j++)
			F[j][i]=0;
		if (i<N/2)
		{
			F[k][i]=1;
			F[N/2+k+1][i]=1;
			k++;
		}
		else if (i==N/2)
		{
			F[k][i]=1;
			k-=1;
		}
		else
		{
			F[k][i]=1;
			F[N/2+k+1][i]=-1;
			k-=1;
		}
	}
	return(F);
}