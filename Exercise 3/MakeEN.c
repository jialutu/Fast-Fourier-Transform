#include<malloc.h>
#include<stdlib.h>
#include<math.h>
double **make_matrix(int NR, int NC);

double **MakeEN(int N)
{
	double **EN,pi=(16*atan(1/5)-4*atan(1/239));//pi=3.14159265358979323846;
	int i,j;
	
	EN=make_matrix(N,N);
	for (i=1; i<=N; i++)
	{
		for (j=1; j<=N; j++)
			EN[i][j]=cos((2*i-1)*(2*j-1)*pi/(4*N));
	}
	return(EN);
}