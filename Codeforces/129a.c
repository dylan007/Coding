#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,i,even=0,odd=0,x,sum=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		sum += x;
		if(x%2 == 0)
			even++;
		else
			odd++;
	}
	if(sum%2 == 0)
		printf("%d\n",even);
	else
		printf("%d\n",odd);
	return 0;
}
