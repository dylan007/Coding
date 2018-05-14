#include<iostream>

using namespace std;

int main()
{
	int x,y;
	cin >> x >> y;
	int z;
	z = x+y;
	int a=0,b=0,c=0;
	int i=1;
	while(x>0)
	{
		a += (x%10)*i;
		if(x%10 != 0)
			i*=10;
		x = x/10;
	}
	i=1;
	while(y>0)
	{
		b += (y%10)*i;
		if(y%10 != 0)
			i*=10;
		y = y/10;
	}
	i=1;
	while(z>0)
	{
		c += (z%10)*i;
		if(z%10 != 0)
			i*=10;
		z = z/10;
	}
	if(a+b == c)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
