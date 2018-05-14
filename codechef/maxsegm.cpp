//Shounak Dey
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
	TEST
	{
		int n;
		read(n);
		vector<int> c(n);
		vector<int> q;
		REP(i,n)
			read(c[i]);
		vector<int> w(n);
		REP(i,n)
		{
			read(w[i]);
			if(i!=0)
				w[i] += w[i-1];
		}
		vector<int> pos(n,-1);
		int m=-1,M=0;
		REP(i,n)
		{
			if(pos[c[i]]>=0)
			{
				error(i,pos[c[i]]);
				if(m>=0)
					M = max(M,w[i-1]-w[m]);
				else
					M = max(M,w[i-1]);
				m = max(pos[c[i]],m);
				pos[c[i]] = i;
			}
			else
				pos[c[i]] = i;
		}
		//error(m,M,w[n-1]);
		if(m>=0)
			M = max(M,w[n-1]-w[m]);
		else
			M = max(M,w[n-1]);
		cout << M << endl;
	}
	return 0;
}

