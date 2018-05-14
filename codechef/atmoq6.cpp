/*=======================
Author    : Shounak Dey
Filename  : atmoq6.cpp
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

ull check(vector<ull> v)
{
	for(ull i=0;i<v.size();i++) if(!v[i]) return i;
	return v.size();
}

ull count(vector<ull> &v,vector<ull> child,ull pos)
{
	if(v[pos] == 1)
		return 0;
	v[pos] = 1;
	return 1+count(v,child,child[pos]-1);
}

ull gcd(ull a,ull b){
	return b==0?a:gcd(b,a%b);
}

ull lcm(ull a,ull b){
	return (a*b)/gcd(a,b);
}

int main()
{
	TEST{
		ull n;
		readul(n);
		vector<ull> cycles;
		vector<ull> v(n,0);
		vector<ull> child(n);
		REP(i,n) readul(child[i]);
		while(1){
			ull pos =  check(v);
			if(pos==v.size()) break;
			cycles.PB(count(v,child,pos));
		}
		// for(auto it:cycles) cout << it << " ";
		// cout << endl;
		ull ans = cycles[0];
		for(int i=1;i<cycles.size();i++)
			ans = lcm(cycles[i],ans);
		cout << ans << endl;
	}
	return 0;
}
