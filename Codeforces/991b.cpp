/*=======================
Author    : Shounak Dey
Filename  : 991b.cpp
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
	double n;
	cin >> n;
	set<double> x;
	vector<double> arr(n);
	map<double,double> count;
	double sum=0;
	REP(i,n){
		cin >> arr[i];
		if(count.find(arr[i]) != count.end())
			count[arr[i]]++;
		else{
			x.insert(arr[i]);
			count[arr[i]] = 1;
		}
		sum += arr[i];
	}
	double ans=0;
	while(1){
		double temp = sum/n;
		if(temp>=4.5)
			break;
		ans++;
		double p = *(x.begin());
		// cout << p  << " " << temp << endl;
		sum -= p;
		sum += 5;
		count[p]--;
		if(count[p]==0){
			x.erase(p);
			if(count.find(5) == count.end()){
				x.insert(5);
				count[5] = 1;
			}
			else
				count[5]++;
		}
	}
	cout << ans << endl;
	return 0;
}