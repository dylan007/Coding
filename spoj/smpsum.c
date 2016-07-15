#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	int ans;
	a -= 1;
	ans = (b*(b+1)*(2*b + 1)) - (a*(a+1)*(2*a + 1));
	ans /= 6;
	printf("%d\n",ans);
	return 0;
}
