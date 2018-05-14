#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int cmpfunc(const void *a,const void *b)
{
	return *(int *)b - *(int *)a;
}

int main()
{
	int i,n,k;
	scanf("%d %d%*C",&n,&k);
	int occur[26];
	char c,string[1000000];
	for(i=0;i<26;i++)
		occur[i]=0;
	i=0;
	scanf("%s",string);
	for(i=0;i<n;i++)
	{
		c = string[i];
		occur[c-'A']++;
	}
	qsort(occur,26,sizeof(int),cmpfunc);
	int sum=0,top=0;
	while(k>=0)
	{
		if(k>=occur[top])
		{
			k -= occur[top];
			sum += occur[top]*occur[top];	
		}
		else
		{
			sum += k*k;
			k=0;
			break;
		}
	}
	printf("%d\n",sum);
}
