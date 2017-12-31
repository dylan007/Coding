/*=======================
Author    : Shounak Dey
Filename  : 908b.cpp
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

int check(int x,int l)
{
	return x>=0 && x<l;
}


int solve(vector<string> board,string per,string comm)
{
	int startx,starty,endx,endy;
	int r,c;
	r = board.size();
	c = board[0].size();
	REP(i,r)
	{
		REP(j,c)
		{
			if(board[i][j] == 'S')
			{
				startx = i;
				starty = j;
			}
			else if(board[i][j] == 'E')
			{
				endx = i;
				endy = j;
			}
		}
	}
	int cx,cy;
	cx = startx;
	cy = starty;
	int i=0;
	while(check(cx,r) && check(cy,c))
	{
		int t = comm[i] - '0';
		i++;
		if(i>comm.length())
			return 0;
		if(per[t]=='U')
			cy--;
		else if(per[t]=='D')
			cy++;
		else if(per[t]=='L')
			cx--;
		else if(per[t]=='R')
			cx++;
		if(!check(cx,r) || !check(cy,c))
			return 0;
		//cout << cx << " " << cy << board[cx][cy]<< endl;
		if(board[cx][cy] == 'E')
			return 1;
		if(board[cx][cy] == '#')
			return 0;
	}
	return 0;
}

int main()
{
	int n,m;
	cin >> n >> m;
	vector<string> board;
	string comm;
	REP(i,n)
	{
		string temp;
		cin >> temp;
		board.PB(temp);
	}	
	cin >> comm;
	string per = "DLRU";
	int ans=0;
	while(1)
	{
		ans += solve(board,per,comm);
		//cout << per << endl;
		bool x = next_permutation(per.begin(),per.end());
		if(!x)
			break;
	}
	cout << ans << endl;
	return 0;
}
