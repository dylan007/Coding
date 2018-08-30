/*=======================
Author    : Shounak Dey
Filename  : 451b.cpp
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
	vector<int> arr(n);
	pair<int,int> ans;
	REP(i,n)
		cin >> arr[i];
	if(n==1)
		cout << "yes\n1 1\n";
	else{
		int curr=arr[0];
		int flag=0,count=0;
		ans.first = 0;
		flag = (arr[0]>arr[1]);
		FOR(i,1,n){
			if(arr[i]>curr){
				if(flag){
					ans.second = i-1;
					flag=0;
					count++;
				}
				curr = arr[i];
			}
			else{
				curr = arr[i];
				if(!flag)
					ans.first = i-1;
				flag=1;
			}
		}
		if(flag){
			ans.second = n-1;
			count++;
		}
		int f1,f2;
		f1 = f2 = 0;
		f1 = (ans.first>0 && arr[ans.second]>arr[ans.first-1]) || ans.first==0;
		f2 = (ans.second<(n-1) && arr[ans.first]<arr[ans.second+1]) || ans.second==(n-1);
		if(count>1)
			cout << "no" << endl;
		else if(count==0)
			cout << "yes\n1 1\n";
		else if(f1 && f2)
			cout << "yes" << endl << ans.first+1 << " " << ans.second+1 << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}
