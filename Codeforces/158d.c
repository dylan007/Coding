#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,i,sum1=0,sum2=0,x,sum;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		if(i%2 == 0)
			sum1 += x;
		else
			sum2 += x;
	}
	sum = sum1+sum2;
	if(n <= 4)
		printf("%d\n",sum);
	else if((sum>sum1)&&(sum>sum2))
		printf("%d\n",sum);
	else if((sum1>=sum)&&(sum1>sum2))
		printf("%d\n",sum1);
	else if((sum2>sum1)&&(sum2>=sum))
		printf("%d\n",sum2);
	return 0;
}
