#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>

int main()
{
	int n,s;	
	int x,y;
	scanf("%d %d",&n,&s);
	int min=INT_MAX;
	int f1=0,f2=0;
	while(n--)
	{
		scanf("%d %d",&x,&y);
		if(!(x>s || (x==s && y>0)))
		{
			if(y!=0)
			{
				min = min<y?min:y;
				f2=1;
			}
			f1=1;
		}
	}
	if(f1==0)
		printf("-1\n");
	else
	{
		if(f2==0)
			printf("0\n");
		else
			printf("%d\n",100-min);
	}
	return 0;
}
