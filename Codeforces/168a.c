#include<stdio.h>
#include<stdlib.h>

int main()
{
	float n,x,y;
	scanf("%f%f%f",&n,&x,&y);
	y = y/100;
	n *= y;
	if( n > (int)(n))
		n = (int)(n) + 1;
	if(x >= n)
		printf("0\n");
	else
		printf("%d\n",(int)(n-x));
	return 0;
}
