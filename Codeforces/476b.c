#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	char str1[20],str2[20];
	scanf("%s",str1);
	scanf("%s",str2);
	int i,pos=0,count=0;
	for(i=0;i<strlen(str1);i++)
	{
		pos += (str1[i]=='+')?1:-1;
		count += (str2[i]=='?');
	}
	int index[count],top=0;
	for(i=0;i<strlen(str1);i++)
	{
		if(str2[i]=='?')
			index[top++]=i;
	}
	char copy[20];
	int j=0,ans=0,POS=0;
	for(i=0;i<pow(2,count);i++)
	{
		POS=0;
		strcpy(copy,str2);
		int t;
		t = i;
		for(j=0;j<strlen(str2);j++)
		{
			if(str2[j]=='+')
				POS++;
			else if(str2[j]=='-')
				POS--;
			else
			{
				if(t%2 == 0)
					POS++;
				else
					POS--;
				t/=2;
			}
		}
		if(POS==pos)
			ans++;
	}
	if(count>0)
	{
		double a,b;
		a = ans;
		b = pow(2,count);
		printf("%.9lf\n",a/b);
	}
	else
	{
		double a;
		a = 1;
		if(POS==pos)
			printf("%.9lf\n",a);
		else
			printf("%.9lf\n",a-1);
	}	
	return 0;
}
