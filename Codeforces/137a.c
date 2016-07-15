#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char list[100];
	scanf("%s",list);
	int len,i,count=1,ans=0;
	len = strlen(list);
	for(i=1;i<len;i++)
	{
		if((list[i] != list[i-1]) || (count == 5))
		{
			ans++;
			count = 1;
		}
		else
			count++;

	}
	ans++;
	printf("%d\n",ans);
	return 0;
}
