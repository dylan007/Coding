#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void printd(int n)
{
	if(n<0)
	{
		printf("-");
		n = 0-n;
	}
	if((n/10))
	{
		printd(n/10);
		putchar('0'+n%10);
	}
	else
		putchar('0'+n%10);
}

int main()
{
	int n;
	scanf("%d",&n);
	printd(n);
	printf("\n");
	return 0;
}
