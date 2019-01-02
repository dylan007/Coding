/*=======================
Author    : Shounak Dey
Filename  : 1082b.cpp
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
	vector<ll> rle;
	ll pos=1;
	char curr=a[0];
	ll l=1,c=(a[0]=='G');
	while(pos<a.length()){
		if(curr != a[pos]){
			curr = a[pos];
			rle.PB(l);
			l=1;
		}
		else
			l++;
		c+=(a[pos]=='G');
		pos++;
	}
	rle.PB(l);
	ll ans=0;
	ll f = (a[0]=='G')?0:1;
	// for(auto it:rle)
	// 	cout << it << " ";
	// cout << endl;
	REP(i,rle.size()){
		if((i&1)==f)
			ans = max(ans,rle[i]+(rle[i]<c));
		else{
			if(i>0 && (i<(rle.size()-1)))
				ans = max(ans,rle[i-1]+rle[i+1]+(rle[i-1]+rle[i+1] < c));
			else if(i==0 && (i+1)<rle.size())
				ans = max(ans,rle[i+1]+(rle[i+1]<c));
			else if(i==(rle.size()-1) && (i>0))
				ans = max(ans,rle[i-1]+(rle[i-1]<c));
		}
		// error(ans);
	}
	cout << ans << endl;
	return 0;
}