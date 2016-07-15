#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int i,K,N,f=0;
	scanf("%d %d",&K,&N);
	char subs[K][51];
	char inp[51];
	for(i=0;i<K;i++) scanf("%s%*C",subs[i]);
	while(N--)
	{
		scanf("%s",inp);
		f=0;
		if(strlen(inp)>=47)
		{
			printf("Good\n");
			continue;
		}
		for(i=0;i<K;i++)
		{
			if(strstr(inp,subs[i])!=NULL)
			{
				printf("Good\n");
				f=1;
				break;
			}
		}
		if(f==0)
			printf("Bad\n");
	}
	return 0;
}
