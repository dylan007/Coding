#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MOD 1000000007

int main()
{
	int n;
	scanf("%d",&n);
	int p[1010];
	int i;
	for(i=1;i<=n;++i)
		scanf("%d",&p[i]);
	int j,t[1010];
	for(i=1;i<=n;++i)
	{
		t[i]=2;
		for(j=p[i];j<i;++j)
			t[i] = (t[i]+t[j])%MOD;
	}
	int r;
	for(i=1;i<=n;++i)
		 r = (r+t[i]) % MOD;
	printf("%d\n",r);
	return 0;
}
