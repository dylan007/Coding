#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	long long int n,t;
	cin >> n;
	int c=0;
	while(n>0)
	{
		t = pow(2,c);
		if(n%2 == 1)
			cout << t << " ";	
		c++;
		n/=2;
	}
	cout << endl;
	return 0;
}
