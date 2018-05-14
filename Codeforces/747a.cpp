#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int x = sqrt(n);
	while(1)
	{
		if(n%x == 0)
		{
			cout << x << " " << n/x << endl;
			return 0;
		}	
		x--;
	} 
	return 0;
}
