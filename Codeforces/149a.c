#include<stdio.h>
#include<stdlib.h>

int cmpfunc(const void *a,const void *b)
{
	return *(int *)b - *(int *)a;
}

int main()
{
	int k,i;
	int g[12],count=0;
	scanf("%d",&k);
	if(!k)
	{
		printf("0\n");
		return 0;
	}
	for(i=0;i<12;i++)
		scanf("%d",&g[i]);
	qsort(g,12,sizeof(int),cmpfunc);
	i=0;
	while((k>0)&&(i<12))
	{
		count++;
		k -= g[i];
		i++;
	}
	if(k>0)
		printf("-1\n");
	else
		printf("%d\n",count);
	return 0;
}
