/*=======================
Author    : Shounak Dey
Filename  : 962b.cpp
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

void parse(string s,vector<int> &arr){
	int curr=0;
	REP(i,s.length()){
		if(s[i]=='.')
			curr++;
		else{
			if(i==0)
				continue;
			arr.PB(curr);
			curr=0;
		}
	}
	if(curr)
		arr.PB(curr);
}

int main()
{
	int n,a,b;
	cin >> n >> a >> b;
	string s;
	cin >> s;
	vector<int> arr;
	parse(s,arr);
	if(a>b){
		a += b;
		b = a-b;
		a = a-b;
	}
	SORTV(arr);
	int ans=0;
	REP(i,arr.size()){
		int l,r;
		l = arr[i]/2;
		r = arr[i]/2 + arr[i]%2;
		if(l>a || r>b){
			ans += min(l,a) + min(r,b);
			l -= min(l,a);
			r -= min(r,b);
		}
		a -= l;
		b -= r;
		ans += arr[i];
	}
	cout << ans << endl;
	return 0;
}