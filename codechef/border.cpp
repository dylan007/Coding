/*=======================
Author    : Shounak Dey
Filename  : border.cpp
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

// int count(string a, string b, int m, int n)
// {
//     if ((a.length()==0 && b.length() == 0) || b.length() == 0)
//         return 1; 
//     if (a.length() == 0)
//         return 0;
//      if (a[a.length() - 1] == b[b.length() - 1])
//         return count(a, b, a.length() - 1, b.length() - 1) +
//                count(a, b, a.length() - 1, b.length());
//     else
//         return count(a, b, a.length() - 1, b.length());
// }

vector<int> getvals(string out){
	vector<int> x;
	//cout << out << endl << endl;
	FOR(i,1,out.length()+1){
		int l1,l2;
		l1=0;
		l2=out.length()-i;
		int t = i;
		// cout << t << " " << out.length() << endl << endl; 
		while(t--){
			// cout << l1 << " " << l2 << endl;
			if(out[l1] != out[l2]){
				break;
			}
			l1++;
			l2++;
		}
		if(l1 == i){
			x.PB(i);
			// error(i);
		}
	}
	return x;
}

int main()
{
	TEST{
		int n,q;
		cin >> n >> q;
		string s;
		cin >> s;
		vector<pair<int,int>> queries,list;
		map<pair<int,int>,int> answers;
		REP(i,q){
			int x,y;
			cin >> x >> y;
			x--;
			queries.PB(MK(x,y));
			answers[MK(x,y)] = 0;
			list.PB(MK(x,y));
		}
		sort(queries.begin(),queries.end());
		int l=0;
		string out="";
		vector<int> res;
		REP(i,q){
			pair<int,int> query = queries[i];
			if(l<query.first || i==0){
				while(l<=query.first){
					out += s[l];
					l++;
				}
				res = getvals(out);
			}
			//cout << out << endl;
			if(query.second > res.size())
				answers[query] = -1;
			else
				answers[query] = res[query.second-1];
		}
		REP(i,q){
			cout << answers[list[i]] << endl;
		}
	}
	return 0;
}
