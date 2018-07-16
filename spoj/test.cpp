#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define lim 1000000000000000000
#define PB push_back

ll next_set(ll x){
	ll t = x | (x-1);
	ll w = (t + 1) | (((~t & -~t) - 1) >> (__builtin_ctz(x) + 1));
	return w;
}

int main()
{
    vector<ll> ele;
    ele.PB(0);
    ll curr=1;
    while(curr <= lim){
        ele.PB(curr);
        cout << curr << endl;
        curr = next_set(curr);
    }
    curr = 3;
    while(curr <= lim){
        ele.PB(curr);
        cout << curr << endl;
        curr = next_set(curr);
    }
    curr = 7;
    while(curr <= lim){
        ele.PB(curr);
        curr = next_set(curr);
    }
    sort(ele.begin(),ele.end());
    cout << ele.size() << endl;
    int T;
    cin >> T;
    while(T--){
        ll q;
        cin >> q;
        while(q--){
            ll l,r;
            cin >> l >> r;
            cout << lower_bound(ele.begin(),ele.end(),r) - lower_bound(ele.begin(),ele.end(),l) << endl; 
        }
    }
	return 0;
}