#include<stdio.h>
#include<malloc.h>
#include <stdlib.h>

void print_matrix(double **M, int NR, int NC)
{
	int i,j;
	printf("\n%d by %d Matrix: \n",NR+1,NC+1);
	for (i=0; i<=NR; i++)
	{
		printf("\n");
		for (j=0; j<=NC; j++)
			printf("%12g",M[i][j]);
	}
	printf("\n\n");
}