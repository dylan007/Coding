/*=======================
Author    : Shounak Dey
Filename  : 988c.cpp
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
	vector<vector<int>> arr(n,vector<int>());
	map<int,vector<pair<int,int>>> s;
	int flag=0,c=0;
	REP(i,n){
		int l;
		cin >> l;
		int x;
		int sum=0;
		REP(j,l){
			cin >> x;
			arr[i].PB(x);
			sum += arr[i][j];
		}
		map<int,pair<int,int>> p;
		REP(j,l){
			int temp = sum - arr[i][j];
			if(p.find(temp) == p.end()){
				p[temp] = MK(i+1,j+1);
			}
		}
		map<int,pair<int,int>>::iterator it = p.begin();
		while(it != p.end()){
			if(s.find(it->first) != s.end()){
				s[it->first].PB(it->second);
				flag=1;
				c=it->first;
			}
			else{
				vector<pair<int,int>> temp;
				temp.PB(it->second);
				s[it->first] = temp;
			}
			it++;
		}
		if(flag)
			break;
	}
	if(flag){
		cout << "YES" << endl;
		vector<pair<int,int>> temp = s[c];
		cout << temp[0].first << " " << temp[0].second << endl;
		cout << temp[1].first << " " << temp[1].second << endl;
	}
	else
		cout << "NO" << endl;
	return 0;
}