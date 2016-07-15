#include<stdio.h>
#include<string.h>
#include<string.h>
#include<math.h>

int min(int a[],int n)
{
	int i,min=1000000000;
	for(i=0;i<n;i++)
		min = min>a[i]?a[i]:min;
	return min;
}

int cmpfunc(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
	int i,n;
	scanf("%d",&n);
	int a[n],b[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		b[i] = a[i];
	}
	qsort(b,n,sizeof(int),cmpfunc);
	int k,t,c=0,temp,j;
	t = b[0];
	for(k=0;k<n;k++)
	{
		t = b[k];
		j=k;
		while(t == b[j])
			j++;
		k=j-1;	
		for(i=0;i<n;i++)
		{	
			j=i;
			while(t<=a[j] && j<n)
				j++;
			if(i!=j-1)
				c++;
			printf("%d %d %d %d\n",t,j,i,c);
			i=j;
		}
	}
	printf("%d\n",c);
	return 0;
}
