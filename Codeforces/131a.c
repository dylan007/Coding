#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char str[100];
	scanf("%s",str);
	int i,n,t,flag=1;
	n = strlen(str);
	for(i=1;i<n;i++)
	{
		t = str[i];
		if((t>=97)&&(t<=122))
		{
			flag = 0;
			break;
		}
	}
	if(flag)
	{
		for(i=1;i<n;i++)
		{
			t = str[i];
			t += 32;
			str[i] = t;
		}
		t = str[0];
		if((t>=97)&&(t<=122))
		{
			t -= 32;
			str[0]=t;
		}
		else
		{
			t += 32;
			str[0]=t;
		}
	}
	printf("%s\n",str);
	return 0;
}
