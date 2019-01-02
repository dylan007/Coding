/*=======================
Author    : Shounak Dey
Filename  : spikes.cpp
=======================	*/

#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define PB push_back
#define MK make_pair 
#define SZ(a) (int)(sizeof(a))
#define F first
#define S second
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) for(int i=0;i<n;i++)
#define read(n) scanf("%d",&n)
#define readl(n) scanf("%lld",&n)
#define readul(n) scanf("%llu",&n);


#define SORTV(a) sort(a.begin(),a.end())
#define TEST int Test;cin >> Test;while(Test--)
#define gcd(a,b) __gcd(a,b)
#define ffs(a) __builtin_ffs(a) // find first set
#define clz(a) __builtin_clz(a) // count leading zeroes
#define ctz(a) __builtin_ctz(a) // count trailing zeroes
#define popc(a) __builtin_popcount(a) // count set bits
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)


#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }

vector<string> split(const string& s, char c) {
	vector<string> v;
	stringstream ss(s);
	string x;
	while (getline(ss, x, c))
		v.emplace_back(x);
	return move(v);
}

void err(vector<string>::iterator it) {}
template<typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
	cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << '\n';
	err(++it, args...);
}

int main()
{
	fast_io;
	ll n,m,k;
	cin >> n >> m >> k;
	k>>=1;
	vector<string> maze(n,string());	
	REP(i,n)
		cin >> maze[i];
	// REP(i,n)
	// 	cout << maze[i] << endl;
	vector<pair<int,int>> start,end;
	REP(i,n){
		REP(j,m){
			if(maze[i][j]=='@')
				start.PB({i,j});
			if(maze[i][j]=='x')
				end.PB({i,j});
		}
	}
	int f=0;
	map<pair<int,int>,int> cs,ce;
	for(auto it: start){
		vector<vector<int>> visited(n,vector<int>(m,0));
		vector<vector<int>> count(n,vector<int>(m,0));
		queue<pair<int,int>> q;
		q.push(it);
		while(!q.empty()){
			pair<int,int> curr = q.front();
			q.pop();
			int x,y;
			x = curr.first;
			y = curr.second;
			if(x<0 || x>=n || y<0 || y>=m)
				continue;
			if(maze[x][y]=='x'){
				f = 1;
				cs[{x,y}]=count[x][y];
				break;
			}
			else if(maze[x][y]=='#')
				continue;
			if(count[x][y]>k)
				break;	
			if(x<(n-1) && !visited[x+1][y]){
				visited[x+1][y]=1;
				count[x+1][y] = (maze[x+1][y]=='s') + count[x][y];
				q.push({x+1,y});
			}
			if(y<(m-1) && !visited[x][y+1]){
				visited[x][y+1]=1;
				count[x][y+1] = (maze[x][y+1]=='s') + count[x][y];
				q.push({x,y+1});
			}
			if(x>=1 && !visited[x-1][y]){
				visited[x-1][y] = 1;
				count[x-1][y] = (maze[x-1][y]=='s') + count[x][y];
				q.push({x-1,y});
			}
			if(y>=1 && !visited[x][y-1]){
				visited[x][y-1] = 1;
				count[x][y-1] = (maze[x][y-1]=='s') + count[x][y];
				q.push({x,y-1});
			}
		}
		if(f)
			break;
	}
	if(!f)
		cout << "IMPOSSIBLE" << endl;
	else
		cout << "SUCCESS" << endl;
	return 0;
}