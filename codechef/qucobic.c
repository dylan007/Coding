#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int T;
	scanf("%d%*C",&T);
	while(T--)
	{
		int i=2,h=0,m=0;
		char c;
		while(i--)
		{
			c = getchar();
			h = h*10 + c-'0';
		}
		i = 2;
		while(i--)
		{
			c = getchar();
			m = m*10 + c-'0';
		}
		int s,H=0,M=0,max=0;
		scanf("%d%*C",&s);
	//	printf("%d")
		while(s> -60)
		{
			if(h+m > max)
			{
				H = h;
				M = m;
			}
			s-=60;
			m++;
			if(m==60)
			{
				if(h==23)
					h=0;
				else
					h++;
			}
		}
		if(H<10 && M<10)
			printf("0%d0%d\n",H,M);
		else if(H<10 && M>=10)
			printf("0%d%d\n",H,M);
		else if(H>=10 && M<10)
			printf("%d0%d\n",H,M);
		else
			printf("%d%d\n",H,M);
	}
	return 0;
}
