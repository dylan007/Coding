#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,i,x=0;
	scanf("%d",&n);
	char str[3];
	for(i=0;i<n;i++)
	{
		scanf("%s",str);
		if((str[0] == '+')||(str[2] == '+'))
			x += 1;
		else if((str[0] == '-')||(str[2] == '-'))
			x -= 1;
	}
	printf("%d\n",x);
	return 0;
}
