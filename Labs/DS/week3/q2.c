#include <stdio.h>
#include <stdlib.h>

int len(char s[],int x)
{
	if(s[x] == '\0')
		return 0;
	return 1+len(s,x+1);
}

int main()
{
	char s[100];
	scanf("%s",s);
	printf("%d\n",len(s,0));
	return 0;
}