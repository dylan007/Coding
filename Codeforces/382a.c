#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char wgt[60],extra[60];
	scanf("%s%*C%s",wgt,extra);
	int j,ext,i,len,left,right;
	j = len = strlen(wgt);
	ext = strlen(extra);
	for(i=0;i<len;i++)
	{
		if(wgt[i] == '|')
		{
			left = i;
			break;
		}
	}
	right = len -left - 1;
	if(!(((right+left+ext)%2 == 0)&&(right+ext>=left)&&(left+ext>=right)))
		printf("Impossible\n");
	else
	{
		int t = (left+right+ext)/2;
		j=0;
		for(j=0;j<(t-left);j++)
			printf("%c",extra[j]);
		for(i=0;i<left;i++)
			printf("%c",wgt[i]);
		putchar('|');
		for(i++;i<len;i++)
			printf("%c",wgt[i]);
		for(j;j<ext;j++)
			printf("%c",extra[j]);
		printf("\n");
	}
	/*if(!((right+left+ext)%2 == 0 )||( left+ext < right )||( right+ext < left))
		printf("Impossible\n");
	else
	{
		len = (left + right + ext)/2;
		for(i=0;i<(len - left);i++) printf("%c",extra[i]);
		for(i=0;i<left+1;i++) printf("%c",wgt[i]);
		printf("|");
		for(i=left+2;i<j;i++)	printf("%c",wgt[i]);
		for(i=len-left;i<ext;i++)	printf("%c",extra[i]);
		printf("\n");
	}*/
	
	return 0;
}
