#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		int j=0,p;
		scanf("%d",&p);
		char c='a';
		getchar();
		printf("%d ",i+1);
		while(c!='\n')
		{
			j++;
			c = getchar();
			if(j!=p)
				putchar(c);
		}
	}
}
