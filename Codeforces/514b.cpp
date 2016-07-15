#include<bits/stdc++.h>

using namespace std;

#define inf INT_MAX

int main()
{
	int n,x,y,x1,y1;
	cin >> n >> x >> y;
	double cord[n];
	for(int i=0;i<n;i++)
	{
		cin >> x1 >> y1;
		if(x-x1 == 0)
			cord[i]=inf;
		else
			cord[i] = (y-y1)/(x-x1);
	}
	sort(cord,cord+n);
	int X=1,temp=cord[0];
	cout << cord[0];
	for(int i=1;i<n;i++)
	{
		cout << cord[i];
		if(temp != cord[i])
		{
			X++;
			temp = cord[i];
		}
	}
	cout << X << endl;
	return 0;
}
