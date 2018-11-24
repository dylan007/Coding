/*=======================
Author    : Shounak Dey
Filename  : gmedian.cpp
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

#define MOD 1000000007

ll add(ll a,ll b) {return (a+b)%MOD;}
ll mul(ll a,ll b) {return (a*b)%MOD;}

ll modexp(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1)
			ans = (ans * a)%MOD;
		a = (a*a)%MOD;
		b >>= 1;
	}
	return ans;
}

int main()
{
	fast_io;
	//Precompute the nCr function over sample space.
	vector<vector<ll>> dp(1000,vector<ll>(1000,0));
	REP(i,1000){
		REP(j,i+1){
			if(j==0 || j==(i+1))
				dp[i][j] = 1;
			else
				dp[i][j] = add(dp[i-1][j],dp[i-1][j-1]);
		}
	}
	TEST{
		ll n;
		cin >> n;
		vector<ll> arr(n);
		vector<ll> cop;
		map<ll,ll> c;
		map<ll,ll> prec;
		//Create a map with count values.
		REP(i,n){
			cin >> arr[i];
			if(c.find(arr[i]) == c.end()){
				c[arr[i]] = 1;
				cop.PB(arr[i]);
			}
			else
				c[arr[i]]++;
		}
		SORTV(arr);
		ll ans=0;
		//Compute all odd length permutations.
		ans = add(ans,modexp(2,n-1));
		//Sort the set of values.
		SORTV(cop);	
		//Generate the count of elements less than or equal to x for all x in cop.
		REP(i,cop.size()){
			if(i==0)
				prec[cop[i]] = c[cop[i]];
			else
				prec[cop[i]] = c[cop[i]] + prec[cop[i-1]];
		}
		//Iterate over every element in the set and compute the permutations in which it is the median. 
		REP(i,cop.size()){
			if(c[cop[i]]==1)		//Elements with only one occurence cannot be medians of even length permutation.
				continue;
			ll length = 2;
			ll temp = 0;
			while(length <= n){					//Iterate over every even length value.
				ll cd = c[cop[i]]-2;
				ll l = prec[cop[i]] - c[cop[i]]; 				// l -> elements that can be on the left. starts with l1
				ll r = n - l - 2;							// r -> elements that can be on the right. starts with r1 + c1
				ll lim = l+cd;
				error(l,r,lim);
				while(l<=lim){
					temp = add(temp,mul(dp[l][length-2],dp[r][length-2]));
					// error(dp[l][length-2],dp[r][length-2]);
					l++;
					r--;
				}
				temp = mul(temp,dp[cd+2][2]); 			
				error(length,temp,cop[i]);
				length += 2;
			}
			ans = add(ans,temp);
		}
		cout << ans << endl;
	}
	return 0;
}