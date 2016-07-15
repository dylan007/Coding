#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmpfunc(const void *a, const void *b)
{
	return *(int *)b - *(int *)a;
}

int main()
{
	char str[1000];
	scanf("%s",str);
	int len,t,i,j=0,c=0;
	len = strlen(str)-1;
	int a[1000] = {0};
	printf("%d\n",len);
	for(i=1;i<(len-1);i+=3)
	{
		t = str[i];
		printf("%d\n",t);
		a[j] = t;
		j++;
	}
	qsort(a,j,sizeof(int),cmpfunc);
	for(i=0;i<j;i++) printf("%d\t",a[i]);
	t = a[0];
	c = 1;
	for(i=1;i<=j;i++)
	{
		if(t != a[i])
		{
			c++;
			t = a[i];
		}
	}
	printf("%d\n",c);
	return 0;
}
