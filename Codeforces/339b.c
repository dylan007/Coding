#include<stdio.h>

int main()
{
	int n,m,i,pos=1;
	long long int time = 0;
	scanf("%d%d",&n,&m);	
	int a[m];
	for(i=0;i<m;i++)
		scanf("%d",&a[i]);
	for(i=0;i<m;i++)
	{
		if(pos<a[i])
		{
			time += a[i]-pos;
			pos = a[i];
		}
		else if(pos>a[i])
		{
			time += n-pos+1;
			time += a[i]-1;
			pos = a[i];
		}
	}
	printf("%I64d\n",time);
	return 0;
}

