#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct 
{
	char name[21];
	int status;
	char vote[2];
}entry;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,i,j,score=0,curr=0;
		scanf("%d",&n);
		entry list[100];
		for(i=0;i<n;i++) 
		{
			scanf("%s%s",list[i].name,list[i].vote);
			list[i].status = 0;
		}
		for(i=0;i<n;i++)
		{
			if(list[i].status == 0)
			{
				for(j=i;j<n;j++)
				{
					if(strcmp(list[i].name,list[j].name)==0)
					{
						curr = (list[j].vote[0] == '+')?1:-1;
						list[i].status = 1;
					}
				}
				score += curr;
			}
		}
		printf("%d\n",curr);
	}
	return 0;
}
