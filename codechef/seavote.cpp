#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		double a[n];
		double sum=0;
		for(int i=0;i<n;i++)
		{
			cin >> a[i];
			sum += a[i];
		}
		if(sum < 100)
			cout << "NO" << endl;
		else if(sum>=100 && sum <= 101)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
