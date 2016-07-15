#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct
{
	int x,y;
}point;

int main()
{
	int T,C=0,t,r1,r2,r3;
	scanf("%d",&T);
	while(T--)
	{
		point a,b,c;
		scanf("%d %d %d %d %d %d",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y);
		r1 = (a.x - b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
		r2 = (c.x - b.x)*(c.x-b.x) + (c.y-b.y)*(c.y-b.y);
		r3 = (a.x - c.x)*(a.x-c.x) + (a.y-c.y)*(a.y-c.y);
		C += ((r1 == r2+r3)||(r2 == r1+r3)||(r3 == r1+r2));
	}
	printf("%d\n",C);
	return 0;
}
