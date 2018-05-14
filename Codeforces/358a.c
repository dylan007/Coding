#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	int f1=0,j,f2;
	for(i=0;i<(n-1);i++)
	{
		f1=0;
		f2=0;
		for(j=i+2;j<n;j++)
		{
			if((a[j]>a[i] && a[j]>a[i+1]) || (a[j]<a[i] && a[j]<a[i+1]))
				f1=1;
			else
				f2=1;
		}
		if(f1==1 && f2==1)
			break;
	}
	if(f1==1 && f2==1)
		printf("yes\n");
	else
		printf("no\n");
}
