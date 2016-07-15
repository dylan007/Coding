#include<stdio.h>
#include<stdlib.h>

int cmpfunc(const void *a, const void *b)
{
	return *(int *)b - *(int *)a;
}

int main()
{
	int n,k,i,f,t;
	scanf("%d %d",&n,&k);
	int joy[n];
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&f,&t);
		if(t<=k)
			joy[i] = f;
		else
			joy[i] = f - (t-k);
	}
	qsort(joy,n,sizeof(int),cmpfunc);
	printf("%d\n",joy[0]);
	return 0;
}
