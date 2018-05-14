//Shounak Dey
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
#define fast_io ios_base::sync_with_stdio(false);cin.tie(Nll)

/*
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
*/
#define END 5000010
#define MOD 1000000007

void sieve(vector<ll> &flag)
{
	FOR(i,2,END)
	{
		if(!flag[i])
		{
			flag[i]=i;
			for(int j=2*i;j<=END;j+=i)
			{
				if(!flag[j])
					flag[j] = i;
			}
		}
	}
}

int modexp(ll a,ll b)
{
	if(b==0)
		return 1;
	else if(b&1)
		return ((a%MOD)*(modexp(a*a,(b-1)/2)))%MOD;
	else
		return modexp(a*a,b/2)%MOD;
}

int calc(ll c,vector<ll> flag,vector<ll> &vals)
{
	if(vals[c]>0)
		return vals[c];
	if(c==1)
		vals[c] = 0;
	else if(flag[c]==1)
		vals[c] = (c*(c-1))/2;
	else
		vals[c] = (flag[c]*(flag[c]-1)/2)*(c/flag[c]) + calc(c/flag[c],flag,vals);
	return vals[c];
}

int main()
{
	vector<ll> flag(END,0);
	sieve(flag);		
	ll t,l,r;
	cin >> t >> l >> r;
	ll ans=0;
	vector<ll> vals(END,0);
	vals[1]=0;
	for(ll i=2;i<=END;i++)
	{
		vals[i] = ((flag[i]*(flag[i]-1))/2)*(i/(flag[i]));
		vals[i] = (vals[i]+vals[i/flag[i]])%MOD;
	}
	int p =1;
	for(ll i=l;i<=r;i++)
	{
		//cout << vals[i] << " " << flag[i] << endl;
		ans = (ans+(p*vals[i])%MOD)%MOD;
		p = (p*t)%MOD;
	}
	cout << ans << endl;
	return 0;
}

