#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char str1[100],str2[100];
	scanf("%s%s",str1,str2);
	int len,i,t,val1=0,val2=0;
	len = strlen(str1);
	for(i=0;i<len;i++)
	{
		t = str1[i];
		if((t>=65)&&(t<=90))
		{
			t += 32;
			str1[i]=t;
		}
		val1 += t;
		t = str2[i];
		if((t>=65)&&(t<=90))
		{
			t += 32;
			str2[i] = t;
		}
		val2 += t;
		if(val2>val1)
		{
			printf("-1\n");
			return 0;
		}
		else if(val1>val2)
		{
			printf("1\n");
			return 0;
		}
	}	
	printf("0\n");
	return 0;
}
