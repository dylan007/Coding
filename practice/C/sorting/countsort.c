#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void countsort(int *arr,int n)
{
	int output[n];
	int count[10];
	int i;
	for(i=0;i<n;i++) count[i]=0;
	for(i=0;i<n;i++)
		count[arr[i]]++;
	for(i=0;i<10;i++)
		count[i] += count[i-1];
	for(i=0;i<10;i++)
		printf("%d ",count[i]);
	printf("\n");
}

int main()
{
	int n;
	scanf("%d",&n);
	int arr[n];
	int i=0;
	for(i=0;i<n;i++) scanf("%d",&arr[i]);
	countsort(arr,n);
	for(i=0;i<n;i++) printf("%d ",arr[i]);
	printf("\n");
}
