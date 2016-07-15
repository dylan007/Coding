#include<stdio.h>
#include<stdlib.h>

int good(int x,int k)
{
	int i,flag[10] = {0};
	while(x > 0)
	{
		flag[x%10] = 1;
		x /= 10;
	}
	int a=0;
	for(i=0;i<=k;i++)
		a += flag[i];
	if(a == k+1)
		return 1;
	else
		return 0;
}

int main()
{
	int c=0,i,n,k,x;
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		c += good(x,k);
	}	
	printf("%d\n",c);
	return 0;
}
