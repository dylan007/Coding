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
	double a,v,l,d,w;
	cin >> a >> v;
	cin >> l >> d >> w;
	double t1,t2;
	w = min(w,v);
	double v1 = (2*a*d + w*w)/2;
	v1 = sqrt(v1);
	if(v1>v)
	{
		t1 = (v-w)/a + (v/a) + (d-((2*v*v - w*w)/(2*a)))/v;
		//error(t1,v1);
		//cout << 1 << endl;
	}
	else
	{
		t1 = v1/a + (v1-w)/a;
		//error(t1,v1);
		//cout << 2 << endl;
	}
	if(w==v)
		t2 = (l-d)/w;
	else
	{
		l -= d;
		double v2 = sqrt(w*w + 2*a*l);
		if(v2<=v)
			t2 = (v2-w)/a;
		else
			t2 = (v-w)/a + ((l-(v*v - w*w)/(2*a))/v);
		//cout << t2 << endl;
		//cout << "else" << endl;
	}
	printf("%.6f\n",t1+t2);
	return 0;
}

