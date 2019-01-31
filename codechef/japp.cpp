/*=======================
Author    : Shounak Dey
Filename  : japp.cpp
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
	TEST{
		ll q;
		cin >> q;
		ll n;
		cin >> n;
		if(q==2){
			vector<vector<ll>> arr(n,vector<ll>(n,0));
			ll curr=1;
			ll x = n-1,y=0;
			REP(i,n-1){
				ll x=0,y=i;
				while(y>=0 && x<n){
					// error(x,y);
					arr[x][y] = curr;
					curr++;
					x++;
					y--;
				}
				x=n-i-1;y=n-1;
				while(y>=0 && x<n){
					// error(x,y);
					arr[x][y] = curr;
					curr++;
					x++;y--;
				}
			}
			// error(x,y);
			x = 0;y=n-1;
			while(y>=0 && x<n){
				arr[x][y] = curr;
				curr++;
				x++;y--;
			}
			REP(i,n){
				REP(j,n)
					cout << arr[i][j] << " ";
				cout << endl;
			}
		}
		else{
			vector<vector<ll>> arr(n,vector<ll>(n,0));
			ll l=0,curr=1,p=n;
			while(l<((n/2) + !(n&1))){
				if(l&1){
					FOR(i,l,n-l-1)
						arr[i][l] = curr + (i-l)*4;
					curr++;
					FOR(i,l,n-l-1)
						arr[n-l-1][i] = curr + (i-l)*4;
					curr++;
					for(ll i=(n-l-1);i>l;i--)
						arr[i][n-l-1] = curr + (n-l-1 - i)*4;
					curr++;
					for(ll i=(n-l-1);i>l;i--)
						arr[l][i] = curr + (n-l-1 - i)*4;
					curr -= 3;
					curr += 4*(p-1);
					p -= 2;
				}
				else{
					FOR(i,l,n-l-1)
						arr[l][i] = curr + (i-l)*4;
					curr++;
					FOR(i,l,n-l-1)
						arr[i][n-l-1] = curr + (i-l)*4;
					curr++;
					for(ll i=(n-l-1);i>l;i--)
						arr[n-l-1][i] = curr + (n-l-1 - i)*4;
					curr++;
					for(ll i=(n-l-1);i>l;i--)
						arr[i][l] = curr + (n-l-1 - i)*4;
					curr -= 3;
					curr += 4*(p-1);
					p -= 2;
				}
				l++;
			}
			if(n&1)
				arr[n/2][n/2] = n*n;
			REP(i,n){
				REP(j,n) cout << arr[i][j] << " ";
				cout << endl;
			}
		}
	}
	return 0;
}