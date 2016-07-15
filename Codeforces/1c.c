#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>


int main()
{
	double x1,x2,x3,y1,y2,y3;
	scanf("%lf %lf %lf %lf %lf %lf",&x1,&x2,&x3,&y1,&y2,&y3);
	double area;
	area = fabs((x1-x3)*(y2-y1) - (x1-x2)*(y3-y1));
	printf("%.6lf\n",area);
	return 0;
}
