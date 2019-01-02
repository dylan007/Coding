/*=======================
Author    : Shounak Dey
Filename  : 1096d.cpp
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

int main()
{
	fast_io;
	ll n;
	cin >> n;
	string a;
	cin >> a;
	vector<ll> arr(n);
	REP(i,n)
		cin >> arr[i];
	vector<ll> x;
	string tmp;
	ll c=0,indd=n-1;
	while(a[indd]!='d')
		indd--;
	REP(i,indd+1){
		if(a[i]=='h'){
			x.PB(arr[i]);
			tmp += 'h';
			c=max(1ll,c);
		}
		if(a[i]=='a' && c>0){
			x.PB(arr[i]);
			tmp += 'a';
			c=max(2ll,c);
		}
		if(a[i]=='r' && c>1){
			x.PB(arr[i]);
			tmp += 'r';
			c=max(3ll,c);
		}
		if(a[i]=='d' && c>2){
			x.PB(arr[i]);
			tmp += 'd';
			c=max(4ll,c);
		}
	}
	map<char,ll> index = {{'h',0},{'a',1},{'r',2},{'d',3}};
	string tmp2;
	vector<ll> count(4,0);
	vector<ll> y;
	REP(i,tmp.length())
		count[index[tmp[i]]]++;
	REP(i,tmp.length()){
		if(tmp[i]=='h' && count[1] && count[2] && count[3]){
			tmp2 += 'h';
			y.PB(x[i]);
			count[0]--;
		}
		if(tmp[i]=='a' && count[2] && count[3]){
			tmp2 += 'a';
			y.PB(x[i]);
			count[1]--;
		}
		if(tmp[i]=='r' && count[3]){
			tmp2 += 'r';
			y.PB(x[i]);
			count[2]--;
		}
		if(tmp[i]=='d'){
			tmp2 += 'd';
			y.PB(x[i]);
			count[3]--; 	
		}
	}

	cout << tmp << " " << tmp2 << endl;
	vector<ll> cost(4,0);
	// for(auto it: y)
	// 	cout << it << " ";
	// cout << endl;
	REP(i,tmp2.length()){
		if(tmp2[i]=='h')
			cost[0] += y[i];
		if(tmp2[i]=='a')
			cost[1] += y[i];
		if(tmp2[i]=='r')
			cost[2] += y[i];
		if(tmp2[i]=='d')
			cost[3] += y[i];
	}
	ll ans=cost[0];
	for(auto it: cost)
		ans = min(it,ans);
	cout << ans << endl;
	return 0;
}