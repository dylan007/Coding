#include<stdio.h>
#include<stdlib.h>
int main()
{
	int x,i,n,t;
	int a[3] = {0};
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		switch(i%3)
		{
			case 0:
				a[0] += x;
				break;

			case 1:
				a[1] +=x;
				break;

			case 2:
				a[2] += x;
				break;
		}
	}
	x=0;
	for(i=0;i<3;i++)
	{
		if(a[i]>x)
		{
			x = a[i];
			t = i;
		}
	}
	switch(t)
	{
		case 0:
			printf("chest\n");
			break;
		case 1:
			printf("biceps\n");
			break;
		case 2:
			printf("back\n");
			break;
	}

	return 0;
}
