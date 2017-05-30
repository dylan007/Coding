#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		vector<string> s(2);
		for(int i=0;i<2;i++)
			cin >> s[i];
		int count=0;
		for(int i=0;i<n;i++)
			count += (s[0][i]=='#') + (s[1][i]=='#');
		int curr=0;
		int cnt=0;
		int start=0;
		int flag=0;
		for(int i=0;i<n;i++)
		{
			if(s[0][i]=='#' || s[1][i]=='#')
			{
				start = i;
				break;
			}
		}
		for(int i=start;i<n;i++)
		{
			if(s[0][i]=='#' && s[1][i]=='#')
			{
				curr = !curr;
				cnt += 2;
			}
			else if(s[curr][i]=='#')
				cnt++;
			else
			{
				flag=1;
				break;
			}
		}
		if(count == cnt)
		{
			cout << "yes" << endl;
			continue;
		}
		curr=1;
		cnt=0;
		for(int i=start;i<n;i++)
		{
			if(s[0][i]=='#' && s[1][i]=='#')
			{
				curr = !curr;
				cnt += 2;
			}
			else if(s[curr][i]=='#')
				cnt++;
			else
			{
				flag=1;
				break;
			}
		}
		if(count == cnt)
		{
			cout << "yes" << endl;
			continue;
		}
		cout << "no" << endl;
	}
	return 0;
}
