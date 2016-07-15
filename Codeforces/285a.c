#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,k,i,t;
	scanf("%d %d",&n,&k);
	int a[n];
	for(i=0;i<n;i++)
		a[i] = i+1;
	if(k<n)
	{
		for(i=n;i>(n-k);i--)
			printf("%d ",i);
		for(i=1;i<=(n-k);i++)
			printf("%d ",i);
		printf("\n");
	}
	/*if(k==0)
	{
		for(i=0;i<n;i++)
			printf("%d ",a[i]);
		printf("\n");
	}
	else if(k==(n-1))
	{
		for(i=(n-1);i>=0;i--)
			printf("%d ",a[i]);
		printf("\n");
	}
	else if(n/2 >= k)
	{
		for(i=0;i<(n-1);i+=2)
		{
			t = a[i];
			a[i] = a[i+1];
			a[i+1] = t;
			k--;
			if(k==0)
				break;
		}
		for(i=0;i<n;i++)
			printf("%d ",a[i]);
		printf("\n");
	}*/
	else 
		printf("-1\n");
	return 0;
}
