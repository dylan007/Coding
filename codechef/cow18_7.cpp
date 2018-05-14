/*=======================
Author    : Shounak Dey
Filename  : cow18_7.cpp
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
	TEST{
		priority_queue<pair<int,int>> left,right;
		int x,n,k;
		cin >> n >> k;
		vector<vector<int>> val;
		vector<int> temp;
		REP(i,n)
		{
			val.PB(temp);
			int m;
			cin >> m;
			while(m--)
			{
				cin >> x;
				val[i].PB(x);
			}
			left.push(MK(val[i][0],i));
			right.push(MK(val[i][val[i].size()-1],i));
		}
		// priority_queue<pair<int,int>> tempq = left;
		// while(!tempq.empty())
		// {
		// 	cout << tempq.top().first << " " << tempq.top().second << endl;
		// 	tempq.pop();
		// }
		// tempq = right;
		// while(!tempq.empty())
		// {
		// 	cout << tempq.top().first << " " << tempq.top().second << endl;
		// 	tempq.pop();
		// }
		int ans=0;
		while(k--)
		{
			int l,r;
			l = left.top().first;
			r = right.top().first;
			if(l>r)
			{
				ans += l;
				//cout << l << endl;
				int index = left.top().second;
				if(val[index].size()!=0)
					left.push(MK(val[index][1],index));
				val[index].erase(val[index].begin());
				left.pop();
			}		
			else
			{
				ans += r;
				//cout << r << endl;
				int index = right.top().second;
				if(val[index].size()!=0)
					right.push(MK(val[index][1],index));
				val[index].erase(val[index].begin() + val[index].size()-1);
				right.pop();
			}
		}
		cout << ans << endl;
	}
	return 0;
}
