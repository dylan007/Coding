/*=======================
Author    : Shounak Dey
Filename  : 999d.cpp
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
	ull n,m;
	cin >> n >> m;
	vector<ull> arr(n);
	ull sum=0;
	ull moves = (m-1)*n;
	moves /= 2;
	map<ull,ull> count;
	REP(i,n){
		arr[i] = arr[i]%m;
		sum += arr[i];
		if(count.find(arr[i]) != count.end())
			count[arr[i]]++;
		else
			count[arr[i]] = 1;
	}
	moves -= sum;
	ull req = n/m;
	map<ull,ull>::iterator it = count.begin();
	map<ull,set<ull>> countrev;
	while(it != count.end()){
		cout << it->first << " " << it->second << endl;
		if(countrev.find(it->second) != countrev.end())
			countrev[it->second].insert(it->first);
		else{
			countrev[it->second] = set<ull>();
			countrev[it->second].insert(it->first);
		}
	}
	map<ull,set<ull>>::iterator it = countrev.begin();
	while(it != countrev.end()){
		
	}
	while(1){

	}
	return 0;
}