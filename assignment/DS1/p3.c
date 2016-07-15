#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		int max=0,MAX=0;
		int i,x,y;
		n--;
		scanf("%d",&y);
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			MAX = MAX+(x-y);
			if(MAX<0)
				MAX=0;
			else if(max < MAX)
				max = MAX;
			y=x;
		}
		printf("%d\n",max);
	}	
	return 0;
}
