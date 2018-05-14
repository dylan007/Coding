#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int cmpfunc(const void *a,const void *b)
{
	return *(int *)b - *(int *)a;
}

int main()
{
	int T,I;
	scanf("%d",&T);
	for(I=0;I<T;I++)
	{
		int x,n;
		scanf("%d %d",&x,&n);
		int a[n],i,sum=0;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		qsort(a,n,sizeof(int),cmpfunc);
		for(i=0;i<n;i++)
		{
			sum += a[i];
			if(sum>=x)
				break;
		}
		if(sum>=x)
			printf("Scenario #%d:\n%d\n\n",I+1,i+1);
		else
			printf("Scenario #%d:\nimpossible\n\n",I+1);
	}
	return 0;
}
