#include<bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for(int t=1;t<=T;t++)
	{
		int N,x,s=0;
		cin >> N;
		std::vector<int> v;
		int drop = 0,ans=0;
		for(int i=0;i<N;i++)
		{
			cin >> x;
			s+=x;
			v.push_back(x);
			drop = max(drop,v[i+1]-v[i]);
			if(v[i]<v[i-1])
				ans += (v[i-1]-v[i]);
		}
		cout << "Case #" << t << ": ";
		cout << ans << " " << s-2*v[N-1] << endl;
	}
	return 0;
}