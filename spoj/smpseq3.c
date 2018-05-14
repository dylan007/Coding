#include<stdio.h>
#include<stdlib.h>

int search(int x,int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i] == x)
			return 1;
		else if(a[i] > x)
			return 0;
	}
	return 0;
}

int main()
{
	int n,m,i;
	scanf("%d",&n);
	int s[n];
	for(i=0;i<n;i++)
		scanf("%d",&s[i]);
	scanf("%d",&m);
	int q[m];
	for(i=0;i<n;i++)
		scanf("%d",&q[i]);
	
	for(i=0;i<n;i++)
	{
		if(search(s[i],q,n) == 0)
			printf("%d ",s[i]);
	}
	printf("\n");
	return 0;
}
