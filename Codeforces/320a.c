#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int magic(char str[],int len)
{
	int i,flag=1;
	for(i=0;i<len;i++)
	{
		if((str[i] == '1')&&(str[i+1] == '4')&&(str[i+2] == '4'))
		{
			flag=0;
			i = i+2;
		}
		else if((str[i] == '1')&&(str[i+1] == '4'))
		{
			flag=0;
			i = i+1;
		}
		else if((str[i]=='1'))
			flag = 0;
		else
			return 1;
	}
	return flag;
}

int main()
{
	char num[1000000000];
	scanf("%s",num);
	int len;
	len = strlen(num);
	if(magic(num,len) == 1)
		printf("NO\n");
	else
		printf("YES\n");
	return 0;
}
