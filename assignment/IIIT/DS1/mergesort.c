#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int n;

void merge(int *a,int low,int mid,int high)
{
	int i,j,k,c[200000];
	i=low;
	j = mid+1;
	k=low;
	while(i<=mid && j<=high)
	{
			if(a[i]<=a[j])
				c[k++] = a[i++];
			else
				c[k++] = a[j++];
	}
	while(i<=mid)
		c[k++] = a[i++];
	while(j<=high)
		c[k++] = a[j++];	
	for(i=low;i<k;i++)
		a[i] = c[i];
	for(i=low;i<k;i++)
		printf("%d ",a[i]);
	printf("\n");
	return;
}

void mergesort(int *a,int low,int high)
{
	int mid;
	mid = (low+high)/2;
	if(low>=high)
		return;
	mergesort(a,low,mid);
	mergesort(a,mid+1,high);
	merge(a,low,mid,high);
	return;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a[20010];
		int i;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		mergesort(a,0,n-1);
		for(i=0;i<n;i++)
			printf("%d ",a[i]);
		printf("\n");
	}
	return 0;
}
