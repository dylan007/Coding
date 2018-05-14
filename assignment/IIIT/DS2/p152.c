#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>

int minVal(int x, int y){return x<y?x:y;}

int query(int *tree, int start, int end, int qs, int qe, int index)
{
	if(qs<=start && qe>=end)
		return tree[index];
	else if(end < qs || start > qe)
		return INT_MAX;
	int mid = start+(end-start)/2;
	return minVal(query(tree, start, mid, qs, qe, 2*index+1),query(tree, mid+1, end, qs, qe, 2*index+2));
}

int buildtree(int arr[], int start, int end, int *tree, int index)
{
	if(start == end)
	{
		tree[index] = arr[start];
		return arr[start];	
	}
	int MID = start+(end-start)/2;
	tree[index] =  minVal(buildtree(arr, start, MID, tree, index*2+1),buildtree(arr, MID+1, end, tree, index*2+2));
	return tree[index];
}

int *build(int arr[],int n)
{
	int height;
	height = (int)(ceil(log2(n)));
	int size = 2*(int)(pow(2,height)) - 1;
	int *tree = (int *)malloc(sizeof(int) * size);
	buildtree(arr,0,n-1,tree,0);
	int i;
//	for(i=0;i<size;i++)
//		printf("%d ",tree[i]);
//	printf("\n");
	return tree;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,k;
		scanf("%d %d",&n,&k);
		int i,a[n];
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		int *tree = build(a,n);
		for(i=0;i<(n-k+1);i++)
		{
			printf("%d",query(tree,0,n-1,i,i+k-1,0));
			(i==(n-k))?:printf(" ");
		}
		printf("\n");
	}
	return 0;
}
