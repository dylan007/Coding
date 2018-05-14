/*=======================
Author    : Shounak Dey
Filename  : border2.cpp
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

vector<int> getvals(string out){
	vector<int> x;
	//cout << out << endl << endl;
	string s1="";
	string s2="";
	FOR(i,1,out.length()+1){
		int l1,l2;
		l1=i-1;
		l2=out.length()-i;
		s1 += out[l1];
		s2 = out[l2]+s2;
		int t = i;
		// // cout << t << " " << out.length() << endl << endl; 
		// while(t--){
		// 	// cout << l1 << " " << l2 << endl;
		// 	if(out[l1] != out[l2]){
		// 		break;
		// 	}
		// 	l1++;
		// 	l2++;
		// }
		// if(l1 == i){
		// 	x.PB(i);
		// 	// error(i);
		// }
		//cout << s1 << " " << s2 << endl;
		if(s1 == s2)
			x.PB(i);
	}
	return x;
}

int main()
{
	TEST{
		int n,q;
		cin >> n >> q;
		map<int,vector<int>> answers;
		string a;
		cin >> a;
		string out = "";
		FOR(i,1,a.length()+1){
			out += a[i-1];
			answers[i] = getvals(out);
		}
		while(q--){
			int x,y;
			cin >> x >> y;
			if(y > answers[x].size())
				cout << -1 << endl;
			else
				cout << answers[x][y-1] << endl;
		}
	}
	return 0;
}
