#include<stdio.h>
#include<string.h>
char temp[1000];

int next()
{
	int len,i;
	char t;
	len = strlen(temp);
	for(i=len-1;i>=0;i--)
	{
		if(temp[i]>temp[i-1])
		{
			t = temp[i-1];
			temp[i-1] = temp[i];
			temp[i]=t;
			return 1;
		}
	}
	return -1;
}

int main()
{
	scanf("%s",temp);
	while(next()!=-1)
		printf("%s\n",temp);
	return 0;
}
