/*=======================
Author    : Shounak Dey
Filename  : 377a.cpp
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
#define popc(a) __ builtin_popcount(a) // count set bits
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

void dfs(vector<vector<int>> arr,vector<vector<int>> &visited,int x,int y){
	if(x>=arr.size() && x<0)
		return;
	if(y>=arr[0].size() && y<0)
		return;
	if(arr[x][y]<0)
		return;
	if(visited[x][y])
		return;
	visited[x][y] = 1;
	cout << x << " " << y << endl;
	dfs(arr,visited,x+1,y);
	dfs(arr,visited,x-1,y);
	dfs(arr,visited,x,y-1);
	dfs(arr,visited,x,y+1);
	return;
}

int check(vector<vector<int>> arr,vector<vector<int>> visited){
	REP(i,visited.size()){
		REP(j,visited.size()){
			if(arr[i][j]>=0){
				if(visited[i][j]!=1)
					return 1;
			}
		}
	}
	return 0;
}

pair<int,int> find(vector<vector<int>> arr){
	pair<int,int> temp;
	temp.first = -1;
	temp.second = -1;
	REP(i,arr.size()){
		REP(j,arr[0].size()){
			if(arr[i][j] == 0){
				temp.first = i;
				temp.second = j;
				return temp;
			}
		}
	}
	return temp;
}

int main()
{
	int n,m,k;
	cin >> n >> m >> k;
	vector<vector<int>> arr(n,vector<int>(m,0));
	REP(i,n){
		string a;
		cin >> a;
		REP(j,m){
			arr[i][j] = (a[j]=='.')*0 + (a[j]=='#')*(-1); 
		}
	}
	REP(i,n){
		REP(j,m){
			if(arr[i][j]<0)
				continue;
			vector<vector<int>> visited(n,vector<int>(m,0));
			arr[i][j] = -2;
			pair<int,int> pos = find(arr);
			cout << pos.first << " " << pos.second << endl;
			dfs(arr,visited,pos.first,pos.second);
			if(check(arr,visited))
				arr[i][j] = 0;
			else
				k--;
			if(k<=0)
				break;
		}
	}
	REP(i,n){
		REP(j,m)
		{
			if(arr[i][j]==0)
				cout << '.';
			if(arr[i][j]==-1)
				cout << '#';
			if(arr[i][j] == -2)
				cout << 'X';
		}
		cout << endl;
	}
	return 0;
}
