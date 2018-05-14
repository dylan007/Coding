#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>

int cmpfunc(const void *a,const void *b)
{
	return *(int *)a - *(int *)b;
}
	
int main()
{
	int n,a,b;
	scanf("%d %d %d",&n,&a,&b);
	int A[a],B[b];
	int i;
	for(i=0;i<a;i++)
		scanf("%d",&A[i]);
	for(i=0;i<b;i++)
		scanf("%d",&B[i]);
	qsort(A,a,sizeof(int),cmpfunc);
	qsort(B,b,sizeof(int),cmpfunc);
	int j;
	for(i=1;i<=n;i++)
	{
		int f=0;
		for(j=0;j<a;j++)
		{
			if(A[j]==i)
			{
				f=1;
				break;
			}
		}
		if(f==0)
		{
			for(j=0;j<b;j++)
			{
				if(B[j]==i)
				{
					f=2;
					break;
				}
			}
		}
		printf("%d ",f);
	}
	printf("\n");
	return 0;
}
