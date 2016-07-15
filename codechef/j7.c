#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		float p,s;
		scanf("%f %f",&p,&s);
		float ans;
		ans = (p - sqrt(p*p - 24*s))/12;
		ans = ans*(ans*ans + s/2 - ans*p/4);
		printf("%.2f\n",ans);
	}
	return 0;
}
