#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>

int can(int m,int s)
{
	return s>=0 && s<=9 *m;
}

int main()
{
	int m,s;
	scanf("%d %d",&m,&s);
	int i,d,sum;
	sum=s;
	char out1[1000];
	int top=0;
	if(m==1 && s==0)
	{
		printf("0 0\n");
		return 0;
	}
	else if(9*m<s || s==0)
	{
		printf("-1 -1\n");
		return 0;
	}
	for(i=0;i<m;i++)
	{
		for(d=0;d<10;d++)
		{
			if(((i>0 || d>0) || (m==1 && d==0)) && (can(m-i-1,sum-d)))
			{
				printf("%d",d);
				sum-=d;
				break;
			}
		}
	}
	//out1[top+1]='\0';
	//printf("%s ",out1);
	top=0;
	sum=s;
	printf(" ");
	char out2[1000];
	for(i=0;i<m;i++)
	{
		for(d=9;d>=0;d--)
		{
			if(((i>0 || d>0) || (m==1 && d==0)) && (can(m-i-1,sum-d)))
			{
				printf("%d",d);
				sum-=d;
				break;
			}
		}
	}
	//out2[top+1]='\0';
	return 0;
}
