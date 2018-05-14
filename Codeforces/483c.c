#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	int a[n];
	int i,curr=k;
	a[0]=1;
	for(i=1;i<n;i++)
	{
		if(curr==0)
		{
			a[i]=2+k;
			curr--;
		}
		else if(curr==-1)
			a[i] = a[i-1]+1;
		else
		{
			if(i%2 == 1)
				a[i] = a[i-1]+curr;
			else
				a[i] = a[i-1]-curr;
			curr--;
		}
	}
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
