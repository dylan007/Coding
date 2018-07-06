/*=======================
Author    : Shounak Dey
Filename  : 991e.cpp
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

void decomp(string a,set<string> &out,int size){
	string temp = "";
	set<char> x;
	for(int i=a.length()-1;i>=0;i--){
		temp = a[i] + temp;
		x.insert(a[i]);
		if(temp[0]!='0' && x.size()==size){
			out.insert(temp);
			cout << temp << endl;
		}
	}
}

int main()
{
	string a;
	cin >> a;
	map<char,int> count;
	int dis=0;
	sort(a.begin(),a.end());
	cout << a << endl;
	set<string> out;
	REP(i,a.length()){
		if(count.find(a[i]) != count.end()){
			count[a[i]]++;
		}
		else{
			count[a[i]] = 1;
			dis++;
		}
	}
	do{
		if(a[0]!='0'){
			out.insert(a);
			cout << a << endl;
		}
		decomp(a,out,dis);
	}while( next_permutation(a.begin(),a.end()));
	cout << out.size() << endl;
	return 0;
}