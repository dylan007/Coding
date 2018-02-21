#include "bits/stdc++.h"
using namespace std;
struct ${$(){ios_base::sync_with_stdio(0);cin.tie(0);}}$;

const int N = 200005;
int prefix[N], nums[N];
int main() {
    int n, l, r, maxi = 0, idx = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> nums[i];
        prefix[i] = prefix[i - 1] + nums[i];
    }
    cin >> l >> r;
    for(int i = 1; i <= n; i++){
        int start = l - i + 1, temp;
        if(start <= 0) start = l + n - i + 1;
        int end = r - i;
        if(end <= 0) end = r + n - i ;
        if(start <= end) temp = prefix[end] - prefix[start - 1];
        else temp = prefix[n] - prefix[start - 1] + prefix[end];
        if(temp > maxi){
            maxi = temp;
            idx = i;
        }
        //cout << i << " " << temp << endl;
    }
    cout << idx << endl;
    return 0;
}