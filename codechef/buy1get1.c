#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmpfunc(const void *a,const void *b)
{
	return ( *(int *)a - *(int *)b );
}

int main()
{
	int t,i;
	scanf("%d%*c",&t);
	for(i=0;i<t;i++)
	{
		char str[200];
		scanf("%s%*c",str);
		int len = strlen(str);
		int a[len],j,count=0;
		for(j=0;j<len;j++)
			a[j]=str[j];
		qsort(a,len,sizeof(int),cmpfunc);
		//for(j=0;j<len;j++)
		//	printf("%d ",a[j]);
		for(j=0;j<len;j++)
		{
			if(a[j]==a[j+1])
			{
				count++;
				j=j+1;
			}
			else
				count++;
		}
		printf("%d\n",count);
	}
	return 0;
}
