#include<malloc.h>
#include<stdlib.h>
#include<math.h>
void *FastCN(double *x, double *y, double *w, int N, int skip, double *C);

void FastCosine(double *x, double *y, double *w, 
				double *C, int N, int skip)
{
	y[0]=y[0]/2;
	y[N*skip]=y[N*skip]/2;
	FastCN(x,y,w,N,skip,C);
}