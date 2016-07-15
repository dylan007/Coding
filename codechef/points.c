#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct
{
	int x,y;
}point;

int cmpfunc(const void *a,const void *b)
{
	return *(int *)a - *(int *)b;
}

int count(point a[],int x1,int n)
{
	int i,c=0;
	for(i=0;i<n;i++)
	{
		c += (a[i].x == x1);
		if(a[i].x>x1) return c;
	}
	return c;
}

float dist(point a,point b)
{
	return sqrt(((a.x-b.x)*(a.x-b.x))+((a.y-b.y)*(a.y-b.y)));
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int currx,cuc=1,q,j,n,i,start,minx=10001,maxy=0;
		scanf("%d",&n);
		float d;
		point a[n],temp;
		for(i=0;i<n;i++) scanf("%d %d",&a[i].x,&a[i].y);
		for(i=0;i<n;i++) minx = (minx>a[i].x)?minx:a[i].x;
		qsort(a,n,sizeof(point),cmpfunc);
		currx = a[0].x;
		for(i=0;i<n;i++)
		{
			
			if(count(a,a[i].x,n)>1)
			{
				cuc = count(a,a[i].x,n);	
				for(j=i;j<(i+cuc-1);j++)
				{
					start = j;	
					for(q=j+1;q<(i+cuc);q++)
					{
						if(a[start].y < a[q].y)
							start = q;
					}
					int swap;
					if(start != j)
					{
						swap = a[j].y;
						a[j].y = a[start].y;
						a[start].y = swap;
					}
				}	
			}	
		}
		for(i=0;i<n;i++) printf("%d %d\n",a[i].x,a[i].y);
		temp = a[0];
		for(i=1;i<n;i++)
			d += dist(a[i],temp);
		printf("%.2f\n",d);
	}
	return 0;
}
