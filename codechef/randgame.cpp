
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

int main()
{
	fast_io;
	auto f = [](ll n){
		ll c = 0;
		while(n>1){
			if(!(n&1))
				n >>= 1;
			else if(((n==1) || (n%4)==1))
				n--;
			else
				n++;
			c++;
			error(n);
		}
		return c+1;
	};
	auto mf = [](ll n){
		ll c = 0;
		if(n==1)
			return 0ll;
		if(!(n&1))
			n >>= 1;
		else if(((n==1) || (n%4)==1))
			n--;
		else
			n++;
		return n;
	};
	TEST{
		ll n;
		cin >> n;
		ll moves = f(n);
		if((moves&1)){
			cout << "Win" << endl << flush;
			ll c=0;
			while(1){
				ll nn = mf(n);
				if(!(c&1)){
					if((!(n&1)) && (nn==(n>>1)))
						cout << "/2" << endl << flush;
					else if((nn-n)==1)
						cout << "+1" << endl << flush;
					else
						cout << "-1" << endl << flush;
					n = nn;
				}
				else{
					string res;
					cin >> res;
					if(res=="GG")
						break;
					if(res=="WA")
						exit(0);
					if(res=="/2")
						n >>= 1;
					else if(res=="-1")
						n--;
					else
						n++;
					if(n==0)
						exit(0);
				}
				c++;
			}
		}
		else{
			cout << "Lose" << endl << flush;
			string res;
			cin >> res;
			if(res == "WA")
				exit(0);
		}
	}
	return 0;
}