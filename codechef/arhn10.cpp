#include<iostream>
#include<string.h>
#include<math.h>

using namespace std;

int len(int x)
{
	int count=0;
	while(x>0)
	{
		count++;
		x/=7;
	}
	return count;
}

char out[7] = {'v','d','h','a','p','u','s'};

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int x;
		cin >> x;
		int i,l,A;
		l = len(x);
		char output[l+1];
		output[l]='\0';
		for(i=l-1;i>=0;i--)
		{
			output[i] = out[x%7];
			x = x/7;
		}
		cout << output <<  endl;
	}
	return 0;
}
