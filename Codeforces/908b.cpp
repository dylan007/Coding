/*=======================
Author    : Shounak Dey
Filename  : 908b.cpp
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

ll valid(vector<string> board,vector<ll> conf,string dir){
	ll x=-1,y=-1;
	ll n = board.size(),m = board[0].length();
	REP(i,n){
		REP(j,m){
			if(board[i][j]=='S'){
				x = i;
				y = j;
				break;
			}
		}
		if(x!=-1)
			break;
	}
	REP(i,dir.length()){
		if(x<0 || x>=n)
			return 0;
		if(y<0 || y>=m)
			return 0;
		if(board[x][y]=='#')
			return 0;
		if(board[x][y]=='E')
			return 1;
		ll p = dir[i]-'0';
		switch(conf[p]){
			case 0:
				x++;
				break;
			case 1:
				x--;
				break;
			case 2:
				y++;
				break;
			case 3:
				y--;
				break;
		}
	}
	if(x<0 || x>=n)
		return 0;
	if(y<0 || y>=m)
		return 0;
	if(board[x][y]=='#')
		return 0;
	if(board[x][y]=='E')
		return 1;
	return 0;
}

int main()
{
	fast_io;
	ll n,m;
	cin >> n >> m;
	vector<string> board(n);
	REP(i,n)
		cin >> board[i];
	string dir;
	cin >> dir;
	vector<ll> conf = {0,1,2,3};
	ll ans=0;
	do{
		if(valid(board,conf,dir))
			ans++;
	}while(next_permutation(conf.begin(),conf.end()));
	cout << ans << endl;
	return 0;
}