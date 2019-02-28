#include<bits/stdc++.h>
using namespace std;

int main(){
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		vector<int> a(n),d(n);
		for(int i=0;i<n;i++) cin >> a[i];
		for(int i=0;i<n;i++) cin >> d[i];
		int m=-1;
		for(int i=1;i<(n-1);i++){
			if((a[i-1]+a[i+1])<d[i])
				m = max(d[i],m);
		}
		if((a[1]+a[n-1])<d[0])
			m = max(d[0],m);
		if((a[n-2]+a[0])<d[n-1])
			m = max(d[n-1],m);
		cout << m << endl;
	}
	return 0;
}