#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int x,y;
}drag;

int cmpfunc(const void *a,const void  *b)
{
	const drag *elem1 = a;
	const drag *elem2 = b;
	return elem1->x - elem2->x ;
}

int main()
{
	int s,n,i,j,t;
	scanf("%d %d",&s,&n);
	int X,Y;
	drag a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&X,&Y);
		a[i].x = X;
		a[i].y = Y;
	}
	qsort(a,n,sizeof(drag),cmpfunc);
	for(i=0;i<n;i++)
	{
		if(s <= a[i].x)
		{
			printf("NO\n");
			return 0;
		}
		s += a[i].y;
	}
	printf("YES\n");
	return 0;
}
