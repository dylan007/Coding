#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int time=0,i,j,len,curr=0,k=0;
	       	char inp[1000010];
		scanf("%s",inp);	
		len = strlen(inp);
		for(i=0;i<len;i++)
		{
			if(inp[i] == '.')
			{
				k=1;
				j=i+1;
				while(inp[j] == '.')
				{k++;j++;}
				if(curr<k)
				{
					curr = k;
					time++;
				}	
				i = j-1;
			}	
		}
		printf("%d\n",time);
	}	
	return 0;
}
