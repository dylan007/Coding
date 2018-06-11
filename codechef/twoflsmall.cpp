/*=======================
Author    : Shounak Dey
Filename  : twoflsmall.cpp
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
	int n,m;
	cin >> n >> m;
	vector<vector<int>> arr(n,vector<int>(m));
	set<int> x;
	map<int,int> count;
	REP(i,n){
		REP(j,m){
			cin >> arr[i][j];
			if(x.find(arr[i][j]) == x.end()){
				x.insert(arr[i][j]);
				count[arr[i][j]] = 1;
			}
			else
				count[arr[i][j]]++;
		}
	}
	vector<int> ele;
	set<int>::iterator it = x.begin();
	vector<pair<int,int>> sarr;
	while(it != x.end()){
		sarr.PB(MK(*it,count[*it]));
		it++;
	}
	sort(sarr.begin(),sarr.end(),[](const auto&lhs,const auto &rhs){
		return lhs.second > rhs.second;
	});
	// for(auto it:sarr)
	// 	cout << it.first << " " << it.second << endl;

	for(auto it:sarr)
		ele.PB(it.first);
	// for(auto p:ele)
	// 	cout << p << " ";
	// cout << endl;
	int ans=0;
	if(ele.size()==1){
		cout << n*m << endl;
		return 0;
	}
	REP(i,ele.size()-1){
		FOR(j,i+1,ele.size()){
			int c = count[ele[i]] + count[ele[j]];
			if(c<=ans)
				continue;
			vector<vector<int>> grid(n,vector<int>(m,0));
			REP(l,n){
				REP(r,m)
					grid[l][r] = (arr[l][r]==ele[i] || arr[l][r]==ele[j]);
			}		
			vector<vector<int>> visited(n,vector<int>(m,0));
			int temp=0;
			REP(l,n){
				REP(r,m){
					if(c<=ans)
						break;
					if(!visited[l][r] && grid[l][r]){
						queue<pair<int,int>> q;
						q.push(MK(l,r));
						int a,b;
						temp=0;
						while(!q.empty()){
							pair<int,int> tp = q.front();
							q.pop();
							a = tp.first;
							b = tp.second;
							if(visited[a][b])
								continue;
							temp++;
							// cout << i << " " << j << endl;
							visited[a][b] = 1;
							if(b<(m-1) && grid[a][b+1] && !visited[a][b+1])
								q.push(MK(a,b+1));
							if(b>0 && grid[a][b-1] && !visited[a][b-1])
								q.push(MK(a,b-1));
							if(a>0 && grid[a-1][b] && !visited[a-1][b])
								q.push(MK(a-1,b));
							if(a<(n-1) && grid[a+1][b] && !visited[a+1][b])
								q.push(MK(a+1,b));
						}
						ans = max(ans,temp);	
						c -= temp;
					}
					// error(i,j,ans);
				}
				if(c <= ans)
					break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}