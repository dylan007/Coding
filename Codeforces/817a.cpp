#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define MK make_pair 
#define size(a) (int)(sizeof(a))

int main()
{
	ll a,b,c,d;
	ll x,y;
	cin >> a >> b >> c >> d >> x >> y;
	int flag=1;
	flag &= ((abs(a-c))%x)==0;
	flag &= ((abs(b-d))%y)==0;
	a = abs(a-c)/x;
	b = abs(b-d)/y;
	if(!(abs(a-b)%2) && flag)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}

