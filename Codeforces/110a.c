#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int checklucky(int n)
{
	if(n == 0)
		return 0;
	while(n)
	{
		if((n%10 != 4)&&(n%10 != 7))
			return 0;
		else
			n /= 10;
	}
	return 1;
}

int main()
{
	char c;
	int t,i=0,count=0;
	while((c=getchar())!='\n')
	{
		if((c == '4')||(c == '7'))
			count++;
		i++;
	}
	
	if(checklucky(count))
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}
