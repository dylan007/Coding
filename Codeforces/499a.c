#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
	int n,x;
	int t=1,time=0;
	scanf("%d %d",&n,&x);
	int a,b,p;
	while(n--)
	{
		scanf("%d %d",&a,&b);
		p = a-t;
		if(p>=x)
			t += (p/x)*x;
		time += (b-t+1);
		t = b+1;
	}
	printf("%d\n",time);
	return 0;
}
