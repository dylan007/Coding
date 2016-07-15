#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char msg[100];
	scanf("%s",msg);
	int pos=0,i=0;
	char a[5]={'h','e','l','l','o'};
	for(i=0;msg[i]!='\0';i++)
	{
		if(a[pos] == msg[i])
			pos++;
	}
	if(pos>=5)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
