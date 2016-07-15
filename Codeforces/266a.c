#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int len,count=0,i;
	scanf("%d",&len);
	char str[len];
	scanf("%s",str);
	for(i=0;i<(len-1);i++)
	{
		if(str[i] == str[i+1])
			count++;
	}
	printf("%d\n",count);
	return 0;
}
