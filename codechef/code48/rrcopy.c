#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int cmpfunc(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int i,n;
		scanf("%d",&n);
		int a[n];
		for(i=0;i<n;i++)	scanf("%d",&a[i]);
		qsort(a,n,sizeof(int),cmpfunc);
		int t=0,c=0;
		for(i=0;i<n;i++)
		{
			if(t!=a[i])
			{
				t = a[i];
				c++;
			}
		}
		printf("%d\n",c);
	}
	return 0;
}
