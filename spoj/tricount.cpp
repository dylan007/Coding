#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int T,x;
	cin >> T;
	while(T--)
	{
		cin >> x;
		cout << (x*(x+2)*(2*x+1))/8 << endl;
	}
	return 0;
}
