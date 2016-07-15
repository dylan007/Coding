#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int cmpfunc(const void *a,const void *b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
	int a,b,c,pos[6];
	scanf("%d %d %d",&a,&b,&c);
	{
		pos[0]=a+b+c;
		pos[1] = a+(b*c);
		pos[2] = a*b + c;
		pos[3] = a*(b+c);
		pos[4] = (a+b)*c;
		pos[5] = a*b*c;
		qsort(pos,6,sizeof(int),cmpfunc);
		printf("%d\n",pos[5]);
	}
	return 0;
}
