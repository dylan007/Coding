#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int count[10]={2,7,2,3,3,4,2,5,1,2};

int main()
{
	int n;
	char str[5];
	scanf("%s",str);
	int ans=1,i=0;
	while(i<2)
	{
		ans *= count[str[i++]-'0'];
		n /= 10;
	}
	printf("%d\n",ans);
	return 0;
}
