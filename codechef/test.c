#include<stdio.h>
#include<stdlib.h>

int memo[1000]; 

int fib(int n)
{
	if(n==0||n==1)
		memo[n] = n;
	if(memo[n] == -1)
		memo[n] = fib(n-1)+fib(n-2);
	return memo[n];
}

int main()
{
	int i;
	for(i=0;i<100;i++) memo[i] = -1;
	while(!feof(stdin))
	{
		int n;
		scanf("%d",&n);
		printf("%d\n",fib(n));
	}
	return 0;
}
