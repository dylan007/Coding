#include<stdio.h>
#include<stdlib.h>

int cmpfunc(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
	int i,n,m;
	scanf("%d %d",&n,&m);
	int f[m],min;
	for(i=0;i<m;i++)
		scanf("%d",&f[i]);
	qsort(f,m,sizeof(int),cmpfunc);
	//printf("%d\n",f[0]);
	min = f[n-1]-f[0];
	for(i=0;i<(m-n+1);i++)
		min = min>(f[i+n-1]-f[i])?(f[i+n-1]-f[i]):min;
	printf("%d\n",min);
	return 0;
}
