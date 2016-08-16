#include<malloc.h>
#include<stdlib.h>
#include<math.h>
double **MakeCN(int N);
void *FastDN(double *x, double *y, double *w, int N, int skip, double *C);

void *FastCN(double *x, double *y, double *w, int N, int skip, double *C)
{
	int i;

	if (N>3)
	{
		w[0]=y[0]+y[N]; 
		w[N/2]=y[N/2];
		w[N/2+1]=y[0]-y[N];

		for (i=1;i<N/2;i++)
		{
			w[i]=y[i]+y[N-i];
			w[i+N/2+1]=y[i]-y[N-i];
		}

		for (i=0;i<=N;i++)
			y[i]=w[i];

		N=N/2;
		skip=skip*2;

		FastCN(x,y,w,N,skip,C);
		FastDN(x+N,y+N,w,N,skip,C);

		for (i=0;i<=N*2;i++)
			w[(i*2)%(N*2+1)]=x[i];
		
		for (i=0;i<=N*2;i++)
			x[i]=w[i];
	}
	else if (N==2)
	{
		x[0]=y[0]+y[1]+y[2];
		x[1]=y[0]-y[2];
		x[2]=y[0]-y[1]+y[2];
	}
	else
	{
		x[0]=y[0]+y[1]+y[2]+y[3];
		x[1]=y[0]+y[1]/2-y[2]/2-y[3];
		x[2]=y[0]-y[1]/2-y[2]/2+y[3];
		x[3]=y[0]-y[1]+y[2]-y[3];
	}
	return(0);
}