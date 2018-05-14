#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int a[1000000];
int f=0;

void print(int k)
{
	int i;
	for(i=0;i<k;i++)
		printf("%d ",a[i]);
	printf("\n");
}

void next_perm(int n,int k)
{
	int i;
	for(i=(k-1);i>=0;i--)
	{
		if(a[i]<n) 
			break;
	}
	a[i]++;
	int j;
	for(j=i+1;j<k;j++)
		a[j] = a[i];
	if(a[0]==n && a[k-1]==n)
		f=1;
}

int main()
{
	//int T;
	//scanf("%d",&T);
	//while(T--)
	{
		int n,k,i,count=1;
		scanf("%d %d",&n,&k);
		for(i=0;i<k;i++)
			a[i]=1;
		if(n==1)
		{
			printf("1\n");
			print(k);
		}
		else
		{
			count=1;
			f=0;
			while(f!=1)
			{
				count++;
				next_perm(n,k);
			}
			printf("%d\n",count);
			f=0;
			for(i=0;i<k;i++)
				a[i]=1;
			while(f!=1)
			{
				print(k);
				next_perm(n,k);
			}
			for(i=0;i<k;i++)
				printf("%d ",n);
			printf("\n");	
		}
	}
	return 0;
}
