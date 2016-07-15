#include<iostream>

using namespace std;

int gcd(int a,int b)
{
	return (b!=0)?gcd(b,a%b):a;
}

int main()
{
	int x,y;
	cin >> x >> y;
	int max=0;
	max = x;
	max = max>y?max:y;
	max =6-max+1;
	y=6;
	if(max==0)
		cout << "0/1" << endl;
	else
		cout << max/gcd(max,y) << "/" << 6/gcd(max,y) << endl;
	return 0;
}
