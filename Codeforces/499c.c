#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
	long long int x1,x2,y1,y2;
	scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);
	long long int n;
	long long int count=0;
	scanf("%lld",&n);
	long long int a,b,c;
	while(n--)
	{
		scanf("%lld %lld %lld",&a,&b,&c);
		long long int t1,t2;
		t1 = a*x1+b*y1+c;
		t2 = a*x2+b*y2+c;
		t1 = t1>0?1:-1;
		t2 = t2>0?1:-1;
		if(t1*t2<0)
			count++;
	}
	printf("%lld\n",count);
	return 0;
}
