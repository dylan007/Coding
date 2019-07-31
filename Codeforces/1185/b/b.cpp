/*=======================
Author    : Shounak Dey
=======================	*/

#include<bits/stdc++.h>

using namespace std;

using ll = long long int;
using ull = unsigned long long int;

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

int main()
{
	fast_io;
	TEST{
		string a,b;
		cin >> a >> b;
		vector<pair<char,int>> ca,cb;
		int c=1;
		char curr=a[0];
		FOR(i,1,a.length()){
			if(curr != a[i]){
				ca.PB(MK(curr,c));
				curr = a[i];
				c = 1;
			}
			else
				c++;
		}
		ca.PB(MK(curr,c));
		c=1;
		curr = b[0];
		FOR(i,1,b.length()){
			if(curr != b[i]){
				cb.PB(MK(curr,c));
				curr = b[i];
				c = 1;
			}
			else
				c++;
		}
		cb.PB(MK(curr,c));
		if(ca.size() != cb.size())
			cout << "NO" << endl;
		else{
			int flag=0;
			REP(i,ca.size()){
				if((cb[i].S<ca[i].S) || (cb[i].F!=ca[i].F)){
					flag=1;
					break;
				}
			}
			if(flag)
				cout << "NO" << endl;
			else
				cout << "YES" << endl;
		}
	}
	return 0;
}

