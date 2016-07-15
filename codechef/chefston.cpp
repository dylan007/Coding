#include<iostream>
#include<cmath>

using namespace std;


int main()
{
	long long int T;
	cin >> T;
	while(T--)
	{
		long long int n,k,max=0;
		cin >> n >> k;
		long long int a[n];
		for(long long int i=0;i<n;i++)
			cin >> a[i];
		long long int x,t;
		for(long long int i=0;i<n;i++)
		{
			cin >> x;
			t = (k/a[i])*x;
			max = max>t?max:t;
		}
		cout << max << endl;
	}
	return 0;
}
