#include<iostream>

using namespace std;

int main()
{
	long long int x,y,z;
	cin >> x >> y >> z;
	while(x!=0 || y!=0 || z!=0)
	{
		if(y-x == z-y)
			cout << "AP " << y-x+z << endl;
		else
			cout << "GP " << (y/x)*z << endl;
		cin >> x >> y >> z;
	}
	return 0;
}
