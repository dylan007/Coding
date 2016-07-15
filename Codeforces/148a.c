#include<stdio.h>
#include<stdlib.h>

int main()
{
	unsigned int k,l,m,n,d,i,count=0;
	scanf("%u%u%u%u%u",&k,&l,&m,&n,&d);
	if((k == 1)||(l == 1)||(m == 1)||(n == 1)){
		printf("%u\n",d);
		return 0;
	}
	for(i=1;i<=d;i++)
	{
		if((i%k == 0)||(i%l == 0)||(i%m == 0)||(i%n == 0))
			count++;
	}
	printf("%u\n",count);
	return 0;
}
