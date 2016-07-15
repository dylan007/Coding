#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	int T;
	scanf("%d",&T);
	int n,r,l;
	while(T--)
	{
		scanf("%d %d %d",&n,&l,&r);
		int k1,k2;
		k1 = n/l;
		k2 = n/r;
		if(k1>k2 || k2*r==n || k1*l==n)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
