#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int T;
	scanf("%d%*C",&T);
	char c,temp;
	while(T--)
	{
		c = getchar();
		temp = 'a';
		int count=0;
		while(c!='\n' || c!=EOF)
		{
			if(c=='\n' || c=='\0')
				break;
			if(c==temp)
				count++;
			else
				temp = c;
			//putchar(c);
			c = getchar();
		}
		
		printf("%d\n",count);
	}
	return 0;
}

