#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{	
	int x,n,sum1=0,sum2=0;
	scanf("%d",&n);
	int pos[n],neg[n],lp=0,ln=0;
	n--;
	int type=0;
	scanf("%d",&x);
	type = (x<0)?1:2;
	if(x<0)
	{
		neg[ln++]=-x;
		sum2-=x;
	}
	else
	{
		pos[lp++]=x;
		sum1+=x;
	}
	while(n--)
	{
		scanf("%d",&x);
		if(x<0)
		{
			sum2-=x;
			x = 0-x;
			ln++;
			neg[ln-1]=x;
			x = 0-x;
		}
		else
		{
			sum1+=x;
			lp++;
			pos[lp-1]=x;
		}
	}
	//printf("%d %d %d\n",sum1,sum2,type);
	int i,f=0;
	if(sum1>sum2)
	{
		if(type==2)
			printf("first\n");
		else
			printf("second\n");
	}
	else if(sum1<sum2)
	{
		if(type==1)
			printf("first\n");
		else
			printf("second\n");
	}
	else
	{
		/*if(lp>ln)
		{
			if(type==2)
				printf("first\n");
			else
				printf("second\n");
		}
		else if(lp<ln)
		{
			if(type==1)
			printf("first\n");
			else
			printf("second\n");
			}
			else
			{
		 */
		for(i=0;i<lp;i++)
			printf("%d\n",pos[i]);
		for(i=0;i<ln;i++)
			printf("%d\n",neg[i]);
		int MAX;
		MAX = lp>ln?ln:lp;
		f=0;
		for(i=0;i<MAX;i++)
		{
			if(pos[i]>neg[i])
				f=2;
			else if(pos[i]<neg[i])
				f=1;
			if(f!=0)
				break;
		}

		if(f==1)
		{
			if(type==1)
				printf("first\n");
			else
				printf("second\n");
		}
		else if(f==2)
		{
			if(type==2)
				printf("first\n");
			else
				printf("second\n");
		}
		else if(f==0)
		{
			if(x<0)
			{
				if(type==1)
					printf("first\n");
				else
					printf("second\n");
			}
			else
			{
				if(type==2)
					printf("first\n");
				else
					printf("second\n");
			}
		}
	}
	return 0;
}
