#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	long long int n1,n2,n3,p1,p2,p3,r;
	char rec[110];
	scanf("%s",rec);
	scanf("%lld %lld %lld %lld %lld %lld %lld",&n1,&n2,&n3,&p1,&p2,&p3,&r);
	long long int c1=0,c2=0,c3=0,i;
	for(i=0;i<strlen(rec);i++)
	{
		c1+=(rec[i]=='B');
		c2+=(rec[i]=='S');
		c3+=(rec[i]=='C');
	}
	long long int min;
	if(c1>0)
		min = n1/c1;
	if(c2>0)
		min = (min > n2/c2)?n2/c2:min;
	if(c3>0)
		min = (min > n3/c3)?n3/c3:min;
	n1 -= c1*min;
	n2 -= c2*min;
	n3 -= c3*min;
	printf("%lld %lld %lld %lld\n",n1,n2,n3,min);
	while(r>0)
	{
		r -= (c1-n1)*p1;
		r -= (c2-n2)*p2;
		r -= (c3-n3)*p3;
		n1 = n2 = n3 =0 ;
		if(r<0)
			break;
		min++;
	}
	printf("%lld\n",min);
	return 0;
}
