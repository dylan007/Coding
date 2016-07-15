#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int cmpfunc(const void *a, const void *b)
{
	return *(double *)a - *(double *)b;
}

int main()
{
	int n,i;
	double d;
	scanf("%d %lf",&n,&d);
	double pos[n];
	for(i=0;i<n;i++)
		scanf("%lf",&pos[i]);
	qsort(pos,n,sizeof(double),cmpfunc);
	/*for(i=0;i<n;i++)
		printf("%lf ",pos[i]);
	printf("\n");*/
	double t,max=0;
	max = pos[0];
	for(i=1;i<n;i++)
	{
		t = pos[i]-pos[i-1];
		t/=2;
		max = max>t?max:t;
	}
	max = (max > (d-pos[n-1]))?max:(d-pos[n-1]);
	printf("%lf\n",max);
	return 0;
}
