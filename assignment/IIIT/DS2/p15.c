#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<limits.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int stack[10000];
		int front=-1,rear=-1;
		int flag=0;
		int n,k;
		scanf("%d %d",&n,&k);
		int i,x;
		int ans[n-k+1];
		int min=INT_MAX;
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			min = min < x?min:x;
			if(flag==0)
			{
				front = 0;
				rear = 0;
				stack[0] = x;
				flag=1;
			}
			else
			{
				if(i<(k-1))
				{
					//printf("i<k i=%d  min=%d\n",i,min);
					stack[front++] = x;
				}
				else
				{
					//printf("i>=k i=%d  min=%d\n",i,min);
					int temp;
					temp = stack[rear++];
					if(temp == min)
					{
						
					}
					printf("%d ",min);
				}
			}
		}
		printf("\n");
	}
	return 0;
}
