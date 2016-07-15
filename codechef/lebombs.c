#include<stdio.h>
#include<stdlib.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,c,i;
		scanf("%d",&n);
		c = n;
		char a[1001];
		scanf("%s",a);
		if(n==1)
			a[0]=='1'?printf("0\n"):printf("1\n");
		else if(n>1)
		{
			if(a[0]=='1'||a[1]=='1')
				c--;
			for(i=1;i<n-1;i++)
			{
				if(a[i] == '1')
					c--;
				else if((a[i-1] == '1')||(a[i+1] == '1'))
					c--;
			}
			if(a[n-1]=='1' || a[n-2]=='1')
				c--;
			printf("%d\n",c);
		}
	}
	return 0;
}
