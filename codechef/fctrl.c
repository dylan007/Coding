#include<stdio.h>
#include<stdlib.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,c=0;
		scanf("%d",&n);
		n /=5;
		while(n!=0)
		{
			c+= n;
			n /= 5;
		}
		printf("%d\n",c);
	}
	return 0;
}
