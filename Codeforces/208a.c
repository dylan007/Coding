#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char dub[200],out[200];
	int len,i,j=0,start=0,count=0,flag=1;
	scanf("%s",dub);
	len = strlen(dub);
	//printf("%d\n",len);
	for(i=0;i<(len);i++)
	{
		if((dub[i]=='W')&&(dub[i+1]=='U')&&(dub[i+2]=='B'))
		{
			out[j] = ' ';
			i = i+2;
			//printf("i = %d out[i] = %c\n",j,out[j]);
			j++;
		}
		else
		{
			out[j] = dub[i];
			if(flag)
			{
				start = j;
				flag = 0;
			}
			//printf("i = %d out[i] = %c\n",j,out[j]);
			j++;
		}
	}
	len = j;
	for(i=start;i<len;i++)
	{
		if(out[i] != ' ')
		{
			printf("%c",out[i]);
			count=0;
		}
		else
		{
			if(count==0)
			{
				printf(" ");
				count++;
			}
		}
	}
	printf("\n");
	return 0;
}
