#include <stdio.h>
#include<stdlib.h>
int main() 
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	while(!((a==0)&&(b==a)&&(c==a)))
	{
		if((b-a)==(c-b))
			printf("AP %d\n",c+b-a);
		else
			printf("GP %d\n",c*(c/b));
		scanf("%d %d %d",&a,&b,&c);
	}
	return 0;
}
