#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,i;
	scanf("%d",&n);
	int x,y,a=0,b=0;
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&x,&y);
		a += x;
		b += y;
	}
	printf("%d %d\n",a,b);	
	return 0;
}
