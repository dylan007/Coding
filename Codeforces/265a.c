#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char s[50],t[50];
	int pos=0,i,j=0,lens,lent;
	scanf("%s %s",s,t);
	lens = strlen(s);
	lent = strlen(t);
	for(i=0;i<lent;i++)
	{
		if(s[pos]==t[i])
			pos++;
	}
	printf("%d\n",pos+1);
	return 0;
}
