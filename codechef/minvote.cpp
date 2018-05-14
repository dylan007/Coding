/*=======================
Author    : Doraemon
Filename  : minvote.cpp
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

// int searchleft(vector<int> pre,vector<int> arr,int low,int high,int index){
// 	int mid = (low+high)/2;
// 	if(pre[index-1]-)
// }

int main()
{
	TEST{
		ll n;
		cin >> n;
		vector<ll> arr(n);
		vector<ll> pre(n,0);
		vector<ll> count(n,0);
		REP(i,n){
			cin >> arr[i];
			pre[i] = pre[i-(i!=0)] + arr[i];
		}
		REP(i,n){
			ll l,r;
			if(i!=0){
				if(i==1)
					l=0;
				else{
					ll low,high,mid;
					low = 0;
					high = i-1;
					while(low<=high){
						mid = (low+high)/2;
						ll s1,s2;
						ll flag=0;
						if(mid==0){
							s1 = pre[i-1]-pre[0];
							// error(low,high,mid,s1,s2,arr[i]);
							if(s1 > arr[i]){
								low = mid+1;
								continue;
							}
							else{
								flag=1;
							}
						}
						else{
							s1 = pre[i-1]-pre[mid];
							s2 = s1 + arr[mid];
							// error(low,high,mid,s1,s2,arr[i]);
							if(s1 > arr[i]){
								low = mid+1;
								continue;
							}
							else if(s1<=arr[i]){
								// cout << "Inside s1 and s2" << endl;
								if(s2<=arr[i]){
									// cout << "fucked" << endl;
									high = mid-1;
									continue;
								}
								else{
									// cout << "done" << endl;
									flag=1;
								}
							}
						}
						if(flag){
							// cout << mid << endl;
							break;
						}
					}
					if(low<=high)
						l = mid;
					else
						l = i-1;
				}
			}
			else
				l = 0;
			// cout << endl;
			// cout << l << endl;
			// cout << endl << "right" << endl;
			//right search
			if(i!=(n-1)){
				if(i==(n-2))
					r=n-1;
				else{
					ll low,high,mid;
					low = i+1;
					high = n-1;
					while(low<=high){
						mid = (low+high)/2;
						ll s1,s2;
						ll flag=0;
						if(mid==(n-1)){
							s1 = pre[n-2]-pre[i];
							// error(low,high,mid,s1,s2,arr[i]);
							if(s1 > arr[i]){
								high = mid-1;
								continue;
							}
							else{
								flag=1;
							}
						}
						else{
							s1 = pre[mid-1]-pre[i];
							s2 = s1 + arr[mid];
							// error(low,high,mid,s1,s2,arr[i]);
							if(s1 > arr[i]){
								high = mid-1;
								continue;
							}
							else if(s1<=arr[i]){
								// cout << "Inside s1 and s2" << endl;
								if(s2<=arr[i]){
									// cout << "fucked" << endl;
									low = mid+1;
									continue;
								}
								else{
									// cout << "done" << endl;
									flag=1;
								}
							}
						}
						if(flag)
							break;
					}
					if(low <= high)
						r = mid;
					else
						r = i+1;
				}
			}
			else
				r = n-1;
			// cout << endl << i << " "  << l << " " << r << endl << endl;
			count[l] += 1;
			if(r<(n-1))
				count[r+1] -= 1;
		}
		FOR(i,1,n)
			count[i] += count[i-1];
		REP(i,n)
			cout << count[i]-1 << " ";
		cout << endl;
	}
	return 0;
}
