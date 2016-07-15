#include<bits/stdc++.h>

using namespace std;

int lookup[] = {0, 0, 0, 0, 1, 1, 1, 1, 6, 2, 4, 8, 1, 3, 9, 7, 6, 4, 6, 4,5, 5, 5, 5, 6, 6, 6, 6, 1, 7, 9, 3, 6, 8, 4, 2, 1, 9, 1, 9};

int last(int x,int a)
{
	return lookup[((x%10)<<2)+(a&3)];
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int x,a;
		cin >> x >>a;
		if(a > 0)
			cout << last(x,a) << endl;
		else
			cout << "1\n";
	}
	return 0;
}
