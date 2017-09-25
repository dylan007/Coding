#include <stdio.h>
 
int main() {
	int n,ans;
	scanf("%d",&n);
	ans = (n*(n+1)*(2*n+1))/6;
	while(n!=0)
	{
		printf("%d\n",ans);
		scanf("%d",&n);
		ans = (n*(n+1)*(2*n+1))/6;
	}
	return 0;
} 