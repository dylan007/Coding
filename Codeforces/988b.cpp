/*=======================
Author    : Shounak Dey
Filename  : 988b.cpp
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
	map<int,string> x;
	vector<string> arr;
	int flag=1;
	vector<string> sarr;
	map<string,int> count;
	REP(i,n){
		string a;
		cin >> a;
		int l = a.length();
		if(x.find(l) != x.end()){
			if(x[l] != a){
				flag=0;
				break;
			}
		}
		else{
			x[l] = a;
		}
		if(count.find(a) != count.end()){
			count[a]++;
		}
		else{
			count[a] = 1;
		}
		arr.PB(a);
	}
	if(!flag)
		cout << "NO" << endl;
	else{
		map<int,string>::iterator it = x.begin();
		while(it != x.end()){
			sarr.PB(it->second);
			it++;
		}
		flag=1;
		FOR(i,1,sarr.size()){
			if(sarr[i].find(sarr[i-1]) != string::npos){
				continue;
			}
			else{
				flag=0;
				break;
			}
		}
		if(!flag)
			cout << "NO" << endl;
		else{
			cout << "YES" << endl;
			REP(i,sarr.size()){
				REP(j,count[sarr[i]])
					cout << sarr[i] << endl;
			}
		}
	}
	return 0;
}