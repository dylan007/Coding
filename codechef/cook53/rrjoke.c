#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		int i,ans=0;
		int x,y;
		for(i=1;i<=n;i++)
		{
			scanf("%d %d",&x,&y);
			ans = ans^i;
		}
		printf("%d\n",ans);
	}
	return 0;
}
