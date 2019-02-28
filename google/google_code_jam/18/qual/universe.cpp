/*=======================
Author    : Shounak Dey
Filename  : universe.cpp
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

int calc(string a){
	int d=0,curr=1;
	REP(i,a.length()){
		if(a[i]=='C')
			curr <<= 1;
		else
			d += curr;
	}
	return d;
}

int main()
{
	int T;
	cin >> T;
	for(int test=0;test<T;test++){
		cout << "Case #" << test+1 << ": ";
		int d;
		string a;
		cin >> d >> a;
		int c=0;
		REP(i,a.length()){
			c += a[i]=='C';
		}
		if(c==0){
			if(a.length() > d)
				cout << "IMPOSSIBLE" << endl;
			else
				cout << 0 << endl;
		}
		else if(c==(a.length())){
			cout << 0 << endl;
		}
		else{
			if(d < (a.length()-c))
				cout << "IMPOSSIBLE" << endl;
			else{
				int score=0,damage=0,charge=1;
				REP(i,a.length()){
					if(a[i]=='C')
						charge <<= 1;
					else
						damage += charge;
				}
				while(damage>d){
					for(int i=(a.length()-1);i>=1;i--){
						if(a[i]=='S' && a[i-1]=='C'){
							a[i] = 'C';
							a[i-1] = 'S';
							damage = calc(a);
							score++;
						}
					}
				}
				cout << score << endl;
			}
		}
	}
	return 0;
}
