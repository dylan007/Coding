#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,i;
	scanf("%d",&n);
	while(n!=0)
	{
		int a[n],count=0;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<n;i++)
		{
			if(i+1 != a[a[i]-1])
			{ count = 1;break;}
		}
		if(count) printf("not ambiguous\n");
		else printf("ambiguous\n");
		scanf("%d",&n);
	}
	return 0;
}
