#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int T;
	cin >> T;
	int en=0,x=0,y=0,a=0,b;
	while(T--)
	{
		cin >> b;
		x += (a-b);
		if(x<0)
		{
			y += -x;
			x=0;
		}
		a = b;
	}
	cout << y << endl;
	return 0;
}
