#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char str[100];
	scanf("%s",str);
	int t,upper=0,lower=0,len,i;
	len = strlen(str);
	for(i=0;i<len;i++)
	{
		t = str[i];
		if((t>=65)&&(t<=90))
			upper++;
		else if((t>=97)&&(t<=122))
			lower++;
	}
	if(lower>=upper)
	{
		for(i=0;i<len;i++)
		{
			t = str[i];
			if((t>=65)&&(t<=90))
			{
				t += 32;
				str[i] = t;
			}
		}
	}
	else
	{
		for(i=0;i<len;i++)
		{
			t = str[i];
			if((t>=97)&&(t<=122))
			{
				t -= 32;
				str[i] = t;
			}
		}
	}
	printf("%s\n",str);
	return 0;
}
