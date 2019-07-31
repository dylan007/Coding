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

vector<string> perm;

void build(string a){
	if(a.length()==5){
		perm.PB(a);
		return;
	}
	build(a+"P");
	build(a+"S");
	build(a+"R");
}

int better(char a,char b){
	if((a=='P' && b=='R') || (a=='R' && b=='P'))
		return 'P';
	if((a=='S' && b=='R') || (a=='R' && b=='S'))
		return 'R';
	if((a=='S' && b=='P') || (a=='P' && b=='S'))
		return 'S';
}

int check(string a,string b){
	int c=0;
	int l = (a.length() * b.length()) / gcd(a.length(),b.length());
	int f=1;
	while(c<l){
		char c1,c2;
		c1 = a[c%a.length()];
		c2 = b[c%b.length()];
		char x = better(c1,c2);
		if((x==c1) && (c1!=c2))
			return 0;
		f &= (c1==c2);
		c++;
	}
	if(f)
		return 0;
	return 1;
}

int main()
{
	fast_io;
	int T;
	cin >> T;
	build("");
	REP(test,T){
		int n;
		cin >> n;
		cout << "Case #" << test+1 << ": ";
		int f=0;
		vector<string> s(n);
		string out="IMPOSSIBLE";
		REP(i,n)
			cin >> s[i];
		for(auto it:perm){
			f=1;
			REP(i,n)
				f &= check(s[i],it);
			if(f){
				out = it;
				break;
			}
		}
		cout << out << endl;
	}
	return 0;
}

