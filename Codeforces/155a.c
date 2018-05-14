#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,i,count=0,min,max=0;
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	min = arr[0];
	max = arr[0];
	for(i=0;i<(n-1);i++)
	{
		if(max < arr[i])
		{
			max = arr[i];
			count++;
//			printf("max = %d\n",max);
		}
		else if(min>arr[i])
		{
			min = arr[i];
			count++;
//			printf("min = %d\n",min);
		}
	}
	if((min>arr[n-1])||(max<arr[n-1]))
		count++;
	printf("%d\n",count);
	return 0;
}
