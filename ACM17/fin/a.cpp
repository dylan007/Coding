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

int check(int a[3],int b[3])
{
	int ans=0;	
	for(int i=0;i<3;i++)
		ans |= b[i]>a[i];
	if(ans)
		return 1;
	ans = 0;
	for(int i=0;i<3;i++)
		ans |= a[i]>b[i];
	if(ans)
		return 2;
	return ans;
}

int main()
{
	TEST{
		int a[3],b[3],c[3];
		for(int i=0;i<3;i++)
			cin >> a[i];
		for(int i=0;i<3;i++)
			cin >> b[i];
		for(int i=0;i<3;i++)
			cin >> c[i];
		if(check(a,b)==1)
		{
			if(check(c,a)==1 || check(b,c)==1 || ((check(a,c)==1)&&(check(c,b)==1)))
				cout << "yes" << endl;
			else
				cout << "no" << endl;
		}
		else if(check(a,b)==2)
		{
			if(check(c,b)==1 || check(a,c)==1 || ((check(b,c)==1)&&(check(c,a)==1)))
				cout << "yes" << endl;
			else
				cout << "no" << endl;
		}	
		else
			cout << "no" << endl;
	}		
	return 0;
}

