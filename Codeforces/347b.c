#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,i;
	scanf("%d",&n);
	int a[n];
	int c=0;
	for(i=0;i<n;i++)	
	{
		scanf("%d",&a[i]);
		if(a[i] == i)
			c++;
	}
	for(i=0;i<n;i++)
	{
		if(a[i] == i)
			continue;
		if(a[a[i]] == i)
		{
	
			printf("%d\n",c+2);
			return 0;
		}
	}
	printf("%d\n", c+1<=n ? c+1:c);
	return 0;
}
