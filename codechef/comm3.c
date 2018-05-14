#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct point
{
	int x,y;
}point;

float distance(point a,point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

int main()
{
	int T,flag=0;
	scanf("%d",&T);
	while(T--)
	{
		flag=0;
		point a,b,c;
		float R,ab,ac,bc;
		scanf("%f %d %d %d %d %d %d",&R,&a.x,&a.y,&b.x,&b.y,&c.x,&c.y);
		ab = distance(a,b);
		ac = distance(a,c);
		bc = distance(b,c);

		if((ab<=R)&&(ac<=R)&&(bc<=R))
			printf("yes\n");
		else
		{
			if(ab>R)
			{
				if(!( ac<=R && bc<=R))
				{
					printf("no\n");
					continue;
				}
			}	
			if(ac>R)
			{
				if(!( ab<=R && bc<=R))
				{
					printf("no\n");
					continue;
				}
			}
			if(bc>R)
			{
				if(!(ab<=R && ac<=R))	
				{
					printf("no\n");
					continue;
				}
			}
			printf("yes\n");
		}
	}
	return 0;
}
