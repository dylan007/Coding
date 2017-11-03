#include <stdio.h>
#include <stdlib.h>

int toh(int n)
{
	if(n==1)
		return 1;
	return 3+toh(n-1);	
}

int main()
{
	int n;
	scanf("%d",&n);
	int x;
	x = toh(n);
	printf("%d\n",x);
	return 0;
}
