#include<bits/stdc++.h>

using namespace std;

int main()
{
	int T,x,y;
	cin >> T;
	int flag=0;
	vector<int> a,b;
	while(T--)
	{
		cin >> x >> y;
		flag |= (x!=y);
		a.push_back(x);
		b.push_back(x);
	}
	sort(a.rbegin(),a.rend());
	if(a==b && flag==0)
		flag=2;
	if(flag==1)
		cout << "rated"  << endl;
	else if(flag==0)
		cout << "unrated" << endl;
	else
		cout << "maybe" << endl;
	return 0;
}

