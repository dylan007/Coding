#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char s[5],t[5];
	scanf("%s%*C%s",s,t);
	int h1,h2,m1,m2,H,M;
	h1 = (s[0] - '0')*10 + (s[1] - '0');
	h2 = (t[0] - '0')*10 + (t[1] - '0');
	m1 = (s[3] - '0')*10 + (s[4] - '0');
	m2 = (t[3] - '0')*10 + (t[4] - '0');
	if(m1 >= m2)
		M = m1 - m2;
	else
	{
		M = 60 + m1 - m2;
		h2 += 1;
	}
	if(h1 >= h2)
		H = h1 - h2;
	else
		H = 24 + h1 - h2;
	printf("%d%d:%d%d\n",(H/10),H%10,M/10,M%10);
	return 0;
}
