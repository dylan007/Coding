/*=======================
Author    : Doraemon
Filename  : xxor.cpp
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
	int n,q;
	cin >> n >> q;
	vector<int> arr(n);
	vector<vector<int>> count(n,vector<int>(32,0));
	REP(i,n){
		cin >> arr[i];
		// count = update(count,arr[i],i);
		int x = arr[i];
		REP(j,31){
			count[i][j] = count[i-(i!=0)][j]+(x%2);
			x >>= 1;
		}
	}
	while(q--){
		int l,r;
		cin >> l >> r;
		l--;r--;
		// cout << solve(count,l,r) << endl;
		int ans = 0;
		ull pow=1;
		int x = (r-l+2)/2;
		// error(x);
		REP(i,31){
			int temp;
			if(l==0)
				temp = count[r][i];
			else
				temp = count[r][i] - count[l-1][i];
			if(temp>=x){
				// cout << pow << endl;
				ans += pow;
			}
			pow <<= 1;
		}
		ans = INT_MAX-ans;
		cout << ans << endl;
	}
	return 0;
}
