#include <stdio.h>
#include <stdlib.h>

void copys(char s[],char t[],int x)
{
	if(s[x]=='\0')
	{
		t[x] = s[x];
		return;
	}
	t[x] = s[x];
	copys(s,t,x+1);
	return;	
}

int main()
{
	char s[100],t[100];
	scanf("%s",s);
	copys(s,t,0);
	printf("%s\n",t);
	return 0;
}