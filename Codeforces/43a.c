#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int n;
	scanf("%d",&n);
	char s[13],a[13],b[13],t1=0,t2=0;
	if(n == 1)
	{
		scanf("%s",s);
		printf("%s\n",s);
		return 0;
	}
	scanf("%s",s);
	strcpy(a,s);	
	t1 = 1;
	n -= 1;
	while(n--)
	{
		scanf("%s",s);
		if(!strcmp(a,s))
			t1++;
		else
		{
			t2++;
			strcpy(b,s);
		}
	}

	if(t1>t2)
		printf("%s\n",a);
	else
		printf("%s\n",b);
	return 0;
}
