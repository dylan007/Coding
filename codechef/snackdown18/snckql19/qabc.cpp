/*=======================
Author    : Shounak Dey
Filename  : qabc.cpp
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
	TEST{
		int n;
		cin >> n;
		vector<int> a(n),b(n);
		REP(i,n)
			cin >> a[i];
		REP(i,n)
			cin >> b[i];
		REP(i,n)
			a[i] = b[i]-a[i];
		REP(i,n){
			if(a[i]<0){
				cout << "NIE" << endl;
				continue;
			}
		}
		if(n==1){
			if(a[0])
				cout << "NIE" << endl;
			else
				cout << "TAK" << endl;
			continue;
		}
		else if(n==2){
			if(a[0] || a[1])
				cout << "NIE" << endl;
			else
				cout << "TAK" << endl;
			continue;
		}
		int flag=0;
		for(int i=(n-1);i>=2;i--){
			if((a[i]%3) != 0){
				flag=1;
				break;
			}
			int div = a[i]/3;
			a[i-1] -= div*2;
			a[i-2] -= div;
			a[i] = 0;
		}
		flag |= (a[0]>0) || (a[1]>0);
		if(flag)
			cout << "NIE" << endl;
		else
			cout << "TAK" << endl;
	}
	return 0;
}