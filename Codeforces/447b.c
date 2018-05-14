#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char inp[1010],x;
	scanf("%s",inp);
	int max=0,sum=0,len,i,k,t;
	int a[26];
	len = strlen(inp);
	scanf("%d",&k);
	for(i=0;i<26;i++)
	{
		scanf("%d",&a[i]);
		if(max<a[i])
		{
			max = a[i];
			x = 'a'+i;
		}
	}
	for(i=0;i<len;i++)
		sum += (i+1)*a[inp[i]-'a'];
	for(i=len;i<=len+k;i++)
		sum += max*i;
	printf("%d\n",sum);
	return 0;
}
