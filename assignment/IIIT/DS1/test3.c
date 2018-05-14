#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		int x,min=0;
		int count=0;
		int i;
		scanf("%d",&x);
		n--;
		min = x;
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			if(x>=min)
				count++;
			else
				min = x;
		}
		printf("%d\n",count);
	}
	return 0;
}
