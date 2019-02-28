#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		long long int m = 0;
		for(int i=0;i<n;i++){
			long long int x;
			cin >> x;
			m += (x-1);
		}
		cout << m+1 << endl;
	}
	return 0;
}