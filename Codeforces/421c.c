#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXN 100100

int n,m;
int flag[MAXN];
int match[MAXN];
int s1[MAXN],s[MAXN*2][2],top,top1;
int a[MAXN],b[MAXN];
char str[10];
int i,j,k;

int judge()
{
	int num=0;
	int i,j,k;
	for(i=1;i<=top;i++)
	{
		j=s[i][0];
		k=s[i][1];
		if((match[j]==1 && k==1) || (match[j]==0) && k==0) return 0;
		if(match[j]==1)
		{
			num--;
			match[j]=0;
		}
		else{
			num++;
			match[j]=1;
		}
		if(j==s[1][0] && k==0)
		{
			if(num>0) return 0;
			if(i<top && s[i+1][0]!=s[1][0]) return 0;
		}
	}
	return 1;
}
void print_ans()
{
	int i,j,k;
	int ans=0;
	j=0;
	for(i=1;i<=n;i++)
		if(flag[i]==0)
		{
			ans++;
			j=i;
		}
	printf("%d\n",ans);
	for(i=1;i<=n;i++)
		if(flag[i]==0)
		{
			printf("%d",i);
			if(i==j) putchar('\n');
			else putchar(' ');
		}
}

int main()
{
	scanf("%d%d",&n,&m);
	//ans=n;
	top1=0;
	for(i=1;i<=m;i++)
	{
		scanf("%s%d",str,&a[i]);
		if(str[0]=='-') b[i]=0;
		else b[i]=1;
		if(flag[a[i]]==0)
		{
			flag[a[i]]=1;
			//ans--;
			if(b[i]==0)
			{
				top1++;
				s1[top1]=a[i];
			}
		}
	}
	top=0;
	while(top1>0)
	{
		top++;
		s[top][0]=s1[top1];
		s[top][1]=1;
		top1--;
	}
	for(i=1;i<=m;i++)
	{
		top++;
		s[top][0]=a[i];
		s[top][1]=b[i];
	}
	/*
	   for(i=1;i<=top1;i++) printf("%d ",s1[i]);
	   putchar('\n');
	   for(i=1;i<=top;i++) printf("%d ",s[i][0]);
	   putchar('\n');
	 */
	if(judge()==1) flag[s[1][0]]=0;
	print_ans();
	return 0;
}
