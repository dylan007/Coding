#include<bits/stdc++.h>

using namespace std;

int main(){
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		vector<string> arr(n);
		for(int i=0;i<n;i++) 
			cin >> arr[i];
		vector<int> master(26,0);
		for(int i=0;i<n;i++){
			vector<int> c(26,0);
			for(auto it:arr[i])
				c[it-'a']++;
			for(int j=0;j<26;j++)
				master[j] += (c[j]>0);
		}
		int ans=0;
		for(auto it:master)
			ans += (it==n);
		cout << ans << endl;
	}
	return 0;
}