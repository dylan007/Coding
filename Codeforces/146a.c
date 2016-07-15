#include<stdio.h>
#include<stdlib.h>

int main()
{
	char str[50],c;
	int n,i,sum1=0,sum2=0;
	scanf("%d",&n);
	scanf("%s",str);
	for(i=0;i<n;i++)
	{
		c = str[i];
		if((c == '7')||(c == '4'))
		{
			if(i<(n/2))
				sum1 += c - '0';
			
			else
				sum2 += c - '0';
		}
		else
		{
			printf("NO\n");
			return 0;
		}
	}
	if(sum1 == sum2)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
