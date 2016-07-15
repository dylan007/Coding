#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int T;
	scanf("%d\n\n",&T);
	while(T--)
	{
		char c;
		long long int f=0;
		long long int temp1=0,temp2=0;
		while(c!='=')
		{
			c = getchar();
			if(f==0)
			{
				if((c=='+')||(c=='-')||(c=='*')||(c=='/'))
				{
					f=1;
					temp2 = temp1;
				}
				else if(c!=' ')
					temp1 = temp1*10 + (c-'0');
			}
			else if(c!=' ')
			{
				if((c=='+')||(c=='/')||(c=='*')||(c=='-'))
				{
					switch(c)
					{
						case '+':
							temp2 += temp1;
							break;
						case '-':
							temp2 = temp1-temp2;
							break;
						case '/':
							temp2 = temp1/temp2;
							break;
						case '*':
							temp2 *= temp1;
							break;
					}
					temp1=0;
				}
				else
					temp1 = temp1*10+ (c-'0');
			}
			printf("%c %lld %lld\n",c,temp1,temp2);
		}
		printf("%lld\n",temp2);
	}
	return 0;
}
