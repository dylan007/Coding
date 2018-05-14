//Shounak Dey
#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define push_back PB
#define make_pair MK
#define size(a) (int)(sizeof(a))

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		ull sum,x,y;
		cin >> x >> y;
		sum = x+y;
		if(sum==0)
			cout << 1 << endl;
		else
		{
			sum = (sum+1)*(sum)/2 + 1;
			sum += x;
			cout << sum << endl;
		}
	}
	return 0;
}

