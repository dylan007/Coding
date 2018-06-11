/*=======================
Author    : Shounak Dey
Filename  : euler011.cpp
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

int main()
{
	vector<vector<int>> arr(20,vector<int>(20));
	REP(i,20){
		REP(j,20)
			cin >> arr[i][j];
	}
	int ans = INT_MIN;
	REP(i,20){
		REP(j,17)
			ans = max(ans,arr[i][j]*arr[i][j+1]*arr[i][j+2]*arr[i][j+3]);
	}
	REP(i,17){
		REP(j,20)
			ans = max(ans,arr[i][j]*arr[i+1][j]*arr[i+2][j]*arr[i+3][j]);
	}
	REP(i,17){
		REP(j,17)
			ans = max(ans,arr[i][j]*arr[i+1][j+1]*arr[i+2][j+2]*arr[i+3][j+3]);
	}
	FOR(i,3,20){
		REP(j,17)
			ans = max(ans,arr[i][j]*arr[i-1][j+1]*arr[i-2][j+2]*arr[i-3][j+3]);
	}
	cout << ans << endl;
	return 0;
}