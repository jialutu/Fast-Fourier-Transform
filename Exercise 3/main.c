#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<time.h>
double *MakeC(int N);
void print_vector(double *M, int N);
void print_matrix(double **M, int NR, int NC);
double **MakeCN(int N);
double *make_vector(int N);
void FastCosine(double *x, double *y, double *w, 
				double *C, int N, int skip);
double *make_random_vector(int N);
double *mat_vec_mult(double **M, double *N, int n);
void free_vector(double *M);
void free_matrix(double **M);
double *vec_sub(double *B, double *C, int n);
double norm(double *N, int n);

int main(void)
{
	double *C, *x, *y, *w, *A, **CN, then, now, diff, then2, now2, diff2;
	int N, skip, i;

	printf("Name:\t\tJialu Tu\n");
	printf("Email Address:\tjialu.tu06@imperial.ac.uk\n");
	printf("Course Code:\tG100\n");
	printf("Module Code:\tM3SC\n");
	printf("Date:\t\t%s\n",__DATE__);
	printf("Time:\t\t%s\n\n",__TIME__);

	for (N=4; N<=8; N=N*2)
	{
		if (N%2==0||N==3)
		{
			skip=1;
			y=make_random_vector(N);
			x=make_vector(N);
			w=make_vector(N);
			C=MakeC(N);

			for (i=0;i<=N;i++)
				w[i]=y[i];
			w[0]=w[0]/2;
			w[N]=w[N]/2;

			CN=MakeCN(N);
			A=make_vector(N);
			then2=(double)clock()/(double)CLOCKS_PER_SEC;
			/*A=mat_vec_mult(CN,w,N);
			A=mat_vec_mult(CN,w,N);
			A=mat_vec_mult(CN,w,N);
			A=mat_vec_mult(CN,w,N);
			A=mat_vec_mult(CN,w,N);
			A=mat_vec_mult(CN,w,N);
			A=mat_vec_mult(CN,w,N);
			A=mat_vec_mult(CN,w,N);
			A=mat_vec_mult(CN,w,N);
			A=mat_vec_mult(CN,w,N);
			A=mat_vec_mult(CN,w,N);
			A=mat_vec_mult(CN,w,N);
			A=mat_vec_mult(CN,w,N);
			A=mat_vec_mult(CN,w,N);
			A=mat_vec_mult(CN,w,N);
			A=mat_vec_mult(CN,w,N);
			A=mat_vec_mult(CN,w,N);
			A=mat_vec_mult(CN,w,N);
			A=mat_vec_mult(CN,w,N);
			A=mat_vec_mult(CN,w,N);
			A=mat_vec_mult(CN,w,N);
			A=mat_vec_mult(CN,w,N);
			A=mat_vec_mult(CN,w,N);
			A=mat_vec_mult(CN,w,N);
			A=mat_vec_mult(CN,w,N);
			A=mat_vec_mult(CN,w,N);
			A=mat_vec_mult(CN,w,N);
			A=mat_vec_mult(CN,w,N);
			A=mat_vec_mult(CN,w,N);
			A=mat_vec_mult(CN,w,N);
			A=mat_vec_mult(CN,w,N);
			A=mat_vec_mult(CN,w,N);
			A=mat_vec_mult(CN,w,N);
			A=mat_vec_mult(CN,w,N);
			A=mat_vec_mult(CN,w,N);
			A=mat_vec_mult(CN,w,N);
			A=mat_vec_mult(CN,w,N);
			A=mat_vec_mult(CN,w,N);
			A=mat_vec_mult(CN,w,N);
			A=mat_vec_mult(CN,w,N);
			A=mat_vec_mult(CN,w,N);
			A=mat_vec_mult(CN,w,N);
			A=mat_vec_mult(CN,w,N);
			A=mat_vec_mult(CN,w,N);
			A=mat_vec_mult(CN,w,N);
			A=mat_vec_mult(CN,w,N);*/
			A=mat_vec_mult(CN,w,N);
			/*A=mat_vec_mult(CN,w,N);
			now2=(double)clock()/(double)CLOCKS_PER_SEC;
			diff2=now2-then2;*/

			then=(double)clock()/(double)CLOCKS_PER_SEC;
			/*FastCosine(x,y,w,C,N,skip);
			FastCosine(x,y,w,C,N,skip);
			FastCosine(x,y,w,C,N,skip);
			FastCosine(x,y,w,C,N,skip);
			FastCosine(x,y,w,C,N,skip);
			FastCosine(x,y,w,C,N,skip);
			FastCosine(x,y,w,C,N,skip);
			FastCosine(x,y,w,C,N,skip);
			FastCosine(x,y,w,C,N,skip);
			FastCosine(x,y,w,C,N,skip);
			FastCosine(x,y,w,C,N,skip);
			FastCosine(x,y,w,C,N,skip);
			FastCosine(x,y,w,C,N,skip);
			FastCosine(x,y,w,C,N,skip);
			FastCosine(x,y,w,C,N,skip);
			FastCosine(x,y,w,C,N,skip);
			FastCosine(x,y,w,C,N,skip);
			FastCosine(x,y,w,C,N,skip);
			FastCosine(x,y,w,C,N,skip);
			FastCosine(x,y,w,C,N,skip);
			FastCosine(x,y,w,C,N,skip);
			FastCosine(x,y,w,C,N,skip);
			FastCosine(x,y,w,C,N,skip);
			FastCosine(x,y,w,C,N,skip);
			FastCosine(x,y,w,C,N,skip);
			FastCosine(x,y,w,C,N,skip);
			FastCosine(x,y,w,C,N,skip);
			FastCosine(x,y,w,C,N,skip);
			FastCosine(x,y,w,C,N,skip);
			FastCosine(x,y,w,C,N,skip);
			FastCosine(x,y,w,C,N,skip);
			FastCosine(x,y,w,C,N,skip);
			FastCosine(x,y,w,C,N,skip);
			FastCosine(x,y,w,C,N,skip);
			FastCosine(x,y,w,C,N,skip);
			FastCosine(x,y,w,C,N,skip);
			FastCosine(x,y,w,C,N,skip);
			FastCosine(x,y,w,C,N,skip);
			FastCosine(x,y,w,C,N,skip);
			FastCosine(x,y,w,C,N,skip);
			FastCosine(x,y,w,C,N,skip);
			FastCosine(x,y,w,C,N,skip);
			FastCosine(x,y,w,C,N,skip);
			FastCosine(x,y,w,C,N,skip);
			FastCosine(x,y,w,C,N,skip);
			FastCosine(x,y,w,C,N,skip);
			FastCosine(x,y,w,C,N,skip);*/
			FastCosine(x,y,w,C,N,skip);
			now=(double)clock()/(double)CLOCKS_PER_SEC;
			diff=now-then;

			printf("N=%d\n",N);
			print_vector(x,N);
			print_vector(A,N);
			printf("%g\n",norm(vec_sub(A,x,N),N));
			printf("%g\n",diff);
			printf("\n");

			free_vector(C);free_vector(x);
			free_vector(y);free_vector(w);
			free_matrix(CN);
		}
	}

	return(0);
}