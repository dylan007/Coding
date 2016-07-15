#include<bits/stdc++.h>

using namespace std;

string maze[500],temp[500];
int n,m,k;
int MAX=0;

void dfs(int x,int y,int time)
{
	MAX = MAX>time?MAX:time;
	if(temp[x][y]=='#')
		return;
	if(x<0 || y>=m || y<0 || x>=m)
		return;
	if(temp[x][y]!='.')
		return;
	int TEMP;
	TEMP = time+48;
	temp[x][y] = char(TEMP);
	dfs(x+1,y,time+1);
	dfs(x-1,y,time+1);
	dfs(x,y+1,time+1);
	dfs(x,y-1,time+1);
}

int main()
{
	cin >> n >> m >> k;
	for(int i=0;i<n;i++)
	{
		cin >> maze[i];
		temp[i] = maze[i];
	}
	int f=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(maze[i][j]=='.')
			{
				dfs(i,j,1);
				f=1;
				break;
			}
		}
		if(f==1)
			break;
	}
	while(k>0)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(temp[i][j]-'0' == MAX)
				{
					maze[i][j] = 'X';
					k--;
				}
			}
		}
		MAX--;
	}
	for(int i=0;i<n;i++)
		cout << maze[i] << endl;
	return 0;
}
