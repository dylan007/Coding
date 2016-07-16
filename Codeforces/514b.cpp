#include<bits/stdc++.h>

using namespace std;

#define inf INT_MAX

int main()
{
	int n;
	double x,y,x1,y1,s;
	cin >> n >> x >> y;
	set<double> slopes;
	for(int i=0;i<n;i++)
	{
		cin >> x1 >> y1;
		if(x-x1 == 0)
			s=inf;
		else
			s = (y-y1)/(x-x1);
		slopes.insert(s);
	}
	cout << slopes.size() << endl;
	return 0;
}
