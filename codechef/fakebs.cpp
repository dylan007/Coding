/*=======================
Author    : Shounak Dey
Filename  : fakebs.cpp
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

pair<int,int> solve(vector<int> arr,int pos,pair<int,int> &enc){
	int start = 1,end=arr.size();
	int mid;
	int x = arr[pos-1];
	pair<int,int> ans;
	ans.first = 0;
	ans.second = 0;
	while(start <= end){
		mid = (start + end)/2;
		// error(start,end,mid,arr[mid-1]);
		// cout << endl;
		if(arr[mid-1] == x)
			return ans;
		else if(mid > pos){
			if(arr[mid-1] < x)
				ans.second++;
			else
				enc.second++;
			end = mid-1;
		}
		else{
			if(arr[mid-1] > x)
				ans.first++;
			else
				enc.first++;
			start = mid+1;
		}
	}
	return ans;
}

int main()
{
	TEST{
		int n,q;
		cin >> n >> q;
		vector<int> arr(n);
		map<int,int> posx;
		map<int,int> answered;
		REP(i,n){
			cin >> arr[i];
			answered[arr[i]] = -2;
			posx[arr[i]] = i+1;
		}
		vector<int> sorted = arr;
		SORTV(sorted);
		unordered_map<int,int> sortpos;
		// sortpos.setreserve();
		REP(i,n)
			sortpos[sorted[i]] = i+1;
		while(q--){
			int x;
			cin >> x;
			if(answered[x] >= -1){
				cout << answered[x] << endl;
				continue;
			}
			pair<int,int> ans,enc;
			enc.first = 0;
			enc.second = 0;
			ans.first = 0;
			ans.second = 0;
			int start = 1,end = n,pos = posx[x];
			while(start <= end){
				int mid = (start + end)/2;
				// error(start,end,mid,arr[mid-1]);
				// cout << endl;
				if(arr[mid-1] == x)
					break;
				else if(mid > pos){
					if(arr[mid-1] < x)
						ans.second++;
					else
						enc.second++;
					end = mid-1;
				}
				else{
					if(arr[mid-1] > x)
						ans.first++;
					else
						enc.first++;
					start = mid+1;
				}			
			}
			//ans = solve(arr,posx[x],enc);
			int l = sortpos[x]-1-enc.first;
			int r = n-sortpos[x]-enc.second;
			if((l<ans.first) || (r<ans.second)){
				cout << -1 << endl;
				answered[x] = -1;
			}
			else{
				cout << max(ans.first,ans.second) << endl;
				answered[x] = max(ans.first,ans.second);
			}
		}
	}
	return 0;
}
