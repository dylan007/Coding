#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,min;
	scanf("%d",&n);
	int d[n],i,f=0,z;
	for(i=0;i<n;i++)
	{
		scanf("%d",&d[i]);
		if(i == 0) min = d[0];

		min = min>d[i] ? d[i]:min;
	}
	for(i=0;i<n;i++)
	{
		if(min == d[i])
		{
			if(f == 0)
			{
				f = 1;
				z = i;
			}
			else
			{
				printf("Still Rozdil\n");
				return 0;
			}
		}
	}
	printf("%d\n",z+1);
	return 0;
}
