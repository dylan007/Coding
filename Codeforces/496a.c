#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	int j,t;
	int max=INT_MIN;
	int min=INT_MAX;
	for(i=1;i<(n-1);i++)
	{
		max = INT_MIN;
		for(j=1;j<n;j++)
		{
			if(j==i)
				continue;
			t = a[j]-a[j-1-(j == i+1)];
			max = max>t?max:t;
		}
		min = max<min?max:min;
	}
	printf("%d\n",min);
	return 0;
}
