#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int a[100000];
int n;

int count(int x)
{
	int i,count=0;
	for(i=1;i<=x;i++)
	{
		if(check(i,x/i) && (x%i == 0))
			count++;
	}
	return count;
}	

int check(int s,int t)
{
	int i,c1=0,c2=0,s1=0,s2=0;
	for(i=0;i<n;i++)
	{
		c1 += (a[i]==1);
		c2 += (a[i]==2);
		if(c2==t)
		{
			s2++;
			c1 = c2 = 0;
		}
		else if(c1==t)
		{
			s1++;
			c1=c2=0;
		}
		printf("%d %d %d %d %d\n",a[i],c1,c2,s1,s2);
	}
	if(s1>=s || s2>=s)
		return 1;
	else
		return 0;
}

int main()
{
	int x;
	scanf("%d",&n);
	int i;
	int count1=0,count2=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		count1 += (x==1);
		count2 += (x==2);
		a[i]=x;
	}
	int max;
	max = count1>count2?count1:count2;
	printf("%d\n",check(5,3));
	/*if(count1==count2)
		printf("0\n");
	else
	{
		printf("%d\n",count(max));
		for(i=1;i<=max;i++)
		{
			if((max%i == 0) && check(i,max/i)==1)
				printf("%d %d\n",i,max/i);
		}
	}*/
	return 0;
}
