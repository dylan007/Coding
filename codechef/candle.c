#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a[10],i,min=100000,x;	
		for(i=0;i<10;i++)
		{
			scanf("%d",&a[i]);
			a[i] += (i==0);
			if(a[i]<min)
			{
				min = a[i];
				x = i;
			}
		}
		if(x != 0) for(i=0;i<=min;i++) printf("%d",x);
		else
		{
			x = pow(10,min);
			printf("%d",x);
		}
		printf("\n");
	}
	return 0;
}
