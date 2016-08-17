#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

void diameter(int x)
{
	if(x==1)
	{
		printf("0\n");
		return;
	}
	int left,right;
	int maxh;
	maxh = log2(x);
	//printf("maxh = %d\n",maxh);
	int max = (int)(pow(2,maxh+1)-1);
	int elem = pow(2,maxh);
	elem/=2;
	//printf("%d\n",max);
	int flag=0;
	if(max-x >= elem)
		flag = -1;
	else
		flag=1;
	if(flag == 1)
		printf("%d\n",2*maxh);
	else
		printf("%d\n",2*maxh-1);
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int x;
		scanf("%d",&x);
		diameter(x);
	}
	return 0;
}
