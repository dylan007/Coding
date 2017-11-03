#include <stdio.h>
#include <stdlib.h>

int find(char s[],int x)
{
	if(s[x] == '\0')
		return -1;
	if(s[x]>=65 && s[x]<=90)
		return x;
	return find(s,x+1);
}

int main()
{
	char s[1000];
	scanf("%s",s);
	int pos;
	pos = find(s,0);
	if(pos>=0)
		printf("%d\n",pos);
	else
		printf("Not Found\n");
	return 0;
}