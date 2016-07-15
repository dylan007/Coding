#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	if(((a-b)%10 == 0)||((a-b)%10)==1)
		printf("%d\n",a-b+1);
	else
		printf("%d\n",a-b-1);
	return 0;
}
