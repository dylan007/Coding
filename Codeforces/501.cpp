#include<iostream>
#include<stdio.h>

using namespace std;

int max(int a,int t)
{
	int x,y;
	x = (3*a)/10;
	y = a-(a/250)*t;
	return x>y?x:y;
}

int main()
{
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	int X,Y;
	X = max(a,c);
	Y = max(b,d);
	if(X>Y)
		cout << "Misha" << endl;
	else if(X<Y)
		cout << "Vasya" << endl;
	else
		cout << "Tie" << endl;
	return 0;
}
