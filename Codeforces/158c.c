#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int T,t;
	char dir[200] = {""};
	dir[0] = '/';
	scanf("%d",&T);
	//printf("%s\n",dir);
	for(t=0;t<T;t++)
	{
		char cmd[200];
		int len,k,j=0;
		scanf("%s",cmd);
		len = strlen(cmd);
		if(cmd[0] == 'p')
			printf("%s\n",dir);
		else if(cmd[0] == 'c')
		{
			k = cmd[3];
			printf("%d\n",k);
			printf("%c\n",cmd[4]);
			if(cmd[4] == '/')
			{
				printf("ajsdnakjbska\n");
				for(k=3;k<len;k++)
				{
					dir[j] = cmd[k];
					j++;
				}
			}
		}
		//printf("%d\n",t);
	}
	return 0;
}
