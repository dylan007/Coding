#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,i,count=0,j;
       	scanf("%d",&n);
	int a[n],b[n];
	for(i=0;i<n;i++)
		scanf("%d %d",&a[i],&b[i]);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i]==b[j])
				count++;
		}
	}
	printf("%d\n",count);
	return 0;
}
