/*=======================
Author    : Shounak Dey
Filename  : 988d.cpp
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
	int n;
	cin >> n;
	vector<int> arr(n);
	map<int,int> x;
	REP(i,n){
		cin >> arr[i];
		x[arr[i]] = 1;
	}
	int m=0;
	vector<int> ans(3);
	REP(i,n){
		int curr=0;
		int l,r;
		while(curr <= 31){
			l = arr[i] - (1<<curr);
			r = arr[i] + (1<<curr);
			int p=1;
			// cout << arr[i] << " " <<  l << " " << r << endl;
			if(x.find(l)!=x.end())
				p++;
			if(x.find(r)!=x.end())
				p++;
			if(p==3){
				ans[0] = arr[i];
				ans[1] = l;
				ans[2] = r;
				m = 3;
				break;
			}
			else if(p==2){
				if(p>m){
					ans[0] = arr[i];
					if(x.find(l) != x.end())
						ans[1] = l;
					else if(x.find(r) != x.end())
						ans[1] = r;
					m = p;
				}
			}
			else if(p>m){
				ans[0] = arr[i];
				m = 1;
			}
			curr++;
		}
		if(m == 3)
			break;
	}
	if(m==3)
		cout << 3 << endl << ans[0] << " " << ans[1] << " " << ans[2] << endl;
	else if(m==2)
		cout << 2 << endl << ans[0] << " " << ans[1] << endl;
	else
		cout << 1 << endl << ans[0] << endl;
	return 0;
}