/*=======================
Author    : Shounak Dey
Filename  : rrating.cpp
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
	priority_queue<int> maxq;
	priority_queue<int,vector<int>,greater<int>> minq;
	int n=0;
	TEST{
		int c,x;
		cin >> c;
		if(c==1){
			cin >> x;
			int kcurr=n/3;
			n++;
			int k = n/3;
			// error(k,kcurr,x);
			if(k>kcurr){
				maxq.push(x);
				// cout << maxq.top() << " transferred from maxq to minq" << endl;
				minq.push(maxq.top());
				maxq.pop();
			}
			else{
				if(minq.empty()){
					maxq.push(x);
					continue;
				}
				if(x>minq.top()){
					// cout << minq.top()  << " transferred from minq to maxq" << endl;
					maxq.push(minq.top());
					minq.pop();
					minq.push(x);
				}
				else{
					maxq.push(x);
				}
			}
		}
		else{
			int k = n/3;
			if(k==0){
				cout << "No reviews yet" << endl;
				continue;
			}
			cout << minq.top()<< endl;
		}
	}
	return 0;
}