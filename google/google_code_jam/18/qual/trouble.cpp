/*=======================
Author    : Shounak Dey
Filename  : trouble.cpp
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
	int T;
	read(T);
	for(int test=1;test<=T;test++){
		cout << "Case #" << test << ": ";
		int n;
		read(n);
		int x;
		vector<int> p1,p2;
		REP(i,n){
			read(x);
			if(i%2 == 0)
				p1.PB(x);
			else
				p2.PB(x);
		}
		// for(auto it:p1)
		// 	cout << it << " ";
		// cout << endl;
		// for(auto it:p2)
		// 	cout << it << " ";
		// cout << endl;
		SORTV(p1);
		SORTV(p2);
		//SORTV(p3);
		vector<int> arr;
		REP(i,n){
			if(i%2 == 0)
				arr.PB(p1[i/2]);
			else
				arr.PB(p2[i/2]);
		}
		int index=-1;
		REP(i,n-1){
			if(arr[i]>arr[i+1]){
				index = i;
				break;
			}
		}
		// for(auto it:arr)
		// 	cout << it << endl;
		if(index>=0)
			cout << index << endl;
		else
			cout << "OK" << endl;
	}	
	return 0;
}
