#include<stdio.h>
#include<stdlib.h>

int main()
{
	int max=0,n,i,x,count=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		count -= x;
		max = max>count?max:count;

		scanf("%d",&x);
		count += x;
		max = max>count?max:count;
	}
	printf("%d\n",max);
	return 0;
}
