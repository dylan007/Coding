//Shounak Dey
#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define PB push_back
#define MK make_pair 
#define size(a) (int)(sizeof(a))

int main()
{
	ull n,x;	
	cin >> n >> x;
	x = x/9 + ((x%9)!=0);
	x *= 9;
	ull s = (x/10 + 1)*10;
	if(n>=s)
		cout << n-s+1 << endl;
	else
		cout << "0" << endl;
	return 0;
}

