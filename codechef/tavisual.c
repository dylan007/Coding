#include<stdio.h>
#include<stdlib.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int x,y,n,c,q,t;
		scanf("%d %d %d",&n,&c,&q);
		int pos=c;
		while(q--)
		{
			scanf("%d %d",&x,&y);
			if((pos>=x)&&(pos<=y))
				pos = x+y-pos;

		}
		printf("%d\n",pos);
	}
	return 0;
}
