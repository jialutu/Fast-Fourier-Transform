#include<math.h>
#include<malloc.h>
#include <stdlib.h>
double *make_vector(int N);

double norm(double *N, int n)
{
	double A;
	int i;

	A=0;
	for (i=0;i<=n;i++)
		A=A+N[i]*N[i];
	A=sqrt(A);

	return(A);
}