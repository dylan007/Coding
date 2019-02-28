#include<bits/stdc++.h>

using namespace std;

long long int gcd(long long int a,long long int b){
	return b==0?a:gcd(b,a%b);
}

int main(){
	int T;
	cin >> T;
	while(T--){
		long long int n,a,b,k;
		cin >> n >> a >> b >> k;
		long long int c1,c2;
		c1 = n/a - (n*gcd(a,b)/(a*b));
		c2 = n/b - (n*gcd(a,b)/(a*b));
		// cout << c1 << " " << c2 << endl;
		if((c1 + c2)>=k)
			cout << "Win" << endl;
		else
			cout << "Lose" << endl;
	}
	return 0;
}