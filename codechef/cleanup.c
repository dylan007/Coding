#include<stdio.h>
#include<stdlib.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m,i,x;
		scanf("%d %d",&n,&m);
		int a[1000] = {0};
		for(i=0;i<m;i++)
		{
			scanf("%d",&x);
			a[x-1] = 1;
		}
		int b[n-m],j=0;
		for(i=0;i<n;i++)
		{
			if(a[i] == 0)
			{
				b[j] = i+1;
				j++;
			}
		}
		for(i=0;i<(n-m);i+=2)
			printf("%d ",b[i]);
		printf("\n");
		for(i=1;i<(n-m);i+=2)
			printf("%d ",b[i]);
		printf("\n");
	}
	return 0;
}
