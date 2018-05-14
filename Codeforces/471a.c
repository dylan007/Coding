#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>

int cmpfunc(const void *a,const void *b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
	int l[6];
	int i;
	for(i=0;i<6;i++)
		scanf("%d",&l[i]);
	qsort(l,6,sizeof(int),cmpfunc);
	int count=1,temp=0,max=0,leg;
	temp = l[0];
	for(i=1;i<6;i++)
	{
		if(temp==l[i])
			count++;
		else 
		{
			if(count>=4)
				leg = l[i-1];
			max = max>count?max:count;
			count=1;
			temp = l[i];
		}
	}
	max = max>count?max:count;
	if(max<4)
		printf("Alien\n");
	else
	{
		i=0;
		while(l[i]!=leg)
			i++;
		int head,body;
		switch(i)
		{
			case 0:
				head = l[4]<=l[5]?l[4]:l[5];
				body = l[4]>=l[5]?l[4]:l[5];
				break;
			case 1:
				head = l[0]<=l[5]?l[0]:l[5];
				body = l[0]>=l[5]?l[0]:l[5];
				break;
			case 2:
				head = l[0]<=l[1]?l[0]:l[1];
				body = l[0]>=l[1]?l[0]:l[1];
				break;
		}
		if(head==body)
			printf("Elephant\n");
		else
			printf("Bear\n");
	}
	return 0;
}
