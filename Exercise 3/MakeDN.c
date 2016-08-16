#include<malloc.h>
#include<stdlib.h>
#include<math.h>
double **make_matrix(int NR, int NC);

double **MakeDN(int N)
{
	double **DN,pi=(16*atan(1/5)-4*atan(1/239));//pi=3.14159265358979323846;
	int i,j;
	
	DN=make_matrix(N,N);	
	for (i=1; i<=N; i++)
	{
		for (j=0; j<=N-1; j++)
			DN[i][j]=cos((2*i-1)*j*pi/(2*N));
	}
	return(DN);
}