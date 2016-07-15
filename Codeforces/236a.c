#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char str[100];
	scanf("%s",str);
	int flag[26]={0};
	int i,t,len,sum=0;
	len = strlen(str);
	for(i=0;i<len;i++)
	{
		t = str[i];
		t -= 97;
		flag[t]=1;
		//printf("i=%d t=%d\n",i,t);
	}
	for(i=0;i<26;i++)
		sum += flag[i];
//	printf("%d\n",sum);
	if(sum%2 == 0)
		printf("CHAT WITH HER!\n");
	else
		printf("IGNORE HIM!\n");
	return 0;
}
