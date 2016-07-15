#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i,n,ans=0;
	scanf("%d",&n);
	ans += n;
	for(i=1;i<n;i++)
		ans += i*(n-i);
	printf("%d\n",ans);
	return 0;
}
