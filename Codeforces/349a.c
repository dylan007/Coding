#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,i,x,c1=0,c2=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		if(i == 0)
		{
			if(x == 25)
				c1++;
			else
			{
				printf("NO\n");
				return 0;
			}
		}
		else
		{
			switch(x)
			{
				case 25:
					c1++;
					break;
				case 50:
					c2++;
					if(c1 == 0)
					{
						printf("NO\n");
						return 0;
					}
					c1--;
					break;
				case 100:
					if(c1&&c2)
					{
						c1 -= 1;
						c2 -= 1;
					}
					else if(c1>=3)
						c1 -= 3;
					else
					{
						printf("NO\n");
						return 0;
					}
					break;
			}
		}
	}
	printf("YES\n");
	return 0;
}
