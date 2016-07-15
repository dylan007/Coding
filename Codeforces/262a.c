#include<stdio.h>
#include<stdlib.h>

int check(int x,int y)
{
	int c=0;
	while(x>0)
	{
		if((x%10 == 7)||(x%10 == 4))
			c++;
		x = x/10;
		if(c>y)
			return 1;	
	}
	return 0;
}

int main()
{
	int i,n,k;
	scanf("%d %d",&n,&k);
	int num[n],count=0;
	for(i=0;i<n;i++)
		scanf("%d",&num[i]);
	for(i=0;i<n;i++)
	{
		if(check(num[i],k) == 0)
			count++;
	}
	printf("%d\n",count);
	return 0;
}
