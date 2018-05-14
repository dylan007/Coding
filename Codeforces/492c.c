#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef int (*compfun)(const void *, const void *);

typedef struct 
{
	int grade;
	int essays;
}subs;

int cmpfunc(subs *elem1,subs *elem2)
{
	if(elem1->essays < elem2->essays)
		return -1;
	else if(elem1->essays > elem2->essays)
		return 1;
	else
		return 0;
}

int main()
{
	int n,r,avg;
	scanf("%d %d %d",&n,&r,&avg);
	subs ans[n];
	int i,sum=0;
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&ans[i].grade,&ans[i].essays);
		sum += ans[i].grade;
	}
	qsort((void *)ans,n,sizeof(subs),(compfun)cmpfunc);
	/*for(i=0;i<n;i++)
		printf("%d %d\n",ans[i].grade,ans[i].essays);*/
	sum = (avg*n)-sum;
	if(sum<0)
	{
		printf("0\n");
		return 0;
	}
	int count=0;
	for(i=0;i<n;i++)
	{
		if(sum>(r-ans[i].grade))
		{
			count += ans[i].essays*(r-ans[i].grade);
			sum-=(r-ans[i].grade);
		}
		else
		{
			count += ans[i].essays*sum;
			break;	
		}
	}
	printf("%d\n",count);
	return 0;
}
