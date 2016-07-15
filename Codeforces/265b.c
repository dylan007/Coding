#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,i,x,t=0,h=0,nut=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		if(i == 0)
		{
			t += x+1;
			h = x;
			//printf("%d 0\n",t);
		}
		else
		{
			t += 2+ abs(x-h);		
			h = x;
		}
	}
	printf("%d\n",t);
	return 0;
}
