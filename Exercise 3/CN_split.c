#include<malloc.h>
#include<stdlib.h>
#include<math.h>
double **make_matrix(int NR, int NC);
double **MakeCN(int N);
double **MakeDN(int N);

double **CN_split(int N)
{
	double **CN, **DN, **CN_split;
	int i,j;

	CN_split=make_matrix(N,N);
	CN=MakeCN(N/2);
	DN=MakeCN(N/2);

	for (i=0;i<=N/2;i++)
	{
		for (j=0;j<=N/2;j++)
			CN_split[i][j]=CN[i][j];
		for (j=N/2+1;j<=N;j++)
			CN_split[i][j]=0;
	}
	for (i=N/2+1;i<=N;i++)
	{
		for (j=0;j<=N/2;j++)
			CN_split[i][j]=0;
		for (j=N/2+1;j<=N;j++)
			CN_split[i][j]=DN[i][j];
	}


}