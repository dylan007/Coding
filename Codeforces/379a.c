#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a,b,sum=0,leftover=0;
	scanf("%d%d",&a,&b);
	while(a)
	{
		a = a-1;
		leftover++;
		sum++;
		a = a + leftover/b;
		leftover = leftover%b;
	}
	printf("%d\n",sum);
	return 0;
}
