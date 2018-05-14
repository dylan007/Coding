#include<bits/stdc++.h>

using namespace std;

int main()
{
	int x,n;
	cin >> n;
	int s1=0;
	for(int i=0;i<n;i++)
	{
		cin >> x;
		s1 += x;
	}
	int s2=0,s3=0;
	for(int i=0;i<(n-1);i++)
	{
		cin >> x;
		s2 += x;
	}
	cout << s1-s2 << endl;
	for(int i=0;i<(n-2);i++)
	{
		cin >> x;
		s3 += x;
	}
	cout << s2-s3 << endl;
	return 0;
}
