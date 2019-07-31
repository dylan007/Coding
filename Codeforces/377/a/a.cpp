/*=======================
Author    : Shounak Dey
=======================	*/

#include<bits/stdc++.h>

using namespace std;

using ll = long long int;
using ull = unsigned long long int;

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

int n,m,k;
vector<vector<int>> v,turn;
vector<string> a;

void dfs(int x,int y){
	v[x][y] = 1;
	int f=1;
	if(x!=0 && !v[x-1][y] && a[x-1][y]=='.'){
		dfs(x-1,y);
		f &= turn[x-1][y];
	}
	if(y!=0 && !v[x][y-1] && a[x][y-1]=='.'){
		dfs(x,y-1);
		f &= turn[x][y-1];
	}
	if(x!=(n-1) && !v[x+1][y] && a[x+1][y]=='.'){
		dfs(x+1,y);
		f &= turn[x+1][y];
	}
	if(y!=(m-1) && !v[x][y+1] && a[x][y+1]=='.'){
		dfs(x,y+1);
		f &= turn[x][y+1];
	}
	if(f && k>0){
		turn[x][y] = 1;
		k--;
	}
	return;
}

int main()
{
	fast_io;
	cin >> n >> m >> k;
	a = vector<string>(n);
	REP(i,n)
		cin >> a[i];
	v = vector<vector<int>>(n,vector<int>(m,0));
	turn = vector<vector<int>>(n,vector<int>(m,0));
	REP(i,n){
		int f=0;
		REP(j,m){
			if(a[i][j]=='.'){
				f=1;
				dfs(i,j);
			}
		}
		if(f)
			break;
	}
	REP(i,n){
		REP(j,m){
			if(turn[i][j])
				cout << "X";
			else
				cout << a[i][j];
		}
		cout << endl;
	}
	return 0;
}

