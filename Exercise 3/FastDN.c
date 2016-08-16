#include<malloc.h>
#include<stdlib.h>
#include<math.h>
double **MakeDN(int N);
void *FastEN(double *x, double *y, double *w, int N, int skip, double *C);

void *FastDN(double *x, double *y, double *w, int N, int skip, double *C)
{
	int i;

	if (N>3)
	{
		for (i=1;i<=N/2;i++)
		{
			w[i]=y[2*i-1];
			w[N/2+i]=y[2*i];
		}

		for (i=1;i<=N;i++)
			y[i]=w[i];

		N=N/2;
		skip*=2;

		FastDN(x,y,w,N,skip,C);
		FastEN(x+N,y+N,w,N,skip,C);

		for (i=1;i<=N;i++)
		{
			w[i]=x[i]+x[i+N];
			w[N*2-i+1]=x[i]-x[i+N];
		}

		for (i=1;i<=N*2;i++)
			x[i]=w[i];
	}
	else if (N==2)
	{
		x[1]=y[1]+y[2]/sqrt(2.);
		x[2]=y[1]-y[2]/sqrt(2.);
	}
	else
	{
		x[1]=y[1]+sqrt(3.)*y[2]/2+y[3]/2;
		x[2]=y[1]-y[3];
		x[3]=y[1]-sqrt(3.)*y[2]/2+y[3]/2;
	}
	return(0);
}