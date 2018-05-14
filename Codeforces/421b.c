#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int palindrome(char str[])
{
	int len;
	len = strlen(str)-1;
	int i;
	for(i=0;i<(len/2);i++)
	{
		if(str[i]!=str[len-i-1])
			return 0;
	}
	return 1;
}

int main()
{
	char c='a';
	char str[100010];
	int f=0,top=0;
	while(c!='\n')
	{
		c = getchar();
		if((c>='A' && c<='Z') && !((c=='A')||(c=='H')||(c=='I')||(c=='M')||(c=='O')||(c=='T')||(c=='U')||(c=='V')||(c=='W')||(c=='X')||(c=='Y')))
		{
			f=1;
			break;
		}
		str[top++]=c;
	}
	str[top]='\0';
	if(f==1)
		printf("NO\n");
	else
	{
		if(palindrome(str)==1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
