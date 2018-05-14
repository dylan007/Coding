//CODECHEF PROBLEM CODE:ORDERS
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int t,i,n;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d",&n);
		int k,j,a[n],b[n],count;
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[j]);
			b[j]=j+1;
		}
		//for(j=0;j<n;j++)
		// printf("%d ",a[j]);
		//printf("\n");
		//for(j=0;j<n;j++)
		// printf("%d ",b[j]);
		//printf("\n");
		for(j=1;j<n;j++)
		{
			k=a[j];
			for(count=1;count<=k;count++)
				b[j-count]++;
			b[j]-=k;
		}
		for(j=0;j<n;j++)
			printf("%d ",b[j]);
		printf("\n");
	}
	return 0;
}
