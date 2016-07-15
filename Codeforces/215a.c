#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i,n,m,max=0;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&m);
	int b[m],j,t;
	for(i=0;i<m;i++)
	{
		scanf("%d",&b[i]);
		for(j=0;j<n;j++)
		{
			t = b[i]/a[j];
			if((b[i] - a[j]*t)==0)
				max = max>t?max:t;
		}
	}
	int c=0;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			t = b[i]/a[j];
			if((b[i] - t*a[j]) == 0)
				c += (max == t);
		}
	}
	printf("%d\n",c);
	return 0;
}
