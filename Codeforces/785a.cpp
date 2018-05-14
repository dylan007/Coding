//Shounak Dey
#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define PB push_back
#define MK make_pair 
#define size(a) (int)(sizeof(a))

int p(string a)
{
	int ans=0;
	ans += (a[0]=='T')*4 + (a[0]=='C')*6 + (a[0]=='O')*8 + (a[0]=='D')*12 + (a[0]=='I')*20; 
	return ans;
}

int main()
{
	int T;
	cin >> T;
	string a;
	int ans=0;
	while(T--)
	{
		cin >> a;
		ans += p(a);
	}
	cout << ans << endl;
	return 0;
}

