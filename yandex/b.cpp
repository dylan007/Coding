/*=======================
Author    : Shounak Dey
Filename  : b.cpp
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
	vector<int> temp;
	vector<vector<int>> arr(n,vector<int>(n,0));
	vector<vector<int>> perms(2*n,vector<int>(n,0));
	vector<vector<int>> pos(n*n,temp);
	vector<vector<int>> index(n*n,temp);
	REP(i,2*n){
		REP(j,n){
			cin >> perms[i][j];
			perms[i][j]--;
			pos[perms[i][j]].PB(j);
			index[perms[i][j]].PB(i);
		}
	}
	int start=-1;
	REP(i,n*n){
		if(pos[i][0]==pos[i][1] && pos[i][0]==0){
			start = i;
			break;
		}
	}
	int ind = index[start][0];
	REP(i,n){
		arr[0][i] = perms[ind][i];
	}
	ind = index[start][1];
	REP(i,n){
		arr[i][0] = perms[ind][i];
	}
	FOR(i,1,n){
		int p;
		if(pos[arr[0][i]][0]==0)
			p = index[arr[0][i]][0];
		else
			p = index[arr[0][i]][1];
		FOR(j,1,n){
			arr[j][i] = perms[p][j];
		}
	}
	REP(i,n)
	{
		REP(j,n)
			cout << arr[i][j]+1 << " ";
	}
	return 0;
}

