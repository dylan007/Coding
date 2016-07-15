#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	int N;
	scanf("%d",&N);
	int a[N];
	int i=0,j,count=0,f=0,F=0;
	for(i=0;i<N;i++) 
	{
		scanf("%d",&a[i]);	
		if(a[i]==1 && f==0)
			f=i;
	}
	for(i=N-1;i>=0;i--)
		if(a[i]==1)break;
	F=i;
	if(a[0]==1)
		f=0;
	i = f;
	while(i<(N-1))
	{
		if(a[i]==1)
		{
			count++;
			while(a[i+1]==1 && i<(N-1))
				count++,i++;
			if(a[i+1]==0)
				count++,i++;
		}
		else
			i++;
		if(i==(F+1)) break;
		printf("%d %d\n",i,count);
	}
	count -= F!=(N-1);
	printf("%d\n",count);
	return 0;
}
