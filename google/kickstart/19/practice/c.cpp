#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define MOD 1000000007

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

ll modinv(ll a){
    return modexp(a,MOD-2);
}

ll calc(vector<ll> A,ll p){
    ll ans=0;
    ll curr = 1,s=1;
    ll factor = A.size();
    for(ll i=1;i<=A.size();i++){
        ll tmp = s * factor * A[i-1];
        curr ++;
        s = (s + modexp(curr,p))%MOD;
        factor--;
        ans = (ans + tmp)%MOD;
    }
    return ans;
}

ll gps(ll a,ll n){
    return ((a * (modexp(a,n)-1))%MOD)*(modinv(a-1)) %MOD;
}

int main(){
    ll T;
    cin >> T;
    for(ll test=1;test<=T;test++){
        cout << "Case #" << test << ": ";
        ll n,k,x1,y1,c,d,e1,e2,f;
        cin >> n >> k >> x1 >> y1 >> c >> d >> e1 >> e2 >> f;
        // cout << n << " " << k << " " << x1 << " " << y1 << " " << c << " " << d << " " << e1 << " " << e2 << " " << f << endl;
        vector<ll> X(n),Y(n),A(n);
        X[0] = x1;
        Y[0] = y1;
        A[0] = (X[0] + Y[0])%f;
        for(int i=1;i<n;i++){
            X[i] = (c*X[i-1] %f + d*Y[i-1] %f + e1)%f;
            Y[i] = (d*X[i-1] %f + c*Y[i-1] %f + e2)%f;
            A[i] = (X[i] + Y[i])%f;
        }
        ll ans=0;
        // for(ll K=1;K<=k;K++){
        //     // cout << calc(A,K) << endl;
        //     ans = (ans + calc(A,K))%MOD;
        // }
        ll factor = A.size();
        ll s=k,curr=1;
        for(ll i=1;i<=A.size();i++){
            // cout << s << endl;
            ll tmp = (factor * A[i-1] * s)%MOD;
            // cout << A[i-1] << " " << tmp << endl;
            curr++;
            s = (s + gps(curr,k))%MOD;
            factor--;
            ans = (ans + tmp)%MOD;
        }
        cout << ans << endl;
    }
}
