#include <stdio.h>
#include <stdlib.h>

int check(char s[],int x,int l)
{
	if(x>(l/2))
		return 1;
	if(s[x] != s[l-x-1])
		return 0;
	return check(s,x+1,l);
}

int len(char s[],int x)
{
	if(s[x] == '\0')
		return 0;
	return 1+len(s,x+1);
}

int main()
{
	char s[1000];
	scanf("%s",s);
	if(check(s,0,len(s,0)))
		printf("Palindrome\n");
	else
		printf("Not palindrome\n");
	return 0;
}