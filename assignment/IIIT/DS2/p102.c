#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int main()
{
	long long int size;
	scanf("%lld",&size);
	getchar();
	char buff[2*size][500];
	long long int front,rear;
	front = rear = -1;
	char temp[500];
	long long int flag=0;
	long long int i;
	char com[100];
	com[0]='\0';
	char check[100];
	check[0]='Q';
	check[1]='\0';
	long long int x;
	long long int loop;
	long long int length=0;
	while(strcmp(check,com)!=0)
	{
		scanf("%s",com);
		switch(com[0])
		{
			case 'A':
				scanf("%lld",&loop);
				while(loop--)
				{
					scanf("%s",temp);
					getchar();
					if(flag==0)
					{
						strcpy(buff[0],temp);
						front=0;
						rear=0;
						flag=1;
					}
					else
					{
						front = (front+1)%size;
						strcpy(buff[front],temp);
						if(front == rear)
							rear = (rear+1)%size;
					}
//					printf("rear = %d front = %d\n",rear,front);
					length += (length<size);
				}
				break;
			case 'L':
				if(length > 0)
				{
					if(rear<=front)
					{
						for(i=rear;i<=front;i++)
							printf("%s\n",buff[i]);
					}
					else
					{
						for(i=rear;i<size;i++)
							printf("%s\n",buff[i]);
						for(i=0;i<=front;i++)
							printf("%s\n",buff[i]);
					}
				}
				break;
			case 'R':
				scanf("%lld",&loop);
				getchar();
				while(loop--)
				{
					if(length > 0)
					{
						length--;
//						printf("%d\n",length);
						rear = (rear + 1)%size;
//						printf("rear = %d front = %d\n",rear,front);
						if(length == 0)
						{
							front = -1;
							rear = -1;
							flag=0;
						}
					}
					else
					{
						front = -1;
						rear = -1;
						flag = 0;
						break;
					}
				}
				break;
		}
	}
	return 0;
}
