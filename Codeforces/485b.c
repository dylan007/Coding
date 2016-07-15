#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>


int main()
{
	long long int T;
	scanf("%lld",&T);
	long long int x[T],y[T],i;
	long long int maxx=LONG_MIN,maxy=LONG_MIN;
	long long int minx=LONG_MAX,miny=LONG_MAX;
	for(i=0;i<T;i++)
	{
		scanf("%lld %lld",&x[i],&y[i]);
		maxx = maxx>x[i]?maxx:x[i];
		maxy = maxy>y[i]?maxy:y[i];
		minx = minx>x[i]?x[i]:minx;
		miny = miny>y[i]?y[i]:miny;
	}
	maxx = maxx-minx;
	maxy = maxy-miny;
	maxx = maxx>maxy?maxx:maxy;
	printf("%lld\n",maxx*maxx);
	return 0;
}
