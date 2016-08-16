#include<stdio.h>
#include<malloc.h>
#include <stdlib.h>

void print_vector(double *M, int N)
{
	int i;

	for (i=0; i<=N; i++)
		printf("%12g\n",M[i]);
	printf("\n\n");
}