/*=======================
Author    : Shounak Dey
Filename  : 1008a.cpp
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

int check(char x){
	return (x=='a')||(x=='e')||(x=='i')||(x=='o')||(x=='u')||(x=='n');
}


int main()
{
	string a;
	cin >> a;
	int flag=0;
	if(a.length()==1){
		if(check(a[0]))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		return 0;
	}
	FOR(i,0,a.length()-1){
		if(check(a[i]))
			continue;
		if(!check(a[i]) && (a[i+1]=='n' || !check(a[i+1]))){
			flag=1;
			break;
		}
	}
	if(!check(a[a.length()-1]))
		flag=1;
	if(flag)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
 	return 0;
}