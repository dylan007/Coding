/*=======================
Author    : Shounak Dey
Filename  : 43b.cpp
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
	string head,text;
	getline(cin,head);
	getline(cin,text);
	vector<int> small(26,0),big(26,0);
	for(int i=0;i<head.length();i++)
	{
		if(head[i]>=97 && head[i]<=122)
			small[head[i]-97]++;
		else if(head[i]>=65 && head[i]<=90)
			big[head[i]-65]++;
	}
	int flag=0;
	for(int i=0;i<text.length();i++)
	{
		if(text[i]>=97 && text[i]<=122){
			small[text[i]-97]--;
			if(small[text[i]-97] < 0)
				flag++;
		}
		else if(text[i]>=65 && text[i]<=90){
			big[text[i]-65]--;
			if(big[text[i]-65] < 0)
				flag++;
		}
	}
	if(flag)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
	return 0;
}
