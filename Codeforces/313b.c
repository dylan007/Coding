#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char str[100000];
	scanf("%s",str);
	int j,n,i,m,l,r,count=0;
	scanf("%d",&m);
	n = strlen(str);
	int a[100000] = {0};
	for(i=0;i<(n-1);i++)
	{
		if(str[i] == str[i+1])
			count++;
		a[i+1] = count;
	}
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&l,&r);
		printf("%d\n",a[r-1]-a[l-1]);
	}
	return 0;
}
