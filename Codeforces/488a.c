#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int check(int x)
{
	if(x<0)
		x=0-x;
	while(x>0)
	{
		if(x%10 == 8)
			return 1;
		x = x/10;
	}
	return 0;
}

int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;;i++)
	{
		if(check(i+n)==1)
		{
			printf("%d\n",i);
			return 0;
		}
	}
	return 0;
}
