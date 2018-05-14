#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int x;
		scanf("%lld",&x);
		int count=1;
		while(x>0)
		{
			if(x%2 == 0)
				x/=2;
			else 
				x-=1;
			count++;
		}
		if(count%2 == 1)
			printf("Akash\n");
		else
			printf("Aayush\n");
	}
	return 0;
}
