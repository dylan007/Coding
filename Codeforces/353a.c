#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	scanf("%d",&n);
	int i,x,y,a=0,b=0,c=0;
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&x,&y);
		if((x%2 == 0)&&(y%2 == 0))
			continue;
		if((y%2 == 0))
			b++;
		else if((x%2 == 0))
			a++;
		else
			c++;
	}

	//printf("%d %d %d\n",a,b,c);

	if(((a+c)%2 == 0)&&((b+c)%2 == 0))
		puts("0");
	else if((a+c) % 2 + (b+c) % 2 == 1)
		puts("-1");
	else if((a>0)||(b>0))
		puts("1");
	else
		puts("-1");
	return 0;
}
