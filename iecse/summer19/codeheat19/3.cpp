#include<bits/stdc++.h>
using namespace std;

#define LIM 10000
#define ll long long int

ll isPrime(ll x){
	ll curr=2;
	while((curr*curr)<=x){
		if((x%curr)==0)
			return 0;
		curr++;
	}
	return 1;
}

ll pow(ll a){
	ll ans=1;
	ll c=a;
	while(c--)
		ans *= a;
	return ans;
}

int main(){
	ll T;
	cin >> T;
	set<ll> s;
	ll curr=2;
	while(curr<=LIM){
		if(isPrime(curr)){
			s.insert(curr);
			if(curr<=5)
				s.insert(pow(curr));
		}
		curr++;
	}
	while(T--){
		ll x;
		cin >> x;
		if(s.find(x)!=s.end())
			cout << 1 << endl;
		else if(!(x&1))
			cout << 2 << endl;
		else{
			auto it=s.lower_bound(x);
			it--;
			ll y = *it;
			x -= y;
			if((x==2)||(x==4))
				cout << 2 << endl;
			else
				cout << 3 << endl;
		}
	}
	return 0;
}
