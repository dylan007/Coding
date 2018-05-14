#include<bits/stdc++.h>

using namespace std;

int main()
{
	int i,n,k;
	cin >> n >> k;
	int time = 240 - k;
	time = time/5;
	for(i=1;i<=n;i++)
	{
		if((i*(i+1)/2)>=time)
			break;
	}
	if (i*(i+1)/2 <= time)
		cout << min(i,n) << endl;
	else
		cout << min(i-1,n) << endl;
	return 0;
}
