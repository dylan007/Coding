/*=======================
Author    : Shounak Dey
Filename  : 998b.cpp
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

int get(vector<int> parity,int start,int end){
	int n = parity.size();
	int l,r;
	if(start == 0)
		l=0;
	else
		l = parity[start-1];
	if(end==(n-1))
		r = 0;
	else
		r = parity[n-1]-parity[end];
	return parity[n-1]-l-r;
}

int main()
{
	int n,k;
	cin >> n >> k;
	vector<int> arr(n);
	vector<int> parity(n);
	REP(i,n){
		cin >> arr[i];
	}
	parity[0] = arr[0]%2;
	FOR(i,1,n)
		parity[i] += parity[i-1] + arr[i]%2;
	vector<int> costs;
	REP(i,n-1){
		int l = get(parity,0,i);
		int r = get(parity,i+1,n-1);
		// error(arr[i],l,r);
		if(l==((i+1)/2) && r==((n-i-1)/2))
			costs.PB(abs(arr[i+1]-arr[i]));
	}
	// for(auto it:costs)
	// 	cout << it << " ";
	// cout << endl;
 	SORTV(costs);
	int ans=0;
	for(auto it:costs){
		if(k<it)
			break;
		ans++;
		k -= it;
	}
	cout << ans << endl;
	return 0;
}