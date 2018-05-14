#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int cmpfunc(const void *a,const void *b)
{
	return *(float *)a - *(float *)b;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		float x,y,r,R,d;
		int n,i;
		scanf("%f %f %d",&r,&R,&n);
		float a[n];
		for(i=0;i<n;i++)
		{
			scanf("%f %f",&x,&y);
			d = sqrt((x*x)+(y*y));
			x = R-d;
			y = d-r;
			a[i] = (x>y)?x:y;
		}
		qsort(a,n,sizeof(float),cmpfunc);
		printf("%.3f\n",a[n-1]);
	}	
	return 0;
}
