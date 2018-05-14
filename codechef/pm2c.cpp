/*=======================
Author    : Shounak Dey
Filename  : pm2c.cpp
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
vector<vector<int>> v(10,vector<int>(10,0));

pair<int,int> check(int n,int m){
	pair<int,int> t;
	REP(i,n){
		REP(j,m)
		{
			if(v[i][j] == 0){
				t.first = i;
				t.second = j;
				return t;
			}
		}
	}
	t.first = -1;
	t.second = -1;
	return t;
}


void dfs(vector<vector<int>> arr,int n,int m,int x,int y){
	if(!(x>=0 && x<n))
		return;
	if(!(y>=0 && y<m))
		return;
	v[x][y] = 1;
	//cout << x << " " << y << " " << arr[x][y] << endl;
	if(x!=0 && (arr[x][y]==arr[x-1][y]) && !v[x-1][y])
		dfs(arr,n,m,x-1,y);
	if(x!=(n-1) && (arr[x][y]==arr[x+1][y]) && !v[x+1][y])
		dfs(arr,n,m,x+1,y);
	if(y!=0 && (arr[x][y]==arr[x][y-1]) && !v[x][y-1])
		dfs(arr,n,m,x,y-1);
	if(y!=(m-1) && (arr[x][y]==arr[x][y+1]) && !v[x][y+1])
		dfs(arr,n,m,x,y+1);
	return;
}

int main()
{
	TEST{
		int n,m;
		cin >> n >> m;
		vector<vector<int>> arr(n,vector<int>(m,0));
		REP(i,n){
			REP(j,m)
				cin >> arr[i][j];
		}
		int ans=0;
		v = vector<vector<int>>(10,vector<int>(10,0));
		while(1)
		{
			pair<int,int> t;
			t = check(n,m);
			// /cout << t.first << " " << t.second << endl;
			if(t.first == -1)
				break;
			ans++;
			dfs(arr,n,m,t.first,t.second);
			//cout << endl;
		}
		cout << ans << endl;
	}
	return 0;
}
