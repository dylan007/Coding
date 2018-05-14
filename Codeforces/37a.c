#include<stdio.h>
#include<stdlib.h>

int cmpfunc(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
	int n,i,max=1,count=1,j,ansmax=0,flag=0;
	scanf("%d",&n);
	if(n == 1)
	{
		printf("1 1\n");
		return 0;
	}
	int length[n];
       	for(i=0;i<n;i++)
		scanf("%d",&length[i]);
	qsort(length,n,sizeof(int),cmpfunc);
	for(i=1;i<n;i++)
	{
		j = i;
		flag=0;
		while(length[j] == length[j-1])
		{
			max++;	
			j++;
			flag=1;
		}
		if(flag)
			i = j-1;
		if(!flag)
		{
			count++;
			//printf("i=%d\n",i);
			max=1;
		}
		ansmax = ansmax>max?ansmax:max;	
	}
	printf("%d %d\n",ansmax,count);
	return 0;
}
