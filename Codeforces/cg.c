#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int n;
	printf("Enter the number of subjects: ");
	scanf("%d",&n);
	double sum=0,cred=0,x,y;
	while(n--)
	{
		scanf("%lf %lf",&x,&y);
		sum+=x*y;
		cred+=x;
	}
	printf("%lf\n",(sum/cred));
	return 0;
}
