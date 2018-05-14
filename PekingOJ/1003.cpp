#include<iostream>
#include<cmath>

using namespace std;

#define E 2.72
#define e 0.577

int main()
{
	double x;
	int n;
	cin >> x;
	while(x>0.00)
	{
		x++;
		x-=e;
		n = exp(x);
		n--;
		cout << (int)n + 1 << endl;
		cin >> x;
	}
	return 0;
}
