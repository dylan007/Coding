#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int start[1000000],end[1000000];
int n;

int binarysearch(int high,int low,int x)
{
	int mid = high+low;
	mid /= 2;
	if(start[mid]<=x && end[mid]>=x)
		return mid;
	else if(x>end[mid])
		binarysearch(high,mid+1,x);
	else if(x<start[mid])
		binarysearch(mid-1,low,x);
}

int main()
{
	scanf("%d",&n);
	int i,x;
	scanf("%d",&x);
	start[0]=1;
	end[0]=x;
	for(i=1;i<n;i++)
	{
		scanf("%d",&x);
		start[i]=end[i-1]+1;
		end[i]=end[i-1]+x;
	}
	int m;
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%d",&x);
		printf("%d\n",binarysearch(n-1,0,x)+1);
	}
	return 0;
}
