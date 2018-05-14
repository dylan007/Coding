#include<stdio.h>
#include<stdlib.h>

int cmpfunc(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int  main()
{
	int n,i,t,sum=0;
	char c;
	scanf("%d%*C",&n);
	int a[n],b[n],flag[100]={0};
	for(i=0;i<n;i++)
	{
		c = getchar();
		t = c - '0';
		a[i] = t;	
	}
	for(i=0;i<n;i++)
	{
		c = getchar();
		t = c - '0';
		b[i] = t;
	}
	qsort(a,n,sizeof(int),cmpfunc);
	qsort(b,n,sizeof(int),cmpfunc);
	for(i=0;i<n;i++)
	{
		if(a[i]>b[i])
			flag[i] = 1;
		else if(a[i]<b[i])
			flag[i] = 2;
		else 
		{
			printf("NO\n");
			return 0;
		}	
		sum += flag[i];
	}
	if(sum % n != 0)
		printf("NO\n");
	else
	{
		if((sum / n == 1)||(sum /n == 2))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
