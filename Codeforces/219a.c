#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmpfunc(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
	int i,k,len,count[26],t;
	scanf("%d",&k);
	char s[1000];
	scanf("%s",s);
	len = strlen(s);
	int out[len];
	if(len%k != 0)
	{
		printf("-1\n");
		return 0;
	}
	if(k==1)
	{
		printf("%s\n",s);
		return 0;
	}
	for(i=0;i<26;i++)
	{
		t = s[i] - 'a';
		count[t]++;
	}
	for(i=0;i<len;i++)
		out[i] = s[i];
	qsort(out,len,sizeof(int),cmpfunc);
	if((out[0]==out[k-1])&&(k == len))
	{
		printf("%s\n",s);
		return 0;
	}

	for(i=0;i<len;i++)
	{
		if(out[i] == out[i+k-1])
		{
			i = i+k-1;
			//printf("%d\n",i);
		}
		else
		{
			printf("-1\n");
			return 0;
		}
	}
	for(i=0;i<k;i++)
	{
		for(t=0;t<len;t+=(k))
		{
			printf("%c",out[t]);
		}
	}
	printf("\n");
	return 0;
}
