//Shounak Dey
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

int n,m,t,curr;
map<pair<int,int> ,int> vis;
int ans=0;


void dfs(pair<int,int> point)
{
	int x = point.first;
	int y = point.second;
	if(x<0 || x>=n)
		return;
	if(y<0 || y>=m)
		return;
	if(vis.find(point)==vis.end())
		return;
	if(vis[point]>0)
		return;
	vis[MK(x,y)]=curr;
	dfs(MK(x+1,y));
	dfs(MK(x-1,y));
	dfs(MK(x,y+1));
	dfs(MK(x,y-1));
	return ;
}

void vals(int x,int y)
{
	if(x<0 || x>=n)
		return ;
	if(y<0 || y>=m)
		return ;
	if(vis.find(MK(x,y))==vis.end())
		return ;
	if(vis[MK(x,y)] != curr)
		return ;
	vis[MK(x,y)] = 0-curr;
	if(x>0 && (vis.find(MK(x-1,y)) != vis.end()))
		ans += !(abs(vis[MK(x-1,y)])==curr);
	else
		ans++;
	if(x<(n-1) && (vis.find(MK(x+1,y)) != vis.end()))
		ans += !(abs(vis[MK(x+1,y)])==curr);
	else
		ans++;
	if(y>0 && (vis.find(MK(x,y-1)) != vis.end()))
		ans += !(abs(vis[MK(x,y-1)])==curr);
	else
		ans++;
	if(y<(m-1) && (vis.find(MK(x,y+1)) != vis.end()))
		ans += !(abs(vis[MK(x,y+1)])==curr);
	else
		ans++;
	//cout << x << " " << y << " " << ans << endl << endl;
	vals(x+1,y);
	vals(x-1,y);
	vals(x,y+1);
	vals(x,y-1);
	return;
}

int main()
{
	curr=0;
	read(n);read(m);read(t);
	vector<pair<int,int> > p;
	int x,y;
	for(int i=0;i<t;i++)
	{
		read(x);
		read(y);
		//p.PB(MK(x-1,y-1));
		//vis[p[i]]=0
		vis[MK(x-1,y-1)] = 0;
	}
	int m = 0;
	for(auto iter : vis)
	{
		if(vis[iter.first] == 0)
		{
			ans=0;
			curr++;
			dfs(iter.first);
			vals(iter.first.first,iter.first.second);
			m = max(m,ans);
			//cout << ans << endl;
		}
		//cout << iter.first.first << " " << iter.first.second << " " << vis[iter.first] << endl;
	}
	//for(auto iter : vis)
	//	cout << vis[iter.first] << endl;
	cout << m << endl;
	return 0;
}

