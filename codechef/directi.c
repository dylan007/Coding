#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,i,t,j;
		scanf("%d%*C",&n);
		char route[45][55];
		for(i=0;i<n;i++) fgets(route[i],sizeof(route[i]),stdin);
		printf("Begin on ");
		for(i=n;i>=0;i--)
		{
			if(route[i-1][0] == 'L')
				t = 8;
			else
				t = 9;
			while(route[i-1][t]!='\0')
			{
				printf("%c",route[i-1][t]);
				t++;
			}
			if(i==1)
				break;
			if(route[i-1][0] == 'L')
				printf("Right on ");
			else
				printf("Left on ");
		}
	}
	return 0;
}
