#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,x,i,t,sum=0;
	scanf("%d %d",&n,&x);
	for(i=0;i<n;i++)
	{
		scanf("%d",&t);
		sum += t;
	}
	sum = sum<0? -sum:sum;
	if(sum % x != 0)
		printf("%d\n",(sum/x)+1);
	else
		printf("%d\n",(sum/x));
	return 0;
}
