#include<stdio.h>
#include<stdlib.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,i,t,maxtime=0;
		scanf("%d",&n);
		int arr[n],dept[n];
		for(i=0;i<n;i++) scanf("%d",&arr[i]);
		for(i=0;i<n;i++) {scanf("%d",&dept[i]);maxtime = maxtime<dept[i]?dept[i]:maxtime;}
		int time[maxtime];
		for(i=0;i<maxtime;i++) time[i] = 0;
		for(i=0;i<n;i++)
		{
			for(t = arr[i]-1;t<maxtime;t++)
				time[t]++;
		}
		for(i=0;i<n;i++)
		{
			for(t=dept[i]-1;t<maxtime;t++)
				time[t]--;
		}
		int max=0;
		for(i=0;i<maxtime;i++) max=max>time[i]?max:time[i];
		printf("%d\n",max);
	}	
	return 0;
}
