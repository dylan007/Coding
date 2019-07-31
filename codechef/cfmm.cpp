#include <bits/stdc++.h>

using namespace std;

using ll = long long int;

int main(){
	int T;
	cin >> T;
	while(T--){
		ll n;
		cin >> n;
		map<char,ll> x;
		for(int i=0;i<n;i++){
			string a;
			cin >> a;
			for(auto it:a){
				if(x.find(it)!=x.end())
					x[it]++;
				else
					x[it] = 1;
			}
		}
		map<char,ll> fact = {{'c',2},{'o',1},{'d',1},{'e',2},{'h',1},{'f',1}};
		ll ans=LONG_MAX;
		for(auto it:fact){
			char t = it.first;
			if(x.find(t)!=x.end())
				ans = min(ans,x[t]/fact[t]);
			else{
				ans = 0;
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}