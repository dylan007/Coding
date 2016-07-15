#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int area(int x1,int y1,int x2,int y2,int x3,int y3)
{
	int ans;
	ans = (abs((x1-x3)*(y2-y1) - (x1-x2)*(y3-y1)));
	return ans;
}

int max(int a[],int n)
{
	int i,max=0,maxindex;
	for(i=0;i<n;i++)
	{
		if(max<=a[i])
		{
			max=a[i];
			maxindex=i;
		}
	}
	return maxindex+1;
}

int min(int a[],int n)
{
	int i,min,minindex;
	min = a[max(a,n)-1];
	for(i=0;i<n;i++)
	{
		if(min>=a[i])
		{
			min = a[i];
			minindex = i;
		}
	}	
	return minindex+1;
}	
int main()
{
	int n,i;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		int x1,x2,x3,y1,y2,y3;
		scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
		a[i]=area(x1,y1,x2,y2,x3,y3);
	}
	printf("%d %d\n",min(a,n),max(a,n));
	return 0;
}
