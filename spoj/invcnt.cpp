/*=======================
Author    : Shounak Dey
Filename  : invcnt.cpp
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

int getSum(vector<int> arr,int index)
{
	int sum=0;
	index++;
	while(index>0)
	{
		sum += arr[index];
		index -= (index&(-index));
	}
	return sum;
}

void update(vector<int> &arr,int n,int index,int val)
{
	index++;
	while(index<arr.size())
	{
		arr[index] += val;
		index += (index&(-index));
	}
}

void construct(vector<int> &arr,int n)
{
	vector<int> x,tmp(arr);
	SORTV(arr);
	REP(i,n)
		x.PB(lower_bound(arr.begin(),arr.end(),tmp[i])- arr.begin());
	arr = x;
}


int main()
{
	TEST
	{
		int n;
		cin >> n;
		int x;
		vector<int> bit,arr;
		bit = vector<int>(n+1);	
		REP(i,n)
		{
			cin >> x;
			arr.PB(x);
		}
		//update(bit,i,x);
		construct(arr,n);
		// for(auto it:arr)
		// 	cout << it << " ";
		// cout << endl;
		int ans=0;
		for(int i=n-1;i>=0;i--)
		{
			ans += getSum(bit,arr[i]-1);
			update(bit,n,arr[i],1);
		}
		cout << ans << endl;
	}
	return 0;
}
