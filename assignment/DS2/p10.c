#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	char buff[n][200];
	char comm[20];
	char check[2];
	check[0]='Q';
	check[1]='\0';
	scanf("%[^\n]s",comm);
	getchar();
	int i,x;
	int front=0,rear=0,size=0;
	while(strcmp(comm,check)!=0)
	{
		printf("%s\n",comm);
		switch(comm[0])
		{
			case 'A':
				x = comm[2]-'0';
				char t[200];
				while(x--)
				{
					scanf("%s",t);
					getchar();
					strcpy(buff[front],t);
					size += (size<=n);
					front = (front+1)%n;
				}
				break;
			case 'R':
				x = comm[2]-'0';
				while(x--)
				{
					size -= (size>0);
					rear += (rear+1)%n;
				}
			case 'L':
				if(size>0)
				{
					if(rear<=front)
					{
						for(i=rear;i<front;i++)
							printf("%s\n",buff[i]);
					}
					else
					{
						for(i=rear;i<n;i++)
							printf("%s\n",buff[i]);
						for(i=0;i<front;i++)
							printf("%s\n",buff[i]);
					}
				}
		}
		scanf("%[^\n]s",comm);
		getchar();
	}
	return 0;
}
