#include<stdio.h>
#include<stdlib.h>

int check(int a,int b,int c)
{
	return ((a>(b+c))||(b>(a+c))||(c>(b+a)));
}

int cmpfunc(const void *a,const void *b)
{
	return *(int *)a - *(int *)b;
}

#define NL printf("\n");

int main()
{
	int N;
	scanf("%d",&N);
	while(N != 0)
	{
		int j,k,i,a[N],c=0,l=0,r;
		for(i=0;i<N;i++)
			scanf("%d",&a[i]);
		qsort(a,N,sizeof(int),cmpfunc);
		for(i=N-1;i>=2;i--)
		{
			l=0;
			r = i-1;
			while(l<r)
			{
				if(a[l]+a[r]<a[i])
				{
					c += r-l; 
					l++;
				}
				else
					r--;
			}
		}
		printf("%d",c);
		NL;
		scanf("%d",&N);
	}
	return 0;
}
