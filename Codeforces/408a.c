#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int main()
{
	int n;
	scanf("%d",&n);
	int max=INT_MAX;
	int temp=0;
	int a[n];
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	int j=0,x;
	for(i=0;i<n;i++)
	{
		temp=0;
		for(j=0;j<a[i];j++)
		{
			scanf("%d",&x);
			temp+=x*5;
		}
		temp+=15*a[i];
		max = max<temp?max:temp;
	}
	printf("%d\n",max);
	return 0;
}
