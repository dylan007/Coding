#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int r[314159]={0};
int c[314159]={0};

int main()
{
	int i,j,N,Q,m1=0,m2=0;
	scanf("%d %d",&N,&Q);
	char inp[15];
	while(Q--)
	{
		scanf("%s %d %d",inp,&i,&j);
		if(inp[0] == 'R')
		{
			r[i-1] += j;
			m1 = m1>r[i-1]?m1:r[i-1];
		}
		else
		{
			c[i-1] += j;
			m2 = m2>c[i-1]?m2:c[i-1];
		}
	}
	printf("%d\n",m1+m2);
	return 0;
}
