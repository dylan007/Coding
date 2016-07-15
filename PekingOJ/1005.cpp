#include<iostream>
#include<string>
#include<cmath>

using namespace std;

#define pi 3.14159

int main()
{
	int T;
	cin >> T;
	for(int i=1;i<=T;i++)
	{
		double x,y;
		cin >> x >> y;
		double dist;
		dist = x*x + y*y;
		dist = pi*dist;
		cout << "Property " << i << ": This property will begin eroding in year " << ((int)((dist)/100))+1 << "." << endl;
	}
	cout << "END OF OUTPUT." << endl;
	return 0;
}
