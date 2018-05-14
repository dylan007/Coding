#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int cmpfunc(const void *a,const void *b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
	int n,m;
	scanf("%d",&n);
	int i,boys[n];
	for(i=0;i<n;i++)
		scanf("%d",&boys[i]);
	scanf("%d",&m);
	int girls[m];
	for(i=0;i<m;i++)
		scanf("%d",&girls[i]);
	qsort(boys,n,sizeof(int),cmpfunc);
	qsort(girls,m,sizeof(int),cmpfunc);
	int j,count=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(abs(boys[i]-girls[j]) <= 1)
			{
				//printf("%d %d\n",i,j);
				girls[j]=10000;
				count++;
				break;
			}
		}
	}
	printf("%d\n",count);
	return 0;
}
