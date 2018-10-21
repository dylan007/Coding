/*=======================
Author    : Shounak Dey
Filename  : typing.cpp
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

int state(char x){
	if(x=='d' || x=='f')
		return 0;
	return 1;
}

int main()
{
	TEST{
		int n;
		cin >> n;
		int ans=0;
		map<string,int> c;
		while(n--){
			string a;
			cin >> a;
			int curr=0;
			if(c.find(a) != c.end()){
				ans += c[a]/2;
				continue;
			}
			int s=state(a[0]);
			curr += 2;
			FOR(i,1,a.length()){
				if(s != state(a[i])){
					s ^= 1;
					curr += 2;
				}
				else
					curr += 4;
			}
			c[a] = curr;
			ans += curr;
			// error(a,curr);
		}
		cout << ans << endl;
	}
	return 0;
}