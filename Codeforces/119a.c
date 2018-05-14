#include<stdio.h>
#include<stdlib.h>

int gcd(int a, int b)
{
	int t;
	while(b)
	{
		t = a;
		a = b;
		b = t%b;	
	}
	return a < 0 ? -a : a;
}

int main()
{
	int a,b,n,flag=0,g,i=0;
	scanf("%d %d %d",&a,&b,&n);
	while(!flag)
	{
		if(i%2 == 0)
		{
			g = gcd(a,n);
		//	printf("i = %d g = %d\n",i,g);
			if(g>n)
			{
				flag=1;
				break;
			}
			else
				n = n-g;
		}
		else
		{
			g = gcd(b,n);
		//	printf("i = %d g = %d\n",i,g);
			if(g>n)
			{
				flag=1;
				break;
			}
			else
				n = n-g;
		}
		i++;
	}
	printf("%d\n",((i+1)%2));
	return 0;
}
