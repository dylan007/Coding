/*=======================
Author    : Shounak Dey
Filename  : kcon.cpp
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
ll solve(vector<ll> cop,ll sum,vector<ll> x,ll n,ll k)
{
	ll maxe=0,maxs=0,index=-1;
	ll i;
	for(i=0;i<2*n;i++)
	{
		maxe += cop[i];
		if(maxe > maxs)
		{
			maxs = maxe;
			index = i;
		}
		if(maxe < 0)
			maxe=0;
	}
	ll aux=0;
	ll t;
	if(index!=(n-1) && index!=(2*n-1))
	{
		t = index+1;
		ll auxt = 0;
		for(;t<n;t++){
			auxt += cop[t];
			aux = max(aux,auxt);
		}
	}
	//cout << sum << " " << aux << endl;
	if(sum>=0)
	{
		if(index<n)
			return maxs + (k-1)*sum + aux;
		else
			return maxs + (k-2)*sum + aux;
	}
	else
		return maxs + aux;
}

int main()
{
	TEST{
		ll n,k;
		cin >> n >> k;
		vector<ll> x(n);
		ll sum=0;
		ll p=0;
		REP(i,n)
		{
			cin >> x[i];
			sum += x[i];
			p += x[i]>0;
		}
		if(p==n)
		{
			cout << sum*k << endl;
			continue;
		}
		else if(p==0)
		{
			cout << *max_element(x.begin(),x.end()) << endl;
			continue;
		}
		if(k==1)
		{
			ll maxe=0,maxs=0,index=-1;
			ll i;
			for(i=0;i<n;i++)
			{
				maxe += x[i];
				if(maxe > maxs)
				{
					maxs = maxe;
					index = i;
				}
				if(maxe < 0)
					maxe=0;
			}
			cout << maxs << endl;
			continue;		
		}
		vector<ll> cop;
		cop.insert(cop.begin(),x.begin(),x.end());
		cop.insert(cop.end(),x.begin(),x.end());
		cout << solve(cop,sum,x,n,k) << endl;;
	}
	return 0;
}
