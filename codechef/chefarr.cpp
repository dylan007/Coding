#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int check(int sum[],int x,int y,int n)
{
	return (sum[x]==(sum[y]-sum[x]) && sum[x]==(sum[n-1]-sum[y]));
}

int main()
{
	int n;
	cin >> n;
	int a[n];
	int x;
	a[0]=0;
	for(int i=0;i<n;i++)
	{
		cin >> x;
		a[i] = a[i-(i!=0)]+x;
	}
	int i,j,count=0;
	for(i=0;i<(n-2);i++)
	{
		for(j=i+1;j<(n-1);j++)
		{
			if(check(a,i,j,n)==1)
				count++;
		}
	}
	cout << count << endl;
	return 0;
}
