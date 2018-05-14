#include<iostream>

using namespace std;
#define mod 1000000007;

int main()
{
	int x,y;
	int n;
	cin >> x >> y >> n;
	n = n%6;
	int ans;
	switch(n)
	{
		case 1:
			ans = x;;
			break;
		case 2:
			ans = y;
			break;
		case 3:
			ans = y-x;
			break;
		case 4:
			ans = -x;
			break;
		case 5:
			ans = -y;
			break;
		case 0:
			ans = x-y;
			break;
	}
	ans = ans%mod;
	ans+= (ans<0)*mod;
	cout << ans << endl;
}
