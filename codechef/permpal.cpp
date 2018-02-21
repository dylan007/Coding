/*=======================
Author    : Shounak Dey
Filename  : permpal.cpp
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
	TEST{
		string a;
		cin >> a;
		vector<int> temp;
		vector<vector<int>> pos(26,temp);
		vector<int> c(26,0);
		REP(i,a.length()){
			c[a[i]-'a']++;
			pos[a[i]-'a'].PB(i);
		}
		int o=0;
		REP(i,26)
			o += c[i]%2;
		if(o>1)
		{
			cout << -1 << endl;
			continue;
		}
		int l,r;
		l = 0;
		r = a.length()-1;
		vector<int> out(a.length(),0);
		REP(i,26)
		{
			if(c[i]<1)
				continue;
			int x = c[i]/2;
			int j=0;
			while(x--)
			{
				out[l++] = pos[i][j++];
				out[r--] = pos[i][j++];
			}
			if(c[i]%2)
				out[a.length()/2] = pos[i][j];
		}
		REP(i,a.length())
			cout << out[i]+1 << " ";
		cout << endl;
	}
	return 0;
}
