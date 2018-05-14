#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char temp[100][110],tab[100][110];
int n,m;

int pos(int j)
{
	int i;
	for(i=0;i<m;i++)
	{
		if(tab[j][i]<tab[j-1][i])
			return i;
	}
}

void copy(int k)
{
	int i,j,top=0;
	for(i=0;i<n;i++)
	{
		top=0;
		for(j=0;j<m;j++)
		{
			if(j!=k)
				temp[i][top++] = tab[i][j];
		}
		temp[i][top] = '\0';
	}
	for(i=0;i<n;i++)
		strcpy(tab[i],temp[i]);
}

int check()
{
	int i;
	for(i=1;i<n;i++)
	{
		if(strcmp(tab[i],tab[i-1])<0)
			return 0;
	}
	return 1;
}

int main()
{
	scanf("%d %d%*C",&n,&m);
	int i;
	for(i=0;i<n;i++)
		scanf("%[^\n]%*C",tab[i]);
	int j,t,count=0;
	while(check()!=1)
	{
		int f=0;
		for(j=1;j<n;j++)
		{
			if(strcmp(tab[j],tab[j-1])<0)
				break;
		}
		t = pos(j);
		copy(t);
		count++;
	}
	printf("%d\n",count);
	return 0;
}
