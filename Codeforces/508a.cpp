#include<bits/stdc++.h>

using namespace std;

int pixels[1000][1000];

int check(int x,int y)
{
	if(pixels[x][y]==1 && pixels[x-1][y-1]==1 && pixels[x-1][y]==1 && pixels[x][y-1]==1)
		return 1;
	if(pixels[x][y]==1 && pixels[x+1][y-1]==1 && pixels[x+1][y]==1 && pixels[x][y-1]==1)
		return 1;
	if(pixels[x][y]==1 && pixels[x-1][y]==1 && pixels[x-1][y+1]==1 && pixels[x][y+1]==1)
		return 1;
	if(pixels[x][y]==1 && pixels[x+1][y]==1 && pixels[x+1][y+1]==1 && pixels[x][y+1]==1)
		return 1;
	return 0;
}

int main()
{
	int n,m,k;
	cin >> n >> m >> k;
	for(int i=0;i<(n+1);i++)
	{
		for(int j=0;j<(m+1);j++)
			pixels[i][j]=0;
	}
	int f=0,x,y;
	if(n*m < 4)
	{
		cout << 0 << endl;
		return 0;
	}
	for(int q=0;q<k;q++)
	{
		cin >> x >> y;
		pixels[x-1][y-1] = 1;
		if(check(x-1,y-1)==1)
		{
			f=1;
			cout << q+1 << endl;
			return 0;
		}
	}
	if(f==0)
		cout << 0 << endl;
	return 0;
}
