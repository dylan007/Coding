#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct top
{
	int Side;
	int number;
	int Time;
}top;

int main()
{
	char home[30],away[30];
	scanf("%s %s%*C",home,away);
	int T,count1=0,count2=0;
	char status1[100],status2[100];
	scanf("%d",&T);
	top ans[90];
	int top=0;
	memset(status1,'a',100);
	memset(status2,'a',100);
	while(T--)
	{
		int time,num;
		char side,card;
		scanf("%d %c %d %c",&time,&side,&num,&card);
		if(side=='a')
		{
			count2++;
			if(card=='r' && status2[num-1]!='r')
			{
				if(side=='h')
					ans[top].Side = 1;
				else
					ans[top].Side = 2;
				ans[top].number = num;
				ans[top].Time = time;
				top++;
				status2[num-1] = 'r';
			}
			else if(card=='y' && status2[num-1]!='r')
			{
				if(status2[num-1]=='y')
				{
					ans[top].Side = (side=='h')?1:2;
					ans[top].number = num;
					ans[top].Time= time;
					top++;
					status2[num-1] = 'r';
				}
				else if(status2[num-1] == 'a')
					status2[num-1] = 'y';
			}
		}
		else
		{
			count1++;
			if(card=='r' && status1[num-1]!='r')
			{
				ans[top].Side = (side=='h')?1:2;
				ans[top].number = num;
				ans[top].Time= time;
				top++;
				status1[num-1] = 'r';
			}	
			else if(card=='y')
			{
				if(status1[num-1]=='y')
				{
					ans[top].Side = (side=='h')?1:2;
					ans[top].number = num;
					ans[top].Time= time;
					top++;
					status1[num-1] = 'r';
				}
				else if(status1[num-1]=='a')
					status1[num-1] = 'y';
			}
		}
	}
	int i;
	for(i=0;i<top;i++)
	{
		if(ans[i].Side == 1)
			printf("%s %d %d\n",home,ans[i].number,ans[i].Time);
		else
			printf("%s %d %d\n",away,ans[i].number,ans[i].Time);
	}
	return 0;
}
