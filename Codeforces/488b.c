#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int cmpfunc(const void *a,const void *b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
	int n;
	scanf("%d",&n);
	int a[4];
	int i,sum=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	qsort(a,n,sizeof(int),cmpfunc);
	switch(n)
	{
		case 0:
			printf("YES\n1\n1\n3\n3\n");
			break;
		case 1:
			printf("YES\n%d\n%d\n%d\n",a[0],3*a[0],3*a[0]);
			break;
		case 2:
			if(3*a[0]>=a[1])
				printf("YES\n%d\n%d\n",4*a[0]-a[1],3*a[0]);
			else 
				printf("NO\n");
			break;
		case 3:
			if(3*a[0]>=a[2])
				printf("YES\n%d\n",3*a[0]);
			else
				printf("NO\n");
			break;
		case 4:
			if((a[3]-a[0] == sum/4)&&(sum/4 == (a[1]+a[2])/2))
				printf("YES\n");
			else
				printf("NO\n");
	}
	return 0;
}
