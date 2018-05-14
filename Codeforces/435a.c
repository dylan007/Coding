#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int x,i,busn=1,pass=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		if(pass+x <= m)
			pass += x;
		else
		{
			busn++;
			pass = x;
		}
	}	
	printf("%d\n",busn);
	return 0;
}
