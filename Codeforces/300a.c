#include<stdio.h>
#include<stdlib.h>

int cmpfunc(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
	int n,i,j;
	scanf("%d",&n);
	int a[n];
	int p[n],ap=0;
	int z[n],az=0;
	int ne[n],an=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]<0)
			ne[an++] = a[i];
		else if(a[i] == 0)
			z[az++] = a[i];
		else
			p[ap++] = a[i];
	}

	if(ap == 0)
	{
		p[ap++] = ne[an--];
		p[ap++] = ne[an--];
	}
	if(an%2 == 0)
		z[az++] = ne[an--];

	printf("%d ",an);
	for(i=0;i<an;i++)
		printf("%d ",ne[i]);

	printf("\n%d ",ap);
	for(i=0;i<ap;i++)
		printf("%d ",p[i]);

	printf("\n%d ",az);
	for(i=0;i<az;i++)
		printf("%d ",z[i]);
	printf("\n");

	return 0;
}
