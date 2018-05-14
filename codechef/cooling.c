#include<stdio.h>
#include<stdlib.h>

int cmpfunc(const void *a,const void *b) {return *(int *)a - *(int *)b;}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,i;
		scanf("%d",&n);
		int a[n],b[n],c=0;
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		for(i=0;i<n;i++) scanf("%d",&b[i]);
		qsort(a,n,sizeof(int),cmpfunc);
		qsort(b,n,sizeof(int),cmpfunc);
		int j=0,top=0;
		for(i=0;i<n;i++)
		{
			for(j=top;j<n;j++)
			{
				if(a[i] <= b[j])
				{
					top = j+1;
					c++;
					break;
				}
			}
		}
		printf("%d\n",c);
	}
	return 0;
}
