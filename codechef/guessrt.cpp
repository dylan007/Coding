#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD 1000000007
typedef struct frac{ll x,y;}frac;
ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
frac mul(frac a,frac b){
	ll g=gcd(a.x*b.x,a.y*b.y);
	frac t;
	t.x=(a.x * b.x);
	t.y=(a.y*b.y);
	if(g==0) return t;
	t.x /= g;
	t.y /= g;
	return t;
}
frac add(frac a,frac b){
	frac tmp;
	tmp.x = a.x * b.y + a.y * b.x;
	tmp.y = a.y * b.y;
	ll g = gcd(tmp.x,tmp.y);
	if(g==0) return tmp;
	tmp.x /= g;
	tmp.y /= g;
	return tmp;
}
frac sub(frac a,frac b){
	frac tmp;
	tmp.x = a.x * b.y - a.y * b.x;
	tmp.y = a.y * b.y;
	ll g = gcd(tmp.x,tmp.y);
	if(g==0) return tmp;
	tmp.x /= g;
	tmp.y /= g;
	return tmp;
}
ll modexp(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1)
			ans = (ans * a)%MOD;
		a = (a*a)%MOD;
		b >>= 1;
	}
	return ans;
}
ll modinv(ll a){return modexp(a,MOD-2);}
int main(){
	int T;
	cin >> T;

	while(T--){
		ll n,k,m;
		cin >> n >> k >> m;
		frac ans,fail;
		ans.x = 0;
		ans.y = 1;
		frac suc;
		suc.x = 1;
		suc.y = n;
		fail.x = n-1;
		fail.y = n;
		frac unit;
		unit.x = 1;
		unit.y = 1;
		for(ll i=1;i<=m;i+=2){
			ans = add(ans,mul(unit,suc));
			unit = mul(unit,fail);
		}
		//cout << unit.x << " " << unit.y << endl;
		//cout << ans.x << " " << ans.y << endl;
		//cout << suc.x << " " << suc.y << endl;
		if((m%2)==0){
			suc.y = n+k;
			ans = add(ans,mul(unit,suc));
		}
		//cout << ans.x << " " << ans.y << endl;
		cout << (ans.x * modinv(ans.y))%MOD << endl;
	}
	return 0;
}
