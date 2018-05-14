#include<stdio.h>
#include<stdlib.h>

int cmpfunc(const void *a, const void *b)
{
	return *(int *)b - *(int *)a;
}

int main()
{
	int n,k,i,count=0,zindex;
	scanf("%d %d", &n,&k);
	int arr[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	qsort(arr,n,sizeof(int),cmpfunc);
	if(arr[0] <= 0){
		printf("0\n");
		return 0;
	}
	else if(arr[(k-1)] <= 0)
	{
		for(i=(k-1);i>=0;i--)
		{
			if(arr[i]>0)
			{
				zindex = i;
				break;
			}
		}
		printf("%d\n",(zindex+1));
		return 0;
	}
	else
	{
		count = k;
		for(i=(k);i<n;i++)
		{
			if(arr[k-1]!=arr[i])
				break;
			count++;
		}
		printf("%d\n",count);
		return 0;
	}
	/*for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");*/
	return 0;
}
