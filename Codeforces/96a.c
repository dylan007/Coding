#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char str[100];
	scanf("%s",str);
	int len,i,count=0,t,j;
	len = strlen(str);
	for(i=0;i<len;i++)
	{
		count = 0;
		for(j=i;j<len;j++)
		{
			if(str[i]!=str[j])
			{
				i = j;
				//printf("break j = %d\n",j);
				break;
			}
			count++;
			if(count == 7)
			{
				//printf("y j = %d\n",j);
				printf("YES\n");
				return 0;
			}
			//printf("j= %d count = %d\n",j,count);
		}
	}
	printf("NO\n");
	return 0;
}
