//Shounak Dey
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

ll inv=0;

void merge(ll *arr,ll start,ll mid,ll end)
{
	vector<ll> l,r;
	ll n1,n2;
	n1 = mid-start+1;
	n2 = end-mid;
	for(ll i=0;i<n1;i++)
		l.PB(arr[start+i]);
	for(ll i=0;i<n2;i++)
		r.PB(arr[mid+i+1]);
	int i=0,j=0,k=start;
	while(i<n1 && j<n2)
	{
		if(l[i]>r[j])
		{
			arr[k++] = r[j++];
			inv += n1-i;
		}
		else
			arr[k++] = l[i++];
	}
	while(i<n1)
		arr[k++] = l[i++];
	while(j<n2)
		arr[k++] = r[j++];
	return;
}

void merge_sort(ll *arr,ll start,ll end)
{
	ll mid = (start+end)/2;
	if(start>=end)
		return;
	merge_sort(arr,start,mid);
	merge_sort(arr,mid+1,end);
	merge(arr,start,mid,end);
	return;
}

int main()
{
	TEST
	{
		inv = 0;
		ll n;
		readl(n);
		ll arr[n];
		REP(i,n)
			readl(arr[i]);
		merge_sort(arr,0,n-1);
		/*REP(i,n)
			cout << arr[i] << " ";
		cout << endl;*/
		cout << inv << endl;
	}
	return 0;
}

