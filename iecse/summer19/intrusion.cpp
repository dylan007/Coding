/*=======================
Author    : Shounak Dey
=======================	*/

#include<bits/stdc++.h>

using namespace std;

using ll = long long int;

int main()
{
	int T,n;
	cin >> T >> n;
	while(T--){
		ll ans=0,x;
		for(int i=0;i<n;i++){
			cin >> x;
			ans ^= x;
		}
		if(T==0)
			cout << ans;
		else
			cout << ans << " ";
	}
	cout << endl;
	return 0;
}

