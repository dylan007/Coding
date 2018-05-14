#include<stdio.h>
#include<stdlib.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,x,min1,min2;
		scanf("%d %d",&a,&b);
		scanf("%d",&min1);
		a--;
		while(a--)
		{
			scanf("%d",&x);
			min1 = min1<x?min1:x;
		}
		scanf("%d",&min2);
		b--;
		while(b--)
		{
			scanf("%d",&x);
			min2 = min2<x?min2:x;
		}
		if(min1<min2)
			printf("MechaGodzilla\n");
		else if(min1>=min2)
			printf("Godzilla\n");
		else
			printf("uncertain\n");
	}
	return 0;
}
