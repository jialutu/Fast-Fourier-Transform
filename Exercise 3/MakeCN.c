#include<malloc.h>
#include<stdlib.h>
#include<math.h>
//#define M_PI 3.14159265358979323846
double **make_matrix(int NR, int NC);

double **MakeCN(int N)
{
	double **CN,pi=3.14159265358979323846;
	int i,j;

	CN=make_matrix(N,N);
	for (i=0; i<=N; i++)
	{
		for (j=0; j<=N; j++)
			CN[i][j]=cos(i*j*pi/N);
	}
	return(CN);
}