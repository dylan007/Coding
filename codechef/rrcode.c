#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,k,ans;
		scanf("%d %d %d",&n,&k,&ans);
		int i,a[n];
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		char op[5];
		scanf("%*C%s",op);
		if(!strcmp("OR",op))
		{
			if(k)
			{
				for(i=0;i<n;i++)
					ans = ans|a[i];
			}
		}
		else if(!strcmp("XOR",op))
		{
			if(k&1)
			{
				for(i=0;i<n;i++)
					ans = ans^a[i];
			}
		}
		else
		{
			if(k)
			{
				for(i=0;i<n;i++)
					ans = ans&a[i];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
