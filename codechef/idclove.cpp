#include<bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		long long int x,y;
		cin >> x >> y;
		long long int sum=0;
		sum = (y*(y-1))/2;
		long long int prod;
		prod = x/y;
		long long int rem;
		rem = x%y;
		rem = (rem*(rem+1))/2;
		cout << (prod*sum + rem) << endl;
	}
	return 0;
}
