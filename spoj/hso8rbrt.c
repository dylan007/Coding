#include<stdio.h>
#include<stdlib.h>

int main()
{
	float t=0,loan,capital;
	int n=50,ans=0;
	scanf("%f",&loan);
	capital = 0.02*loan;
	while(n--)
	{
		t = (float)ans + capital + 0.01*loan;
		if((int)t == t)
			ans += (int)t;
		else
			ans += (int)t +1;
		loan = loan - capital;
		printf("%f %f %d\n",t,capital,(int)t);
	}
	printf("%d\n",ans);
	return 0;
}
