#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,i,even=-1,odd=-1;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
		if(a[i]%2 == 0)
		{	
			if(even == -1)
				even = i;
			else
			{
				if(odd != -1)
				{
					printf("%d\n",odd+1);
					return 0;
				}
			}
			//printf("%d %d\n",even,odd);
		}
		else
		{
			if(odd == -1)
				odd = i;
			else
			{
				if(even != -1)
				{
					printf("%d\n",even+1);
					return 0;
				}
			}
		}
	}
	if(a[n-1]%2 == 0)
		printf("%d\n",even+1);
	else
		printf("%d\n",odd+1);
	return 0;
}
