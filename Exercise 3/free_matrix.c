#include<malloc.h>
#include <stdlib.h>

void free_matrix(double **M)
{
	free(M[0]);
	free(M);
}
