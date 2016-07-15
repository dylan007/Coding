#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int main()
{
	char str[100];
	scanf("%s",str);
	int len=strlen(str);
	int i,tmpc;
	for(i=0;i<len;i++)
	{
		if((str[i]=='y')||(str[i]=='Y')||(str[i]=='a')||(str[i]=='e')||(str[i]=='i')||(str[i]=='o')||(str[i]=='u')||(str[i]=='A')||(str[i]=='E')||(str[i]=='I')||(str[i]=='O')||(str[i]=='U'))
		{
			str[i]='\0';
		}
	}
	for(i=0;i<len;i++)
	{
		tmpc=str[i];
		if((tmpc>64)&&(tmpc<91))
		{
			tmpc=tmpc+32;
		}
		str[i]=tmpc;    
	}
	len= len*2;

	for(i=0;i<len;i++)
	{
		tmpc=str[(i/2)];
		if(tmpc!=0)
		{
			if((i%2)==0)
				printf(".");
			else
			{
				printf("%c",str[(i/2)]); 
			}
		}   
	}
	printf("\n");
	return 0;
}
