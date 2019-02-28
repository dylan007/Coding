#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MAXN 1000000
vector<vector<ll>> divs(MAXN,vector<ll>());
void divide(){
	for(ll i=1;i<=MAXN;i++){
		for(ll j=1;j<=26 && j*j<=i;j++){
			if((i%j)==0){
				divs[i].push_back(j);
				if((j*j)!=i)
					divs[i].push_back(i/j);
			}
		}
	}
}
int main(){
	divide();
	int T;
	cin >> T;
	while(T--){
		string a;
		cin >> a;
		sort(a.begin(),a.end());
		ll l = a.length();
		vector<ll> count(26,0);
		for(auto it:a)
			count[it-'A']++;
		sort(count.begin(),count.end());
		ll ans=LONG_MAX;
		for(auto it:divs[l]){
			ll curr = it;
			ll pn=0,pp=0,pos=25,c=l/curr;
			ll l,r;
			l = 0;
			r = 25;
			while(count[l]<curr)
				l++;
			while(count[r]>curr)
				r--;
			r++;
			l--;
			l = max(l,0ll);
			l = min(25ll,l);
			r = min(r,25ll);
			c -= max(0ll,r-l-1);
			//cout << l << " " << r << endl;
			while(l>=0 && r<=25 && c>0){
				if(abs(count[l]-curr)>abs(count[r]-curr)){
					pp += count[r]-curr;
					if(l==r)
						l--;
					r++;
				}
				else if(count[l]!=0){
					pn += curr-count[l];
					if(l==r) r++;
					l--;
				}
				else{
					pp += count[r]-curr;
					if(l==r) l--;
					r++;
				}
				c--;
			}
			while(l>=0 && c>0){
				pn += (curr - count[l]);
				l--;
				c--;
			}
			while(r<=25 && c>0){
				pp += (count[r] - curr);
				r++;
				c--;
			}
			ll tot=0;
			tot = max(pn,pp);
			//cout << curr << " " << tot << " " << pn << " " << pp << endl;
			ans = min(ans,tot);
		}
		cout << ans << endl;
	}
	return 0;
}
