#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
	 
} 

int partition(int A[], int start, int end){
	int i= start+1;
	int j = i;
	int pivot = start;
	for(; i<end; i++){
		if(A[i]<A[pivot]){
			swap(&A[i],&A[j]);
			j++;
		}
	}
	if(j<=end){
		swap(&A[pivot],&A[j-1]);
	}
	return j-1;
}
 
void quick_sort(int A[], int start, int end, int K){
	int part ;
	if(start < end) {
		part = partition(A, start, end);
		if(part == K-1){
			printf("%d\n", A[part]);
		}
		if(part>K-1){
			quick_sort(A, start,part, K);
		}
		else{
			quick_sort(A, part+1, end, K);
		}
	}
	return;
} 

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,k;
		scanf("%d %d",&n,&k);
		int a[n];
		int i;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		quick_sort(a,0,n,k);
	}
	return 0;
}
