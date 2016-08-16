#include<malloc.h>
#include<stdlib.h>
#include<math.h>
double **MakeEN(int N);
void *FastDN(double *x, double *y, double *w, int N, int skip, double *C);

void *FastEN(double *x, double *y, double *w, int N, int skip, double *C)
{
	double pi=3.14159265358979323846,n;
	int i,k,l;

	if (N>3)
	{
		w[1]=y[1];
		w[N/2+1]=y[N];
		for (i=2; i<=N/2; i++)
		{
			w[i]=y[(i-1)*2]+y[2*i-1];
			w[N-i+2]=y[(i-1)*2]-y[2*i-1];
		}

		for (i=1;i<=N;i++)
			y[i]=w[i];

		N=N/2;
		skip*=2;

		FastDN(x,y,w,N,skip,C);
		FastDN(x+N,y+N,w,N,skip,C);

		k=N*2-2;
		l=N*4-1;

		for (i=1;i<=N;i+=2)
		{
			w[i]=x[i]*C[k+i]+x[N+i]*C[l-i];
			w[N*2+1-i]=x[i]*C[l-i]-x[N+i]*C[k+i];
		}

		for (i=2;i<=N;i+=2)
		{
			w[i]=x[i]*C[k+i]-x[N+i]*C[l-i];
			w[N*2+1-i]=x[i]*C[l-i]+x[N+i]*C[k+i];
		}

		for (i=1;i<=N*2;i++)
			x[i]=w[i];
	}
	else if (N==2)
	{
		n=cos(3*pi/8);
		x[1]=y[1]*C[1]+y[2]*n;
		x[2]=y[1]*n-y[2]*C[1];
	}
	else
	{
		x[1]=y[1]*C[2]+y[2]*C[3]+y[3]*C[4];
		x[2]=y[1]*C[3]-y[2]*C[3]-y[3]*C[3];
		x[3]=y[1]*C[4]-y[2]*C[3]+y[3]*C[2];
	}
	return(0);
}