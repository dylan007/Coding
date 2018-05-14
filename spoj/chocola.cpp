/*=======================
Author    : Shounak Dey
Filename  : chocola.cpp
=======================	*/

#include <bits/stdc++.h>

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
		int n,m;
		cin >> n >> m;
		vector<int> x(n-1);
		vector<int> y(m-1);
		int f = (n>m);
		vector<pair<int,int>> p;
		REP(i,n-1){
			cin >> x[i];
			p.PB(MK(x[i],f));
		}
		REP(i,m-1){
			cin >> y[i];
			p.PB(MK(y[i],!f));
		}
		sort(p.rbegin(),p.rend());
		// for(auto it:p)
		// 	cout << it.first << " " << it.second << endl;
		int px=0,py=0;
		int ans=0;
		for(auto it:p){
			if(it.second == f){
				ans += (px+1)*it.first;
				py++;
			}
			else{
				ans += (py+1)*it.first;
				px++;
			}
			// error(ans,px,py);
		}
		cout << ans << endl;
	}
	return 0;
}
