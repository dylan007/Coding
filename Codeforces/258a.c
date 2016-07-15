#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char binnum[100000];
	scanf("%s",binnum);
	int len,i,t;
	len = strlen(binnum);
	for(i=0;i<len;i++)
	{
		if(binnum[i]=='0')
		{
			t = i;
			break;
		}
	}
	for(i=0;i<len;i++)
	{
		if(i != t)
			printf("%c",binnum[i]);
	}
	printf("\n");
	return 0;
}
