#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	int x,y,z;
	y = sqrt((a*b)/c);
	x = a/y;
	z = b/y;
	printf("%d\n",4*(x+y+z));
	return 0;
}
