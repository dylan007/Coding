#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a,b,i;
	int x=0,y=0,z=0;
	scanf("%d %d",&a,&b);
	for(i=1;i<=6;i++)
	{
		if(abs(a-i)<abs(b-i))
			x++;
		else if(abs(a-i) == abs(b-i))
			y++;
		else
			z++;
	}
	printf("%d %d %d\n",x,y,z);
	return 0;
}
