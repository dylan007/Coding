#include<stdio.h>
#include<stdlib.h>

int cmpfunc(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
	int n,i,count=0;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	qsort(a,n,sizeof(int),cmpfunc);
	if(a[n-1] == 0)
	{
		printf("0\n");
		return 0;
	}
	for(i=0;i<n;i++)
	{
		if((a[i]==a[i+1])&&(a[i]==a[i+2])&&(a[i]!=0))
		{
			printf("-1\n");
			return 0;
		}
		else
		{
			if((a[i]==a[i+1])&&(a[i]!=a[i+2])&&(a[i]!=0))
			{
				count++;
				i += 1;
			}
		}
	}
	printf("%d\n",count);
	return 0;
}
