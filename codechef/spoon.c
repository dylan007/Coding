#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int i,j,t,r,c,flag=0;
		scanf("%d %d%*C",&r,&c);
		char matr[100][101];
		for(i=0;i<r;i++)
		{
			for(j=0;j<=c;j++)
			{
				scanf("%c",&matr[i][j]);
				t = matr[i][j];
				if(t>=65 && t<=90)
					t += 32;
				matr[i][j] = t;
			}
		}
		for(i=0;i<r;i++)
		{
			for(j=0;j<=c;j++)
				printf("%c",matr[i][j]);
		}
		for(i=0;i<r;i++)
		{
			for(j=0;j<=c;j++)
			{
				if((matr[i][j]=='s')&&(j+4 <= c))
				{
					if((matr[i][j+1]=='p')&&(matr[i][j+2]=='o')&&(matr[i][j+3]=='o')&&(matr[i][j+4]=='n'))	
						flag = 1;
				}
				if(flag) break;
			}
			if(flag) break;
			if((matr[i][j]=='s')&&(i+4 < r))
			{
				if((matr[i][j+1]=='p')&&(matr[i][j+2]=='o')&&(matr[i][j+3]=='o')&&(matr[i][j+4]=='n'))
					flag=1;
			}
			if(flag) break;
		}
		if(flag)
			printf("There is a spoon!\n");
		else
			printf("There is indeed no spoon!\n");
	}
	return 0;
}
