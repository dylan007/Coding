#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main()
{
	int sum=0;
	int i,x;
	for(i=0;i<5;i++)
	{
		scanf("%d",&x);
		sum+=x;
	}
	if((sum%5 == 0)&&(sum>0))
		printf("%d\n",sum/5);
	else
		printf("-1\n");
	return 0;
}
