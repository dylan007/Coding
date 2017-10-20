#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100 //Maximum degree possible 
#define max(a,b) (a>b?a:b)

typedef struct pol{
	int coeff[MAX][MAX];//coeff[i][j] = coefficient of x^i * y*j
	int deg;//Degree of the polynomial
}pol;

void init(pol *a)
{
	int i,j;
	for(i=0;i<MAX;i++)
	{
		for(j=0;j<MAX;j++)
			a->coeff[i][j] = 0;
	}
	return;
}

void read(pol *a)
{
	//printf("Entering input\n");
	//printf("Enter the degree of the polynomial\n");
	scanf("%d",&(a->deg));
	//printf("%d ",a->deg);
	//printf("Enter the number of terms\n");
	int n;
	scanf("%d",&n);
	//printf("%d\n",n);
	//printf("Enter the coefficients in the following manner:\n");
	//printf("Coefficient\texponent of x\texponent of y:\n");
	int c,i,j;
	while(n--)
	{
	 	scanf("%d %d %d",&c,&i,&j);
	 	a->coeff[i][j] = c;
    } 
}

void display(pol *x)	
{
	printf("%d\n",x->deg);
	int i,j;
	for(i=0;i<=x->deg;i++)
	{
		for(j=0;j<=x->deg;j++)
			printf("%d ",x->coeff[i][j]);
		printf("\n");
	}
	return;
}

void add(pol *s,pol *a,pol *b)
{
	int i,j;
	s->deg = max(a->deg,b->deg);
	for(i=0;i<=s->deg;i++)
	{
		for(j=0;j<=s->deg;j++)
			s->coeff[i][j] = a->coeff[i][j] + b->coeff[i][j];
	}
	return;
}

int main()
{
	//printf("Hi!\n");
	pol a,b,x;
	printf("Starting Initialisation\n");
	init(&a);
	init(&b);
	printf("Initialising ...\n");	
	read(&a);
	display(&a);
	read(&b);
	display(&b);
	printf("Adding both polynomials...\n");
	//printf("%d\n",c.deg);
	init(&x);
	add(&x,&a,&b);
	display(&x);
	return 0;
}