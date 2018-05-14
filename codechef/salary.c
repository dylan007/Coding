#include<stdio.h>
#include<stdlib.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int i,N,x,sum=0;
		int min = 10000;
		scanf("%d",&N);
		i=N;
		while(i--)
		{
			scanf("%d",&x);
			min = min>x?x:min;
			sum += x;
		}
		printf("%d\n",sum-N*min);
	}
}
