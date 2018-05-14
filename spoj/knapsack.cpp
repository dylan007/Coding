#include<bits/stdc++.h>

using namespace std;

bool sortfunc(const pair<int,int> a,const pair<int,int> b)
{
	if(a.first != b.first)
		return a.first<b.first;
	else
		return a.second>b.second;
}


int main()
{
	int x,y,n,s;
	cin >> s >> n;
	vector < pair < int,int > > items;
	for(int i=0;i<n;i++)
	{
		cin >> x >> y;
		pair<int,int> temp;
		temp = make_pair(x,y);
		items.push_back(temp);
	}
	sort(items.begin(),items.end(),sortfunc);
	int i=0,ans=0;
	while(s>0)
	{
		if(s>items[i].first)
		{
			ans += items[i].second;
			s -= items[i].first;
		}
		else
			break;
		i++;
	}
	cout << ans  << endl;
	return 0;
}

