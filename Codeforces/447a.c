#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i,p,n,x=0,f=0;
	scanf("%d %d",&p,&n);
	int a[p];
	for(i=0;i<p;i++)
		a[i] = -1;
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		if(a[x%p] != -1)
		{
			f = i;
			break;
		}
		else
			a[x%p] = x;
	}
	if(f==0)
		f=-2;
	printf("%d\n",f+1);
	return 0;
}
