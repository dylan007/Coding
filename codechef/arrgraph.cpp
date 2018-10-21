/*=======================
Author    : Shounak Dey
Filename  : arrgraph.cpp
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

int prime(int x){
	for(int i=2;i*i<=x;i++){
		if((x%i)==0)
			return 0;
	}
	return 1;
}

int main()
{
	vector<int> primes;
	FOR(i,2,51){
		if(prime(i))
			primes.PB(i);
	}
	// for(auto it:primes)
	// 	cout << it << " ";
	// cout << endl;
	TEST{
		int n;
		cin >> n;
		vector<int> arr(n);
		map<int,int> c;
		for(auto it: primes)
			c[it] = 0;
		REP(i,n){
			cin >> arr[i];
			int temp = arr[i];
			for(auto it:primes){
				if((arr[i]%it)==0)
					c[it]++;
			}
		}
		if(n==1){
			cout << 0 << endl;
			cout << arr[0] << endl;
			continue;
		}
		vector<int> degree(n);
		REP(i,n){
			FOR(j,i+1,n){
				if(gcd(arr[i],arr[j])==1){
					degree[i]++;
					degree[j]++;
				}
			}
		}	
		int f=0,index=-1;
		REP(i,n){
			if(degree[i]==0){
				f=1;
				index = i;
				break;
			}
		}
		if(f){
			for(int i=primes.size()-1;i>=0;i--){
				if((arr[index]%primes[i])!=0){
					arr[index] = primes[i];
					break;
				}
			}
		}
		cout << f << endl;
		for(auto it: arr)
			cout << it << " ";
		cout << endl;
	}
	return 0;
}