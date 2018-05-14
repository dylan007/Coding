#include <stdio.h>
#include <string.h>
#include <string.h>

int main()
{
	char vals[1000][1000];
	char s[1000];
	int i;
	for(i=0;i<5;i++)
	{
		scanf("%s",s);
		strcpy(vals[i],s);
	}
	for(i=0;i<5;i++)
		printf("%s\n", vals[i]);
}