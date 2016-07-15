#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int cmpfunc(const void *a,const void *b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
	int N;
	scanf("%d%*C",&N);
	int a[5][N];
	char c;
	int x,i,t;
	int top[5];
	memset(top,0,5*sizeof(int));
	while(N--)
	{
		c = getchar();
		scanf("%d%*C",&x);
		a[c-'A'][top[c-'A']] = x;
		top[c-'A']++;
	}
	for(i=0;i<5;i++)
	{
		int j;
		if(top[i]==0)
			printf("Nothing Unusual\n");
		else
		{
			qsort(a[i],top[i],sizeof(int),cmpfunc);
			t = a[i][0];
			printf("%d ",a[i][0]);
			for(j=1;j<top[i];j++)
			{
				if(t!=a[i][j])
				{
					printf("%d ",a[i][j]);
					t = a[i][j];
				}
			}
			printf("\n");
		}
	}
}
