#include<iostream>
#include<cmath>
#include<string>

using namespace std;

int main()
{
	int T;
	cin >> T;
	string ans[T];
	int count[T];
	while(T--)
	{
		string str;
		cin >> str;
		str.erase('-');
		cout << str;
		count[T]=0;
	}
	return 0;
}
