#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,t,c,max=0;
	scanf("%d %d %d",&n,&t,&c);
	int sev[n],i,f=0,j,cou=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&sev[i]);
		max = max>sev[i] ? max:sev[i];
	}
	for(i=0;i<c;i++)
	{
		if(sev[i]>t)
			f++;
	}
	cou += (f == 0);
	for(i=c;i<(n);i++)
	{
		if(sev[i]>t) f++;
		if(sev[i-c]>t) f--;
		if(f == 0) cou++;
	}
	printf("%d\n",cou);
	return 0;
}
