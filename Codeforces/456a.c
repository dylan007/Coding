#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int n;
	scanf("%d",&n);
	int f=0;
	int x,y;
	while(n--)
	{
		scanf("%d %d",&x,&y);
		if(x!=y)
			f=1;
	}
	if(f==1)
		printf("Happy Alex\n");
	else
		printf("Poor Alex\n");
}
