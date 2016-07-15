#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int len,i,k,c=0;
		scanf("%d",&len);
		char str[len+1];
		scanf("%s",str);
		for(i=0;i<len;i++)
			c += (str[i] == '1');
		c = (c*(c+1))/2;
		printf("%d\n",c);
	}
	return 0;
}
