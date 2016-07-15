#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int k;
		scanf("%d",&k);
		getchar();
		char inp[10010];
		scanf("%s",inp);
		getchar();
		int i,t;
		for(i=0;i<strlen(inp);i++)
		{
			t = inp[i]-'a';
			printf("%c",((t+k)%26)+'a');
		}
		printf("\n");
	}	
	return 0;
}
