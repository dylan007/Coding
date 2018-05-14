#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	memset(a,0,4*n);
	int i,x,t;
	scanf("%d",&t);
	while(t--)
		scanf("%d",&x),a[x-1]=1;
	scanf("%d",&t);
	while(t--)
		scanf("%d",&x),a[x-1]=1;
	int f=0;
	for(i=0;i<n;i++)
	{
		if(a[i]==0)
		{
			f=1;
			break;
		}
	}
	if(f==1)
		printf("Oh, my keyboard!\n");
	else
		printf("I become the guy.\n");
	return 0;
}
