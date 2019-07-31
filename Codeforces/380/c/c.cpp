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

typedef struct node{
	int a,b,c;
}node;

node create(int a,int b,int c){
	node tmp;
	tmp.a = a;
	tmp.b = b;
	tmp.c = c;
	return tmp;
}

vector<node> st;
string s;
int l,size;

void build(int pos,int start,int end){
	if(start==end)
		st[pos] = create(0,(s[start]=='('),(s[start]==')'));
	else{
		build(2*pos,start,(start+end)/2);
		build(2*pos + 1,(start+end)/2 + 1, end);
		int t = min(st[2*pos].b,st[2*pos+1].c);
		st[pos] = create(st[2*pos].a + st[2*pos+1] + t,st[2*pos].b + st[2*pos + 1].b - t,st[2*pos].c + st[2*pos + 1].c - t);
	}
	return;
}

int query(int pos,int start,int end,int l,int r){

}

int main()
{
	fast_io;
	cin >> s;
	l = s.length();
	size = 4*l;
	st = vector<node>(size);
	build(1,0,l-1);
	return 0;
}

