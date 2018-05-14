#include<stdio.h>
#include<stdlib.h>

int gcdof(int u,int v)
{
	return (v!=0)?gcdof(v,u%v):u;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		int nums[n],i,r,gcd;
		scanf("%d",&nums[0]);
		gcd = nums[0];
		for(i=1;i<n;i++)
		{	
			scanf("%d",&nums[i]);
			gcd = gcdof(gcd,nums[i]);
		}
		for(i=0;i<n;i++) printf("%d ",nums[i]/gcd);
		printf("\n");
	}
	return 0;
}
