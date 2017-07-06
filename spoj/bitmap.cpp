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
#define traverse(a) for(auto:a)

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

int dist[200][200]={0};

void bfs(int x,int y,int depth,int n,int m,vector<vector<int> > v)
{
	error(x,y,depth);
	cout << endl;
	if(x<0 || x>=m)
		return;
	if(y<0 || y>=n)
		return;
	if(v[x][y])
		return;
	if(depth>(n+m))
		return;
	v[x][y]++;
	dist[x][y] = min(dist[x][y],depth);
	bfs(x,y+1,depth+1,n,m,v);
	bfs(x,y-1,depth+1,n,m,v);
	bfs(x-1,y,depth+1,n,m,v);
	bfs(x+1,y,depth+1,n,m,v);
	return;
}

int main()
{
	TEST
	{
		int n,m;
		read(n);read(m);
		vector< vector<int> > bits,v;
		vector<int> temp;
		int x;
		string a;
		REP(i,n)
		{
			bits.PB(temp);
			v.PB(temp);
			cin >> a;
			REP(j,m)
			{
				v[i].PB(0);
				bits[i].PB(int(a[i])-'0');
			}
		}
		REP(i,n)
		{
			REP(j,m)
			{
				if(bits[i][j])
				{
					bfs(i,j+1,1,n,m,v);
					bfs(i,j-1,1,n,m,v);
					bfs(i-1,j,1,n,m,v);
					bfs(i+1,j,1,n,m,v);
				}
			}
		}
		REP(i,n)
		{
			REP(j,m)
				cout << dist[i][j] << " ";
			cout << endl;
		}
	}
	return 0;
}

