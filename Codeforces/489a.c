#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	int j,t,top=0;
	int ans1[n],ans2[n];
	for(i=0;i<n;i++)
	{
		j=i;
		for(t=i;t<n;t++)
		{
			if(a[j]>a[t])
				j=t;
		}
		if(i!=j)
		{
			ans1[top]=i;
			ans2[top++]=j;
		}
		t = a[i];
		a[i] = a[j];
		a[j] = t;
	}
	printf("%d\n",top);
	for(i=0;i<top;i++)
		printf("%d %d\n",ans1[i],ans2[i]);
	return 0;
}
