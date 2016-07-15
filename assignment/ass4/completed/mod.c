#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	int t,i;
	scanf("%d%*C",&t);
	while(t--)
	{
		char str[1000000];	
		scanf("%s%*C",str);
		int len,x=0;
		len=strlen(str);
		x += str[len-1]-'0';
		x = x+(str[len-2]-'0')*10;
		if(x%4 == 0)
			printf("4\n");
		else
			printf("0\n");
	}
	return 0;
}
