/*=======================
Author    : Shounak Dey
Filename  : vk18.cpp
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

ll count(ll i,ll j,ll n)
{
	i++;j++;
	if(i==1)
		return j;
	return n-j+1;
}

ll val(ll i,ll j)
{
	i++;j++;
	i += j;
	ll e=0,o=0;
	while(i)
	{
		if(i%10 %2)
			o += i%10;
		else
			e += i%10;
		i /= 10;
	}
	return abs(o-e);
}

int main()
{
	ll pre[1000001];
	pre[1] = 2;
	ll curr=2;
	FOR(i,2,1000001)
	{
		ll diff = val(i-2,0);
		ll x = curr-diff + val(i-1,i-2);
		curr = x + val(i-1,i-1);
		//cout << x << " " << val(i-1,i-1) << endl;
		pre[i] = pre[i-1] + 2*x + val(i-1,i-1);
		//cout << pre[i] << endl; 
	}
	TEST{
		ll n;
		cin >> n;
		cout <<  pre[n] << endl;
	}
	return 0;
}
