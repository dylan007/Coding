/*=======================
Author    : Shounak Dey
Filename  : fentree.cpp
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

void construct(vector<int> &bit,int n)
{
	bit = vector<int>(n+1,0);
}

int getsum(vector<int>bit,int i)
{
	int index = i;
	int ans = 0;
	while(index)
	{
		ans += bit[index];
		index -= index&(-index);
	}
	return ans;
}

void update(vector<int> bit,int i,int x){
	int index = i;
	while(index < bit.size())
	{
		bit[index] += x;
		index += (index & (-index));
	}
}

int main()
{
	int n;
	cin >> n;
	vector<int> x(n);
	REP(i,n)
		cin >> x[i];
	int q;
	cout << n << endl;
	vector<int> bit(n+1,0);
	for(auto it:bit)
		cout << it << " ";
	cout << endl;
	REP(i,n)
		update(bit,i,x[i]);
	// cin >> q;
	// while(q--)
	// {
	// 	string a;
	// 	int l,r;
	// 	cin >> a >> l >> r;
	// 	if(a[0] == 'q')
	// 		cout << getsum(bit,l) - getsum(bit,r-1) << endl;
	// 	else
	// 		update(bit,r,l);
	// }
	return 0;
}
