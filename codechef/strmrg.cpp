/*=======================
Author    : Shounak Dey
Filename  : strmrg.cpp
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

int lcs(string a,string b,int p,int q)
{
	vector<vector<int>> dp(p+1,vector<int>(q+1,0));
	REP(i,p+1)
	{
		REP(j,q+1)
		{
			if(i==0 || j==0)
				dp[i][j] = 0;
			else if(a[i-1] == b[j-1])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[p][q];
}

int f(string s)
{
	int ans=1;
	REP(i,s.length()-1)
	{
		ans += s[i]!=s[i+1];
	}
	return ans;
}

void upd(string &a){
	string temp="";
	temp += a[0];
	FOR(i,1,a.length())
	{
		if(temp[temp.size()-1] != a[i])
			temp += a[i];
	}
	a = temp;
}

int main()
{
	TEST{
		int n,m;
		cin >> n >> m;
		string a,b;
		cin >> a >> b;
		upd(a);upd(b);
		cout << a.length() + b.length() - lcs(a,b,a.length(),b.length()) << endl;
	}
	return 0;
}
