//Shounak Dey
#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define PB push_back 
#define MK make_pair
//#define size(a) (int)(sizeof(a))
#define F(i,a,b) for(int i=a;i<b;i++)

void bfs(int n,int m,int x,int y, int depth, vector< vector<int> > &v,vector< vector<int> > &d)
{
	if(v[x][y])
		return;
	cout << x << " " << y << endl;
	v[x][y]=1;
	d[x][y] = min(d[x][y],depth);
	if(x==0)
	{
		if(y==0)
		{
			bfs(n,m,x+1,y,depth+1,v,d);
			bfs(n,m,x+1,y+1,depth+1,v,d);
			bfs(n,m,x,y+1,depth+1,v,d);
		}
		else if(y==(n-1))
		{
			bfs(n,m,x+1,y-1,depth+1,v,d);
			bfs(n,m,x+1,y,depth+1,v,d);
			bfs(n,m,x,y-1,depth+1,v,d);
		}
		else
		{
			bfs(n,m,x+1,y-1,depth+1,v,d);
			bfs(n,m,x+1,y+1,depth+1,v,d);
			bfs(n,m,x+1,y,depth+1,v,d);
			bfs(n,m,x,y-1,depth+1,v,d);
			bfs(n,m,x,y+1,depth+1,v,d);
		}
	}
	else if(x==(m-1))
	{
		if(y==0)
		{
			bfs(n,m,x-1,y,depth+1,v,d);
			bfs(n,m,x-1,y+1,depth+1,v,d);
			bfs(n,m,x,y+1,depth+1,v,d);
		}
		else if(y==(n-1))
		{
			bfs(n,m,x-1,y-1,depth+1,v,d);
			bfs(n,m,x-1,y,depth+1,v,d);
			bfs(n,m,x,y-1,depth+1,v,d);
		}
		else
		{
			bfs(n,m,x-1,y-1,depth+1,v,d);
			bfs(n,m,x-1,y+1,depth+1,v,d);
			bfs(n,m,x-1,y,depth+1,v,d);
			bfs(n,m,x,y-1,depth+1,v,d);
			bfs(n,m,x,y+1,depth+1,v,d);
		}	
	}
	else if(y==0)
	{
		bfs(n,m,x-1,y,depth+1,v,d);
		bfs(n,m,x-1,y+1,depth+1,v,d);
		bfs(n,m,x,y+1,depth+1,v,d);
		bfs(n,m,x+1,y+1,depth+1,v,d);
		bfs(n,m,x+1,y,depth+1,v,d);
	}
	else if(y==(m-1))
	{
		bfs(n,m,x-1,y,depth+1,v,d);
		bfs(n,m,x-1,y-1,depth+1,v,d);
		bfs(n,m,x,y-1,depth+1,v,d);
		bfs(n,m,x+1,y-1,depth+1,v,d);
		bfs(n,m,x+1,y,depth+1,v,d);
	}
	else
	{
			bfs(n,m,x+1,y,depth+1,v,d);
			bfs(n,m,x+1,y+1,depth+1,v,d);
			bfs(n,m,x+1,y-1,depth+1,v,d);
			bfs(n,m,x,y+1,depth+1,v,d);
			bfs(n,m,x,y-1,depth+1,v,d);
			bfs(n,m,x-1,y,depth+1,v,d);
			bfs(n,m,x-1,y-1,depth+1,v,d);
			bfs(n,m,x-1,y+1,depth+1,v,d);
	}
	return;
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int n,m;
		cin >> n >> m;
		int x=0,a=0;
		vector<vector<int> > arr,depth;
		vector<int> temp;
		int max=1e+8;
		F(i,0,n)
		{
			arr.PB(temp);
			depth.PB(temp);
			F(j,0,m)
			{
				cin >> x;
				arr[i].PB(x);
				a = a>x?a:x;
				depth[i].PB(max);
			}
		}
		vector<pair<int,int> > highs;
		F(i,0,n)
		{
			F(j,0,m)
			{
				if(a == arr[i][j])
					highs.PB(MK(i,j));
			}
		}
		F(i,0,m) temp.PB(0);
		F(i,0,highs.size())
		{
			int x,y;
			x = highs[i].first;
			y = highs[i].second;
			vector< vector<int> > visited;
			F(j,0,n) visited.PB(temp);			
			bfs(n,m,x,y,0,visited,depth);
		}
		int ans=0;
		F(i,0,n)
		{
			F(j,0,m)
			{
				cout << depth[i][j] << " ";
				ans = ans>depth[i][j]?ans:depth[i][j];
			}
			cout << endl;
		}
		cout << ans << endl;
	}	
	return 0;
}

