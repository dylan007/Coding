#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i,n,v,k,j;
	scanf("%d %d",&n,&v);
	int x,min=1000000,c=0;
	int flag[50] = {0};
	for(i=0;i<n;i++)
	{
		min = 1000000;
		scanf("%d",&k);
		for(j=0;j<k;j++)
		{
			scanf("%d",&x);
			min = min<x?min:x;
		}

		if(v>min) flag[i]=1;
		c += flag[i];

	}
	printf("%d\n",c);
	for(i=0;i<n;i++)
	{
		if(flag[i])
			printf("%d ",i+1);
	}
	printf("\n");
	return 0;
}
