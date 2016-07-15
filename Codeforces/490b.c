#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>

typedef struct
{
	int front,back;
}fun;

int main()
{
	int n;
	scanf("%d",&n);
	fun arr[n];
	int i;
	int ans[n];
	memset(ans,0,4*n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&arr[i].front,&arr[i].back);
		if(arr[i].front == 0)
			ans[1]=arr[i].back;
		if(arr[i].back == 0)
			ans[n-2]=arr[i].front;
	}
	int temp=ans[1],j;
	for(i=3;i<n;i+=2)
	{
		for(j=0;j<n;j++)
		{
			if(arr[j].front == temp)
				break;
		}
		ans[i]=arr[j].back;
		temp = arr[j].back;
	}
	if(n%2 == 0)
	{
		temp = ans[n-2];
		for(i=(n-1-!(n%2)*3);i>=2;i-=2)
		{
			for(j=0;j<n;j++)
			{
				if(arr[j].front == temp)
					break;
			}
			ans[i]=arr[j].back;
			temp = arr[j].back;
		}
	}
	else
	{
		temp = ans[1];
		for(i=2;i<n;i+=2)
		{
			for(j=0;j<n;j++)
			{
				if(arr[j].front==temp)
					break;
			}
			temp = arr[j].back;
			for(j=0;j<n;j++)
			{
				
			}
		}
	}
	for(i=0;i<n;i++)
		printf("%d ",ans[i]);
	printf("\n");
	return 0;
}
