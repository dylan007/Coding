#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct
{
	int x,y;
}point;

int check(point a,point b)
{
	if(a.x==b.x && b.y!=a.y)
		return 1;
	else if(a.x!=b.x && a.y==b.y)
		return 2;
	else if((b.x-a.x)==(b.y-a.y))
		return 3;
	else if((b.x-a.x)+(b.y-a.y) == 0)
		return 4;
	return 0;
}

int main()
{
	point p1,p2;
	scanf("%d %d %d %d",&p1.x,&p1.y,&p2.x,&p2.y);
	if(check(p1,p2)==0)
		printf("-1\n");
	else
	{
		if(check(p1,p2)==1)
			printf("%d %d %d %d\n",p1.x+(p2.y-p1.y),p1.y,p2.x+(p2.y-p1.y),p2.y);
		else if(check(p1,p2)==2)
			printf("%d %d %d %d\n",p1.x,p1.y+(p2.x-p1.x),p2.x,p2.y+(p2.x-p1.x));
		else if(check(p1,p2)==3)
			printf("%d %d %d %d\n",p1.x+(p2.x-p1.x),p1.y,p1.x,p1.y+(p2.x-p1.x));
		else if(check(p1,p2)==4)
			printf("%d %d %d %d\n",p1.x+(p2.x-p1.x),p1.y,p1.x,p1.y-(p2.x-p1.x));
	}
}
