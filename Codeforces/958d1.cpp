/*=======================
Author    : Shounak Dey
Filename  : 958d1.cpp
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

int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}

pair<int,int> parse(string exp){
	int a,b,c;
	a=b=c=0;
	int i=1;
	while(1){
		if(exp[i]=='+')
			break;
		a = a*10 + exp[i]-'0';
		i++;
	}
	i++;
	while(1){
		if(exp[i]==')')
			break;
		b = b*10 + exp[i]-'0';
		i++;
	}
	i+=2;
	while(i<exp.length()){
		c = c*10 + exp[i]-'0';
		i++;
	}
	// error(a,b,c);
	a = a+b;
	int g = gcd(a,c);
	a /= g;
	c /= g;
	return MK(a,c);
}

int main()
{
	int T;
	cin >> T;
	map<pair<int,int>,int> c;
	vector<pair<int,int>> x;
	getchar();
	REP(test,T){
		string a;
		getline(cin,a);
		// cout << a << endl;
		pair<int,int> temp = parse(a);
		// cout << temp.first << " " << temp.second << endl;;
		x.PB(temp);
		if(c.find(temp) == c.end())
			c[temp] = 1;
		else
			c[temp]++;
	}
	REP(test,T)
		cout << c[x[test]] << " ";
	cout << endl;
	return 0;
}
