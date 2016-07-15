#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int a[n],max=INT_MIN;
	int t,i,pos;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		t = a[i]/m + !(a[i]%m == 0);
		if(max<=t)
		{
			pos = i;
			max = t;
		}
	}
	printf("%d\n",pos+1);
	return 0;
}
