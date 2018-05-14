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

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	vector<pair<int,int>> points;
	int x;
	int shift=INT_MAX;
	points.PB(MK(0,0));
	int my=0;
	int co=0;
	REP(i,n)
	{
		cin >> x;
		co += x;
		int px,py;
		px = points[i].first;
		py = points[i].second;
		shift = min(shift,py);
		points.PB(MK(px+x,py - (i%2)*x + (1 - i%2)*x));
	}
	shift = min(shift,points[n].second);
	if(shift < 0)
	{
		REP(i,n+1)
		{
			points[i].second -= shift;
			my = max(my,points[i].second);
		}
	}
	else
	{
		REP(i,n+1)
			my = max(my,points[i].second);
	}
	FOR(i,0,n+1)
		points[i].second = my-points[i].second;
	//REP(i,n+1)
	//	cout << points[i].first << " " << points[i].second << endl;
	vector<vector<int>> board(my+1,vector<int>(co,0));
	FOR(i,1,n+1)
	{
		int sx,sy;
		sx = points[i-1].first;
		sy = points[i-1].second-1+!(i%2);
		int c = points[i].first - points[i-1].first;
	//	cout << c << endl;
	//	cout << sy << " " << sx << endl;
		if(points[i].second>points[i-1].second)
		{
			while(c--)
			{
	//			cout << sy << " " << sx << " " << board[sy][sx]<< endl;
				board[sy][sx] = -1;
				sy++;sx++;
			}
		}
		else
		{
			while(c--)
			{
	//			cout << sy << " " << sx << " " << board[sy][sx] << endl;
				board[sy][sx] = 1;
				sy--;sx++;
			}
		}
	}
	REP(i,my)
	{
		REP(j,co)
		{
			if(board[i][j] == -1)
				cout << "\\";
			else if(board[i][j] == 1)
				cout << "/";
			else
				cout << " ";
			//cout << board[i][j];
		}
		cout << endl;
	}
	return 0;
}

