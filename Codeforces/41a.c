#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char s1[100],s2[100];
	int len,i;
	scanf("%s%*C%s",s1,s2);
	len = strlen(s1);
	for(i=0;i<len;i++)
	{
		if(s1[i] != s2[len-1-i])
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}
