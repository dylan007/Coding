/*=======================
Author    : Shounak Dey
Filename  : waffle.cpp
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

int check(vector<vector<int>> arr,vector<int> cuts,int curr,int last, int tot){
	int count=0;
	int l,r;
	l = 0;
	r = 0;
	REP(k,cuts.size()){
		if(k==0)
			r = cuts[k]+1;
		else if(k==(cuts.size()-1)){
			l = cuts[k]+1;
			r = arr.size();
		}
		else{
			l = cuts[k]+1;
			r = cuts[k+1]+1;
		}
		FOR(i,l,r){
			FOR(j,last,curr+1){
				count += arr[i][j];
			}
		}
		// error(l,r,last,curr,count);
		// cout << endl;
		if(count != tot)
			return 0;
		count =0;
	}
	return 1;
}

int main()
{
	int T;
	cin >> T;
	for(int test=1;test<=T;test++){
		int r,c,h,v;
		cin >> r >> c >> h >> v;
		vector<vector<int>> arr(r,vector<int>(c,0));
		int tot=0;
		REP(i,r){
			string a;
			cin >> a;
			REP(j,a.length()){
				arr[i][j] = a[j]=='@';
				tot += arr[i][j];
			}
		}
		cout << "Case #" << test << ": ";
		int cust = (h+1)*(v+1);
		int flag=0;
		if(tot%cust != 0)
			cout << "IMPOSSIBLE" << endl;
		else if(tot == 0)
			cout << "POSSIBLE" << endl;
		else{
			tot /= cust;
			// cout << tot << endl;
			int curr=0;
			int horcut=0,vercut=0;
			vector<int> cuts;
			REP(i,r-1){
				REP(j,c){
					curr+=arr[i][j];
				}
				if(((curr%tot)==0) && ((curr/tot)==(v+1))){
					horcut++;
					curr=0;
					cuts.PB(i);
				}
			}
			// cout << "CUTS" << " ";
			// for(auto it:cuts)
			// 	cout << it << " ";
			// cout << endl;
			// cout << horcut << endl;
			if(horcut != h){
				cout << "IMPOSSIBLE" << endl;
				continue;
			}
			curr=0;
			int last=0;
			REP(i,c-1){
				REP(j,r){
					curr+=arr[j][i];
				}
				// error(i,curr);
				if(((curr%tot)==0) && ((curr/tot)==(h+1)) && check(arr,cuts,i,last,tot)){
					vercut++;
					curr=0;
					last = i+1;
				}
			}
			// cout << vercut << endl;
			if(vercut != v)
				cout << "IMPOSSIBLE" << endl;
			else
				cout << "POSSIBLE" << endl;
		}
	}
	return 0;
}
