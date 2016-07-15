#include<stdio.h>
#include<stdlib.h>

int cmpfunc(const void *a,const void *b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
	char c[15];
	int a[600010] = {0};
	int i=0,n=0,t;
	t = scanf("%s%*C",c);
	while(!feof(stdin))
	{
		if(c[0] != '#')
		{
			a[i] = atoi(c);
			i++;
		}
		else
		{
			qsort(a,i,sizeof(int),cmpfunc);

			if(i%2 == 0)
			{
				printf("%d\n",a[(i/2)]);
				a[(i/2)] = a[i-1];
				i--;
			}
			else
			{
				printf("%d\n",a[(i-1)/2]);
				a[(i-1)/2] = a[i-1];
				i--;	
			}
		}
		t = scanf("%s",c);
	}
}
