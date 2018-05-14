/*=======================
Author    : Shounak Dey
Filename  : 977f.cpp
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
	int n;
	cin >> n;
	vector<int> arr(n);
	REP(i,n)
		cin >> arr[i];
	map<int,int> dp;
	REP(i,n){
		int t = arr[i]-1;
		if(dp.find(t) != dp.end()){
			if(dp.find(arr[i]) != dp.end())
				dp[arr[i]] = max(dp[arr[i]],dp[t]+1);
			else
				dp[arr[i]] = dp[t]+1;
		}
		else{
			if(dp.find(arr[i]) == dp.end())
				dp[arr[i]] = 1;
		}
	}
	map<int,int>::iterator it=dp.begin();
	int lmax = 0;
	int start = 0;
	while(it != dp.end()){
		// cout << it->first << " " << it->second << endl;
		if(it->second > lmax){
			lmax = it->second;
			start = it->first;
		}
		it++;
	}
	int i = n-1;
	vector<int> ans;
	while(i>=0 && lmax>=0){
		if(arr[i] == start){
			ans.PB(i);
			start--;
			lmax--;
		}
		i--;
	}
	reverse(ans.begin(),ans.end());
	cout << ans.size() << endl;
	for(auto it:ans)
		cout << it+1 << " ";
	cout << endl;
	return 0;
}
