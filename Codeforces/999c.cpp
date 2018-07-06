/*=======================
Author    : Shounak Dey
Filename  : 999c.cpp
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
	int n,k;
	cin >> n >> k;
	string a;
	cin >> a;
	map<int,vector<int>> pos;
	REP(i,a.length()){
		int p = a[i]-'a';
		if(pos.find(p) != pos.end())
			pos[p].PB(i);
		else{
			pos[p] = vector<int>();
			pos[p].PB(i);
		}
	}
	int ele=25;
	k = n-k;
	vector<pair<int,int>> out;
	while(k>0){
		int curr=0;
		if(pos.find(ele) == pos.end()){
			ele--;
			continue;
		}
		// for(auto it:pos[ele])
			// cout << it << " ";
		// cout << endl;
		// cout << ele << endl;
		curr = pos[ele].size()-1;
		while(curr>=0){
			out.PB(MK(pos[ele][curr],ele));
			// cout << pos[ele][curr] << " ";
			curr--;
			k--;
			if(k==0)
				break;
		}
		// cout << endl;
		ele--;
	}
	SORTV(out);
	string output="";
	REP(i,out.size()){
		// cout << out[i].second << endl;
		output += char(int('a')+out[i].second);
	}
	cout << output << endl;
	return 0;
}