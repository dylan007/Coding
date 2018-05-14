#include<bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		int a[n];
		for(int i=0;i<n;i++)
			cin >> a[i];
		sort(a,a+n);
		int count=0;
		int temp=0;
		for(int i=0;i<n;i++)
		{
			if(temp!=a[i])
			{
				temp = a[i];
				count++;
			}
		}
		cout << count << endl;
	}
	return 0;
}
