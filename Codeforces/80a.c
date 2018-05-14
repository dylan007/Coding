#include<stdio.h>
#include<stdlib.h>

int prime(int t)
{
	int i;
	if(t == 1 || t == 2 || t == 3)
		return 1;
	i=2;
	for(i=2;i<=(t/2);i++)
	{
		if(t%i == 0)
			return 0;
	}
	return 1;
}

int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	int i = a+1;
	while(1)
	{
		if(prime(i))
			break;
		else
			i++;
	}

	if(i == b)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
