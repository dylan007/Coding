#include<bits/stdc++.h>

using namespace std;

int main()
{
	vector<int> f,s;
	int x,n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> x;
		f.push_back(x);
	}
	for(int i=0;i<(n-1);i++)
	{
		cin >> x;
		std::vector<int>::iterator pos = find(f.begin(),f.end(),x);
		if(pos != f.end()) f.erase(pos);
		s.push_back(x);
	}
	cout << f[0] << endl;
	for(int i=0;i<(n-2);i++)
	{
		cin >> x;
		std::vector<int>::iterator pos = find(s.begin(),s.end(),x);
		if(pos != s.end()) s.erase(pos);
	}
	cout << s[0] << endl;
	return 0;
}
