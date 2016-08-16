#include<malloc.h>
#include<stdlib.h>
#include<math.h>
double *make_vector(int N);

double *MakeC(int N)
{
	double *C,pi=3.14159265358979323846;
	int i,j,k;
	
	if (N%3==0)
	{
		if (N>3)
			C=make_vector(N/2-1);
		else 
			C=make_vector(N);
		C[0]=cos(pi/3);
		C[1]=cos(pi/6);
		k=2;
		for (i=12; i<=N; i*=2)
		{
			for (j=1; j<=(i/2-1); j+=2)
			{
				C[k]=cos(j*pi/i);
				k++;
			}
		}
	}
	else
	{
		k=0;
		C=make_vector(N/2-1);
		for (i=4; i<=N; i*=2)
		{
			for (j=1; j<=(i/2-1); j+=2)
			{
				C[k]=cos(j*pi/i);
				k++;
			}
		}
	}
	return(C);
}