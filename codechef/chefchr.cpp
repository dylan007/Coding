/*=======================
Author    : Shounak Dey
Filename  : chefchr.cpp
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

int check(char x)
{
	return x=='c' || x=='h' || x=='e' || x=='f';
}

int calc(char x)
{
	if(x == 'c')
		return 0;
	if(x=='h')
		return 1;
	if(x=='e')
		return 2;
	if(x=='f')
		return 3;
}


int main()
{
	TEST{
		string a;
		cin >> a;
		int ans=0;
		if(a.length()<4)
		{
			cout << "normal" << endl;
			continue;
		}
		int flag=0;
		vector<int> c(4,0);
		for(int i=0;i<4;i++)
		{
			if(check(a[i])){
				c[calc(a[i])]++;
				flag |= (1 << calc(a[i]));
			}
		}
		ans += (flag==15);
		for(int i=4;i<a.length();i++)
		{
			if(check(a[i-4]))
			{
				int t = calc(a[i-4]);
				c[t]--;
				if(c[t]==0)
					flag ^= (1 << t);
			}
			if(check(a[i]))
			{
				int t = calc(a[i]);
				c[t]++;
				flag |= (1 << t);
			}
			ans += (flag == 15);
		}
		if(ans)
			cout << "lovely " << ans << endl;
		else
			cout << "normal" << endl;
	}
	return 0;
}
