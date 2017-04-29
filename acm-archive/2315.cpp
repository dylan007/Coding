#include<bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		vector<int> a;
		int x,sum=0;
		cin >> x;
		while(x!=0)
		{
			a.push_back(x);
			sum += x;
			cin >> x;
		}
		int i;
		for(i=0;i<a.size();i++)
		{
			if(3*a[i] == sum)
				break;
		}
		if(a.size()<=1)
		{
			cout << "0" << endl;
			continue;
		}
		if(i>=a.size())
			cout << "0" << endl;
		else
			cout << a[i] << endl;
	}
	return 0;
}

