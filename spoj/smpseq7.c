#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,i,flag=0,ans=0;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	if(n == 2)
	{
		printf("Yes\n");
		return 0;
	}
	flag = (a[0]>a[1]);

	for(i=1;i<n;i++)
	{
		if(flag == 1)
		{
			if(a[i]>a[i-1])
			{
				flag = 0;

				break;
			}
		}
		else if(flag == 0)
		{
			if(a[i]<a[i-1])
			{
				flag = 1;

				break;
			}
		}
	}

	ans = 1;
	for(;i<n;i++)
	{

		if(flag)
		{
			if(a[i]>a[i-1])
			{
				ans = 0;
				break;
			}
		}
		else
		{
			if(a[i]<a[i-1])
			{
				ans = 0;
				break;
			}
		}
	}
	if(ans)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}
