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
		ull n,s;
		readul(n);readul(s);
		vector<ull> arr(n);
		ull m=INT_MAX;
		REP(i,n)
			readul(arr[i]);
		SORTV(arr);
		vector<ull> sum(n,0);
		sum[0] = arr[0];
		FOR(i,1,n)
			sum[i] = arr[i]+sum[i-1];
		ull ans,a,b,x;
		int flag=-1;
		for(int i=0;i<n;i++)
		{
			if(i==0)
			{
				if(s%n == 0)
				{
					x = s/n;
					if(x<=arr[0])
					{
						flag=x;
						break;
					}
				}
			}
			else
			{
				a = s-sum[i-1];
				cout << a << endl;
				b = n-i;
				if(a%b == 0)
				{
					x = a/b;
					if(x>arr[i-1] && x<=arr[i])
					{
						flag=x;
						break;
					}
				}
			}
		}
		cout << flag << endl;
	}
	return 0;
}

