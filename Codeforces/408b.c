#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>

int main()
{
	int inp[26],gar[26];
	memset(inp,0,4*26);
	memset(gar,0,4*26);
	char str[1010],garl[1010];
	scanf("%s%*C",str);
	scanf("%s",garl);
	int i;
	for(i=0;i<strlen(str);i++)
		inp[str[i]-'a']++;
	for(i=0;i<strlen(garl);i++)
		gar[garl[i]-'a']++;
	int min=INT_MAX;
	int count=0;
	for(i=0;i<26;i++)
	{
		min = inp[i]<gar[i]?inp[i]:gar[i];
		if(min==0 && gar[i]!=0)
		{
			count=0;
			break;
		}
		count+=min;
	}
	if(count==0)
		count--;
	printf("%d\n",count);
	return 0;
}
