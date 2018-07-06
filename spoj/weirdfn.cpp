/*=======================
Author    : Shounak Dey
Filename  : weirdfn.cpp
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

#define MOD 1000000007

int main()
{
	TEST{
		ull n,a,b,c;
		cin >> a >> b >> c >> n;
		priority_queue<ull> maxh; //left half of elements
		priority_queue<ull,vector<ull>,greater<ull>> minh; // right half of elements
		ull ans=1;
		maxh.push(1);
		for(ull i=1;i<n;i++){
			ull x,temp;
			if(i%2){//odd elements in the current sequence
			 	x = maxh.top();
				temp = ((a*x)%MOD + (b*(i+1))%MOD + c)%MOD;
				if(temp < maxh.top()){
					minh.push(maxh.top());
					maxh.pop();
					maxh.push(temp);
				}
				else{
					minh.push(temp);
				}
			}
			else{// even elements in the current sequence
				x = maxh.top();
				temp = ((a*x)%MOD + (b*(i+1))%MOD + c)%MOD;
				if(temp > minh.top()){
					maxh.push(minh.top());
					minh.pop();
					minh.push(temp);
				}
				else
					maxh.push(temp);
			}
			// error(x,temp,minh.size(),maxh.size(),minh.top(),maxh.top());
			// cout << endl;
			ans += temp;
		}
		cout << ans << endl;
	}
	return 0;
}