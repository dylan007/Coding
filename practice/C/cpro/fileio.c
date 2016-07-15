#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	FILE *fp;
	char buffer[255];
	fp = fopen("./test.c","r");
	while(fgets(buffer,sizeof(buffer),fp)!=NULL)
		printf("%s",buffer);
	return 0;
}
