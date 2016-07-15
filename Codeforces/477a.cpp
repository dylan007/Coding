#include<iostream>
#include<cmath>
#include<string>

using namespace std;

int main()
{
	int p,n;
	cin >> p >> n;
	int i;
	int a[p],x;
	for(i=0;i<p;i++)
		a[i]=-1;
	for(i=1;i<=n;i++)
	{
		cin >> x;
		int t;
		t = x%p;
		if(a[t]==-1)
			a[t]=x;
		else
		{
			cout << i << endl;
			return 0;
		}
	}
	cout << "-1" << endl;
}
