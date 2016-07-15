#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		char inp[1005];
		scanf("%s",inp);
		int i,len,inst=0;
		len = strlen(inp);
		for(i=0;i<len-1;i++)
		{
			if(inp[i+1]>inp[i])
				inst += inp[i+1]-inp[i];
			else if(inp[i+1]<inp[i])
				inst += 122-inp[i]+inp[i+1]-96;
		}
		inst += len+1;
		if(inst>(len*11))
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
