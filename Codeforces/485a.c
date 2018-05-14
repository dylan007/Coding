#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int check(int a)
{
	while(a>1)
	{
		if(a%2 != 0)
			return 0;
		a = a/2;
	}
	return 1;
}

int main()
{
	int x,a,m;
	scanf("%d %d",&a,&m);
	int i;
	while(m%2 == 0)
		m/=2;
	if(a%m==0)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}
