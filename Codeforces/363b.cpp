#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int n,k;
	cin >> n >>  k;
	int a[n];
	int sum[n];
	sum[0]=0;
	int i;
	for(i=0;i<n;i++)
	{
		cin >> a[i];
		sum[i] = sum[i-(i!=0)]+a[i];
	}
	int min=500000000;
	int index,S;
	for(i=1;i<=(n-k+1);i++)
	{
		S=sum[i+k-1]-sum[i-1];
		cout << S << min << endl;
		if(min > S)
		{
			min = S;
			index = i;
		}
	}
	cout << index+1 << endl;
	return 0;
}
