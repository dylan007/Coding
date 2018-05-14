#include <stdio.h>
#include <math.h>

int main()
{

	int a,b;
	int  i,j;
	int flag;
	double x1,y1;
	scanf("%d%d",&a,&b);
	for(i=1;i<a;i++)
	{
		x1=sqrt(a*a-i*i);
		if(x1-(int)x1<0.00000001)
			for(j=1;j<b;j++)
			{	y1=sqrt(b*b-j*j);
				if(y1-(int)y1<0.00000001)
					if(i!=j) { 				
						if(i*j-(int)y1*(int)x1==0) 
						{
							printf("YES\n");
							printf("0 0\n%.lf %d\n%.lf %d\n",x1,i,-y1,j);
							return 0;
						}
					}
			}
	}
	printf("NO\n");
}


