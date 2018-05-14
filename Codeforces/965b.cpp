/*=======================
Author    : Shounak Dey
Filename  : 965b.cpp
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

int calc(vector<vector<int>> board,int x,int y,int k,int n){
	if(board[x][y]==0)
		return 0;
	int v,h;
	v = h = 1;
	int i=y-1;
	while(i>=max(0,y-k+1)){
		if(board[x][i]==0)
			break;
		i--;
		v++;
	}
	i = y+1;
	while(i<=min(n-1,y+k-1)){
		if(board[x][i]==0)
			break;
		i++;
		v++;
	}
	int ans= max(0,v-k+1);
	i = x-1;
	while(i>=max(0,x-k+1)){
		if(board[i][y]==0)
			break;
		i--;
		h++;
	}
	i = x+1;
	while(i<=min(n-1,x+k-1)){
		if(board[i][y]==0)
			break;
		i++;
		h++;
	}
	// error(x,y,v,h);
	// cout << endl;
	ans += max(0,h-k+1);
	return ans;
}

int main()
{
	int n,k;
	cin >> n>> k;
	vector<vector<int>> board(n,vector<int>(n,0));
	REP(i,n){
		string a;
		cin >> a;
		REP(j,n){
			if(a[j] == '#')
				board[i][j] = 0;
			else
				board[i][j] = 1;
		}
	}
	vector<vector<int>> ans(n,vector<int>(n,0));
	int m = 0;
	int x=0,y=0;
	REP(i,n){
		REP(j,n){
			ans[i][j] = calc(board,i,j,k,n);
			if(m < ans[i][j]){
				m = ans[i][j];
				x = i;
				y = j;
				// error(i,j,m);
				// cout << m << endl;
			}
		}
	}
	cout << x+1 << " " << y+1 << endl;
	return 0;
}
