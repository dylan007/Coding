#include<bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for(int t=0;t<T;t++)
	{
		printf("Case #%d: ",t+1);
		vector<double> x;
		double n,d;
		cin >> d >> n;
		for(int i=0;i<n;i++)
		{
			double k,s;
			cin >> k >> s;
			x.push_back((d-k)/s);
		}
		sort(x.begin(),x.end());
		printf("%6lf\n",d/x[n-1]);
	}
	return 0;
}

