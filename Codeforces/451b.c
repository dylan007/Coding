#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	int i;
	int count=0;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	int f=0;
	for(i=0;i<(n-1);i++)
	{
		if(a[i]>a[i+1])
		{
			if(f==0)
			{
				f=1;
				count++;
			}
		}
		else
			f=0;
	}
	if(count>1)
		printf("%d")
}
