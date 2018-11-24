/*=======================
Author    : Shounak Dey
Filename  : hmappy1.cpp
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

void build(vector<int> arr,deque<int> &seg){
	int curr=0,state=0;
	REP(i,arr.size()){
		if(state!=arr[i] && !state){
			state = 1;
			curr = 1;
		}
		else if(state!=arr[i] && state){
			seg.push_back(curr);
			curr = 0;
			state = 0;
		}
		else if(state)
			curr++;
	}
	if(state)
		seg.push_back(curr);
	return;
}



int main()
{
	fast_io;
	int n,q,k;
	cin >> n >> q >> k;
	vector<int> arr(n);
	REP(i,n)
		cin >> arr[i];
	string query;
	cin >> query;
	deque<int> seg;
	build(arr,seg);
	int pos = n-1;
	map<int,int> ans;
	for(auto it:seg){
		if(ans.find(it) != ans.end())
			ans[it]++;
		else
			ans[it] = 1;
	}
	REP(i,q){
		// error(i);
		// cout << "query : " << query[i] << endl;
		if(query[i]=='!'){
			if(arr[pos]){
				int front = (pos + 1)%n;
				if(arr[front]==0){
					seg.push_front(1);
					if(ans.find(1) == ans.end())
						ans[1] = 1;
					else
						ans[1]++;
				}else{
					ans[seg[0]]--;
					if(ans[seg[0]]==0)
						ans.erase(seg[0]);
					seg[0]++;
					if(ans.find(seg[0])==ans.end())
						ans[seg[0]]=1;
					else
						ans[seg[0]]++;
				}
				ans[seg.back()]--;
				if(ans[seg.back()]==0)
					ans.erase(seg.back());
				seg[seg.size()-1]--;
				if(seg.back()==0)
					seg.pop_back();
				else{
					if(ans.find(seg.back()) == ans.end())
						ans[seg.back()]=1;
					else
						ans[seg.back()]++;
				}
			}
			pos = (pos - 1 + n)%n;
			// cout << "segment :"; 
			// for(auto it:seg)
			// 	cout << it << " ";
			// cout  << endl;
		}
		else{
			map<int,int>::iterator it = ans.lower_bound(k);
			if(it == ans.begin()){
				if(ans.size()==0)
					cout << 0 << endl;
				else
					cout << k << endl;
				continue;
			}
			else if(it == ans.end())
				it--;

			cout << it->first << endl;
		}
	}
	return 0;
}