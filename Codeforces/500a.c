#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int n,t;
	scanf("%d %d",&n,&t);
	n--;
	int a[n];
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	int pos=1,f=0;
	while(pos<=n && pos!=t)
	{
		pos += a[pos-1];
		if(pos==t)
			f=1;
	}
	if(f==1)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
