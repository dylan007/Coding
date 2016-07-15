#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	char a[n][110];
	int x;
	char temp[110];
	int front,rear;
	front = -1;
	rear=-1;
	char inp[10];
	scanf("%[^\n]s",inp);
	getchar();
	char check[2];
	check[0] = 'Q';
	check[1] = '\0';
	int i,j=0,flag=1;
	while(strcmp(inp,check)!=0)
	{
		switch(inp[0])
		{
			case 'A':
				x = inp[2]-'0';
				flag=0;
				while(x>0)
				{
					scanf("%s",temp);
					getchar();
					if(front==-1)
					{
						front++;rear++;
						strcpy(a[front],temp);
					}
					else
					{
						front = (front+1)%n;
						strcpy(a[front],temp);
						//printf("%s\n",a[front]);
						if(front==(rear))
							rear++;
					}
					x--;
				}
				break;
			case 'R':
				x = inp[2]-'0';
				while(x>0)
				{
					if(flag==1)
					{
						rear=front=-1;
						break;
					}
					else{
					rear = (rear+1)%n;
					if(rear==(front))
					{flag=1;
					}
					}
					x--;
				}
				break;
			case 'L':
		//		if(front==-1)
		//			printf("\n");
				/*else*/ if(front>=rear && front!=-1)
				{
					for(i=rear;i<=front;i++)
						printf("%s\n",a[i]);
				}
				else if(front < rear)
				{
					for(i=rear;i<n;i++)
						printf("%s\n",a[i]);
					for(i=0;i<=front;i++)
						printf("%s\n",a[i]);
				}
				break;
		}
		scanf("%[^\n]s",inp);
		getchar();
	}	
	return 0;
}
