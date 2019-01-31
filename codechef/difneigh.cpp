/*=======================
Author    : Shounak Dey
Filename  : difneigh.cpp
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
#define popc(a) __builtin_popcount(a) // count set bits
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

#define MAXN 50

int main()
{
	fast_io;
	ll arr[MAXN+10][MAXN+10];
	for(ll i=0;i<MAXN;i+=2){
		ll curr=(max(0ll,i>>1)&1)==0?1:3;
		for(ll j=0;(j+1)<MAXN;j+=2){
			arr[i][j] = arr[i][j+1] = curr;
			curr = (curr==1)?3:1;
		}
	}
	for(ll i=1;i<MAXN;i+=2){
		ll curr=0;
		arr[i][0] = (!((i>>1)&1))*2 + 2;
		curr = arr[i][0]==4?2:4;
		for(ll j=1;j<MAXN;j+=2){
			arr[i][j] = arr[i][j+1] = curr;
			curr = (curr==2)?4:2;
		}
	}
	// REP(i,MAXN){
	// 	REP(j,MAXN)
	// 		cout << arr[i][j] << " ";
	// 	cout << endl;
	// }
	TEST{
		ll n,m,row,col;
		cin >> row >> col;
		n = min(row,col);
		m = max(row,col);
		if(n<3){	
			vector<vector<ll>> board(n,vector<ll>(m,-1));
			vector<vector<vector<pair<ll,ll>>>> adj(n,vector<vector<pair<ll,ll>>>(m,vector<pair<ll,ll>>())); 
			REP(i,n){
				REP(j,m){
					if(i>0 && (j+1)<m){
						adj[i][j].PB({i-1,j+1});
						adj[i-1][j+1].PB({i,j});
					}
					if((i+1)<n && (j+1)<m){
						adj[i][j].PB({i+1,j+1});
						adj[i+1][j+1].PB({i,j});
					}
					if((j+2)<m){
						adj[i][j].PB({i,j+2});
						adj[i][j+2].PB({i,j});
					}
					if((i+2)<n){
						adj[i][j].PB({i+2,j});
						adj[i+2][j].PB({i,j});
					}
					if((i-2)>=0){
						adj[i][j].PB({i-2,j});
						adj[i-2][j].PB({i,j});
					}
				}
			}
			// for(auto it:adj)
			// 	cout << it.first.first << " " << it.first.second << endl;
			ll c = 0,ans=0;
			REP(i,n){
				REP(j,m){
					if(board[i][j]==-1){
						c++;
						queue<pair<ll,ll>> q;
						q.push({i,j});
						while(!q.empty()){
							unordered_set<ll> x;
							pair<ll,ll> curr = q.front();
							q.pop();
							ll m = -1;
							for(auto it:adj[curr.first][curr.second]){
								if(board[it.first][it.second]!=-1)
									x.insert(board[it.first][it.second]);
								else
									q.push({it.first,it.second});
								m = max(board[it.first][it.second],m);
							}
							// else
							// 	cout << "No neighbours" << endl;
							if(m>-1){
								ll p = -1;
								REP(i,m+1){
									if(x.find(i) == x.end()){
										p = i;
										break;
									}
								}
								if(p==-1)
									p = m+1;
								board[curr.first][curr.second]=p;
							}
							else
								board[curr.first][curr.second]=0;
						}
					}
					if(c==2)
						break;
				}
			}
			REP(i,n){
				REP(j,m)
					ans = max(ans,board[i][j]);
			}
			cout << ans+1 << endl;
			if(n==row && m==col){
				REP(i,n){
					REP(j,m)
						cout << board[i][j]+1 << " ";
					cout << endl;
				}
			}
			else{
				REP(i,m){
					REP(j,n)
						cout << board[j][i]+1 << " ";
					cout << endl;
				}
			}
		}
		else{
			cout << 4 << endl;
			REP(i,row){
				REP(j,col)
					cout << arr[i][j] << " ";
				cout << endl;
			}
		}
	}
	return 0;
}