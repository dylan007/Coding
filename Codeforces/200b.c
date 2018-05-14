#include<stdio.h>
#include<stdlib.h>

int main()
{
	double n,i,x,sum=0;
	scanf("%lf",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lf",&x);
		sum += x;
	}
	printf("%.12lf\n",((sum/(n*100))*100));
	return 0;
}
