#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	int x,i=0;
	scanf("%d",&x);
	while(x>0)
	{
		i++;
		x -= (i*(i+1))/2;
		if(x<0)
			i--;
	}
	printf("%d\n",i);
	return 0;
}
