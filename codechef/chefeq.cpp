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
		int temp =a[0];
		int i=0;
		int count =1,max=1;
		for(i=1;i<n;i++)
		{
			if(temp != a[i])
			{
				temp = a[i];
				max = max>count?max:count;
				count=1;
			}
			else
				count++;
		}
		cout << n-max << endl;
	}
	return 0;
}
