//codeforces problem code : 1A
//problem : Theatre Square
#include<stdio.h>
#include<stdlib.h>

int main()
{
	long long int n,m,a,x,y,ans;
	scanf("%lld%lld%lld",&n,&m,&a);
	x=n/a;
	y=m/a;
	if( n%a != 0 )
		x = x+1;
	if( m%a != 0 )
		y=y+1;
	printf("%lld\n",x*y);
	return 0;
}
