/*=======================
Author    : Shounak Dey
Filename  : a.cpp
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

int check(string a,string b){
	vector<int> c(26,0);
	REP(i,a.length())
		c[a[i]-'A']++;
	REP(i,b.length())
		c[b[i]-'A']--;
	REP(i,26){
		if(c[i]!=0)
			return 0;
	}
	return 1;
}

int main()
{
	int T;
	cin >> T;
	REP(test,T){
		int l;
		cin >> l;
		string a,b;
		cin >> a >> b;
		int ans=0;
		REP(i,l){
			FOR(j,i,l){
				int length = j-i+1;
				REP(k,l-length+1){
					if(check(a.substr(i,length),b.substr(k,length))){
						ans++;
						break;
					}
				}
			}
		}
		cout << "Case #" << test + 1 << ": " << ans << endl;
	}
	return 0;
}