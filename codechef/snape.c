#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int b,l;
		scanf("%d %d",&b,&l);
		float r1,r2;
		r1 = sqrt(l*l - b*b);
		r2 = sqrt(l*l + b*b);
		printf("%f %f\n",r1,r2);
	}
	return 0;
}
