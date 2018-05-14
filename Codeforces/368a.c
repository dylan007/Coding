#include<stdio.h>
#include<stdlib.h>

int cmpfunc(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
	int n,d,x,t=0,i;
	scanf("%d %d",&n,&d);	
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	qsort(a,n,sizeof(int),cmpfunc);	
	int m;
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		if(n >= i+1)
			t += a[i];
		else 
			t -= d;;
	}
		printf("%d\n",t);
	return 0;
}
