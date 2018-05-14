#include<stdio.h>
#include<stdlib.h>

int main()
{
	int N;
	scanf("%d",&N);
	int a[N],i,j,k=0,top=0,start=0,pos=0;
	for(i=0;i<N;i++) scanf("%d",&a[i]);
	int state[N],paths[N][N];
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++) paths[i][j] = 0;
		state[i] = 0;	
	}
	for(i=0;i<N;i++)
	{
		if(state[i] == 1)
			continue;
		else
		{
			start = i;
			pos = a[i]-1;
			j=1;
			paths[k][0] = start+1;
			state[i] = 1;
			top++;
			while(pos != start)	
			{
				paths[k][j] = pos+1;
				state[pos] = 1;
				pos = a[pos] - 1;
				j++;
			}
			paths[k][j] = pos+1;
			k++;
		}
	}
	printf("%d\n",top);
	for(i=0;i<top;i++)
	{
		j=0;
		while(paths[i][j]!=0)
		{
			printf("%d ",paths[i][j]);
			j++;
		}
		printf("\n");
	}
	return 0;
}
