#include<stdio.h>
#include<stdlib.h>
int main()
{
	int x,c;
	float y;
	scanf("%d%f",&x,&y);
	c=x%5;
	if((c==0)&&((0.5)<(y-x)))
		printf("%.2f\n",(y-x-0.5));
	else
		printf("%.2f\n",y);
	return 0;
}
