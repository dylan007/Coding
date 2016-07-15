#include<stdio.h>
#include<stdlib.h>

int cmpfunc(const void *a,const void *b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int t=0,n,i,c=1,min,minc;
		scanf("%d",&n);
		int a[n];
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		qsort(a,n,sizeof(int),cmpfunc);
		t = min = a[0];	
		minc = 1;
		for(i=1;i<n;i++)
		{
			if(t!=a[i])
			{
				if(minc<c)
				{
					min = t;
					minc = c;
				}	
				t = a[i];
				c = 1;
			}
			else
				c++;
		}
		if(minc<c)
		{
			minc = c;
			min = t;
		}
		printf("%d %d\n",min,minc);
	}
	return 0;
}
