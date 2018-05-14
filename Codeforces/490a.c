#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>

int main()
{
	int n;
	scanf("%d",&n);
	int a[n],check[n];
	memset(check,0,4*n);
	int i,c1=0,c2=0,c3=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		c1 += (a[i]==1);
		c2 += (a[i]==2);
		c3 += (a[i]==3);
	}
	int min=INT_MAX;
	min = min>c1?c1:min;
	min = min>c2?c2:min;
	min = min>c3?c3:min;
	printf("%d\n",min);
	int j=0;
	for(i=0;i<min;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[j]==1 && check[j]==0)
			{
				check[j]=1;
				printf("%d ",j+1);
				break;
			}
		}
		for(j=0;j<n;j++)
		{
			if(a[j]==2 && check[j]==0)
			{
				check[j]=1;
				printf("%d ",j+1);
				break;
			}
		}
		for(j=0;j<n;j++)
		{
			if(a[j]==3 && check[j]==0)
			{
				check[j]=1;
				printf("%d\n",j+1);
				break;
			}
		}
	}
	return 0;
}
