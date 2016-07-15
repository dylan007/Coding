#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int i=12;
	double x,sum=0;
	while(i--)
	{
		cin >> x;
		sum += x;
	}
	cout << '$' << sum/12 << endl;
	return 0;
}
