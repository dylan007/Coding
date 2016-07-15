#include<stdio.h>
#include<stdlib.h>

int main()
{
	int count=0,n,i,sum=0,x;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		sum += x;
	}
	n = n+1;
	if( (sum+1) % n != 1)
		count++;
	if( (sum+2) % n != 1)
		count++;
	if( (sum+3) % n != 1)
		count++;
	if( (sum+4) % n != 1)
		count++;
	if( (sum+5) % n != 1)
		count++;
	printf("%d\n",count);
	return 0;
}
