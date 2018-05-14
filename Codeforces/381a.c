#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,i,s=0,d=0,start=0,end;
	scanf("%d",&n);
	end = n-1;
	int arr[n];
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	for(i=0;i<n;i++)
	{
		if(arr[start]>=arr[end])
		{
			if(i%2 == 0)
				s += arr[start];
			else
				d += arr[start];
			start++;
		}
		else
		{
			if(i%2 == 0)
				s += arr[end];
			else
				d += arr[end];
			end--;
		}
	}
	printf("%d %d\n",s,d);
	return 0;
}
