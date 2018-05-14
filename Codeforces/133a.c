#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char p[100];
	scanf("%s",p);
	int len ,i,flag=0;
	len = strlen(p);
	for(i=0;i<len;i++)
	{
		if((p[i]=='Q')||(p[i]=='H')||(p[i] == '9'))
		{
			flag=1;
			break;
		}
	}
	if(flag)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
