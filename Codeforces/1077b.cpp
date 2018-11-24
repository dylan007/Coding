/*=======================
Author    : Shounak Dey
Filename  : 1077b.cpp
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

int check(vector<int> dis){
	for(auto it:dis){
		if(it==1)
			return 1;
	}
	return 0;
}

int main()
{
	fast_io;
	int n;
	cin >> n;
	vector<int> arr(n);
	REP(i,n)
		cin >> arr[i];
	int k=0;
	vector<int> dis(n,0);
	FOR(i,1,n-1){
		if(arr[i]==0){
			if(arr[i-1] && arr[i+1])
				dis[i]=1;
		}
	}
	while(check(dis)){
		int index=-1;
		FOR(i,1,n-1){
			if(arr[i]==1 && arr[i-1]==arr[i+1] && arr[i+1]==0 && (dis[i-1]&&dis[i+1])){
				index = i;
				break;
			}
		}		
		// error(index);
		if(index != -1){
			arr[index]=0;
			k++;
			dis[index-1]=0;
			dis[index+1]=0;
			continue;
		}
		FOR(i,1,n-1){
			if(arr[i]==1 && (!arr[i+1] || !arr[i-1]) && (dis[i+1] || dis[i-1])){
				index = i;
				break;
			}
		}
		if(index==-1){
			if(arr[0]==1 && dis[1]){
				arr[0]=0;
				dis[1]=0;
				k++;
				continue;
			}
			else if(arr[n-1]==1 && dis[n-2]){
				arr[n-1]=0;
				dis[n-2]=0;
				k++;
				continue;
			}
		}
		if(dis[index+1])
			dis[index+1]=0;
		else
			dis[index-1]=0;
		arr[index]=0;
		k++;
	}
	cout << k << endl;
	return 0;
}