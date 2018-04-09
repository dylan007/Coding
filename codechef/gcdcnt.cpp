/*=======================
Author    : Shounak Dey
Filename  : gcdcnt.cpp
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

int pos;

void build(vector<vector<int>> &stree,vector<vector<int>> arr,int start,int end,int node){
	cout << node << " " << start << " " << end << endl;
	if(start == end){
		REP(i,pos)
			stree[node][i] = arr[start][i];
	}
	else{
		int mid = (start+end)/2;
		build(stree,arr,start,mid,2*node);
		build(stree,arr,mid+1,end,2*node+1);
		REP(i,pos){
			stree[node][i] = stree[2*node][i] + stree[2*node+1][i];
		}
	}
}

void update(vector<vector<int>> &stree,vector<int> val,int node,int start,int end,int id){
	if(start == end){
		REP(i,pos){
			stree[node][i] += val[i];
		}
	}
	else{
		int mid = (start+end)/2;
		if(start<=id && id<=mid)
			update(stree,val,2*node,start,mid,id);
		else
			update(stree,val,2*node+1,mid+1,end,id);
		REP(i,pos){
			stree[node][i] = stree[2*node][i] + stree[2*node+1][i];
		}
	}
}


int query(vector<vector<int>> stree,vector<int> val,int node,int start,int end,int l,int r){
	if(r<start || end<l)
		return 0;
	if(l<=start && end<=r){
		
	}
}

int main()
{
	int n,q;
	read(n);
	vector<int> flag(1001,0),primes;
	map<int,int> index;
	//sieve
	pos=0;
	FOR(i,2,1001){
		if(flag[i]==0)
		{
			for(int j=2*i;j<=1000;j+=i){
				flag[j]=1;
			}
			index[i] = pos;
			primes.PB(i);
			pos++;
		}
	}
	vector<vector<int>> arr(n,vector<int>(pos,0));
	REP(i,n){
		int x;
		cin >> x;
		REP(j,pos){
			if(x%primes[j] == 0)
				arr[i][j]++;
		}
	}
	vector<vector<int>> stree(2*n,vector<int>(pos,0));
	build(stree,arr,0,n-1,1);
	REP(i,2*n){
		REP(j,10){
			cout << stree[i][j] << " ";
		}
		cout << endl;
	}
	read(q);
	while(q--){
		int x,l,r,g;
		cin >> x >> l >> r;
		if(x==2)
		{
			cin >> g;
			vector<int> val(pos,0);
			REP(i,pos){
				if(g%primes[i] == 0)
					val[i]++;
			}
			cout << query(stree,val,1,0,n-1,l,r);
		}
		else{
			vector<int> val(pos,0);
			REP(i,pos){
				if(r%primes[i] == 0){
					cout << primes[i] << endl;
					val[i]++;
				}
			}
			l--;
			REP(i,pos){
				val[i] = val[i]-arr[l][i];
				arr[l][i] += val[i];
			}
			REP(i,10)
				cout << val[i] << " ";
			cout <<  endl;
			update(stree,val,1,0,n-1,l);
			REP(i,2*n){
				REP(j,10){
					cout << stree[i][j] << " ";
				}
				cout << endl;
			}
		}
	}
	return 0;
}
