/*=======================
Author    : Shounak Dey
Filename  : 1008c.cpp
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
	map<int,int> c;
	map<int,int> temp;
	REP(i,n){
		cin >> arr[i];
		if(c.find(arr[i]) == c.end()){
			c[arr[i]] = 1;
			temp[arr[i]] = 1;
		}
		else{
			c[arr[i]]++;
			temp[arr[i]]++;
		}
	}
	vector<int> set;
	map<int,int>::iterator it = c.begin();
	while(it != c.end()){
		set.PB(it->first);
		it++;
	}
	int l=0,r=1;
	if(set.size()==1){
		cout << 0 << endl;
		return 0;
	}
	int ans=0;
	vector<int> visited(set.size(),0);
	while(r<set.size() && l<set.size()){
		if(l>=r){
			r++;
			continue;
		}
		int a;
		if(visited[l] && temp[set[l]]>0)
			a = temp[set[l]];
		else
			a = c[set[l]];
		visited[l] = 1;
		int b = temp[set[r]];
		// cout << a << " " << b << endl;
		int p = min(a,b);
		a -= p;
		b -= p;
		ans += p;
		temp[set[l]] = a;
		temp[set[r]] = b;
		// cout << l << " " <s< r << " " << p << endl;
		if(a==0)
			l++;
		if(b==0)
			r++;
	}
	cout << ans << endl;
	return 0;
}