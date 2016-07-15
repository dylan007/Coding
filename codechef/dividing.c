#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i,N,sum=0,x;
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		scanf("%d",&x);
		sum += x;
	}
	if(sum == ((N*(N+1))/2))
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
