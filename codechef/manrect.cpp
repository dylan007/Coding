#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define MAXN 1000000000
#define flush fflush(stdout);
int main(){
	ll T;
	cin >> T;
	while(T--){
		ll A,B,C,D;
		cout << "Q 0 0" << endl;
		flush;
		cin >> A;
		cout << "Q " << MAXN << " 0" << endl;
		flush;
		cin >> B;
		cout << "Q " << MAXN << " " << MAXN << endl;
		flush;
		cin >> C;
		cout << "Q 0 " << MAXN << endl;
		flush;
		cin >> D;
		ll xl,yl,l,h;
		ll p = (MAXN + D - C)/2;
		cout << "Q " << p << " 0" << endl;
		flush;
		cin >> yl;
		xl = A-yl;
		l = 0-xl+yl+MAXN-B;
		h = MAXN-A-C+B+xl-yl;
		cout << "A " << xl << " " << yl << " " << xl+l << " " << yl+h << endl;
		flush;
		ll res;
		cin >> res;
	}
	return 0;
}