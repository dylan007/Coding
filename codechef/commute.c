#include<stdio.h>
#include<stdlib.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,time=0,start,travel,interval;
		scanf("%d",&n);
		scanf("%d %d %d",&start,&travel,&interval);
		if(time < start)
			time = start;
		time += travel;
		n--;
		while(n--)
		{

			scanf("%d %d %d",&start,&travel,&interval);
			if(start>time)
				time = start+travel;
			else if((start-time)%interval == 0)
				time += travel;
			else
				time = start + ((time-start)/interval + 1)*interval + travel;
		}
		printf("%d\n",time);
	}
}
