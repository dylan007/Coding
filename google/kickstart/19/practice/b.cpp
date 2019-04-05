#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
int main(){
    int T;
    cin >> T;
    for(int test=1;test<=T;test++){
        ll len;
        cin >> len;
        string a;
        cin >> a;
        ll ans=0;
        ll c = (len>>1) + (len&1);
        for(int i=0;i<c;i++)
            ans += (a[i]-'0');
        ll l=0,r=c,out=ans;
        while(r<len){
            ans -= (a[l]-'0');
            ans += (a[r]-'0');
            out = max(ans,out);
            r++;
            l++;
        }
        cout << "Case #" << test << ": " << out << endl;
    }
    return 0;
}