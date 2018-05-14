#include <stdio.h>
 
int main(void) {
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		if(a==b || a-b==2)
		{
			if(a%2==1)
				printf("%d\n",a+b-1);
			else
				printf("%d\n",a+b);
		}
		else
			printf("No Number\n");
	}
	return 0;
} 

