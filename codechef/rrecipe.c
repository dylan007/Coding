#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		char str[1000009];
		scanf("%s",str);
		int len,i,ans=1;
		len = strlen(str);
		for(i=0;i<(len+1)/2;i++)
		{
			if(str[i]==str[len-i-1] && str[i]=='?')
				ans = (ans*26)%10000009;
			else
			{
				if(str[i]!='?' && str[len-i-1]!='?')
				{
					ans = 0;
					printf("%c %d %d\n",str[i],i,len);
					break;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
