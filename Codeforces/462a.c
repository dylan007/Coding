#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	int n;
	scanf("%d%*C",&n);
	char inp[n+1][n+1];
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%c",&inp[i][j]);
			inp[i+1][j]='a';
		}
		inp[i][j]='a';
		getchar();
	}
	int f=1,temp=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			temp = (inp[i+1][j]=='o') + (inp[i-1][j]=='o') + (inp[i][j+1]=='o') + (inp[i][j-1]=='o');
			if(temp%2 != 0)
				f=0;
			if(f==0)
				break;
		}
		if(f==0)
			break;
	}
	if(f==0)
		printf("NO\n");
	else
		printf("YES\n");
	return 0;
}
