#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	int N;
	scanf("%d%*C",&N);
	int a[N];
	int i,x;
	char C;
	for(i=0;i<N;i++)
	{
		C = getchar();
		a[i] = C-'0';
	}
	int c=1;
	int sum=0;
	int t;
	for(i=0;i<N;i++)
	{
		t = a[i];
		sum += !(a[i]==(a[i]+c));
		a[i] = a[i]^c;
		c = t*c;
	}
	printf("%d\n",sum);
	return 0;
}
