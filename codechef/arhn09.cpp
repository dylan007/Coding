#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	int n,q;
	cin >> n >> q;
	int a[n];
	int sum[n];
	sum[0]=0;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		sum[i]=sum[i-(i!=0)]+a[i];
	}
	int x,y;
	char dump[4];
	while(q--)
	{
		getchar();
		scanf("%s%*C%d%d",dump,&x,&y);
		x--;
		y--;
		cout << sum[y]-sum[x-(x!=0)]+(x==0?sum[0]:0) << endl;
	}
	return 0;
}
