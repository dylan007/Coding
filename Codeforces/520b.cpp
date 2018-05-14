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
	int n,m;
	cin >> n >> m;
	vector<pair <int,int> > q;
	vector<int> visited(20001,0);
	pair<int,int> temp;
	q.PB(MK(n,0));
	visited[n]=1;
	while(!visited[m])
	{
		temp = q[0];
		if(temp.first == m)
			break;
		q.erase(q.begin());
		visited[temp.first]=1;
		if((temp.first*2)<=20000)
		{
			if(!visited[temp.first*2])
				q.PB(MK(temp.first*2,temp.second+1));
		}
		if(temp.first != 1)
		{
			if(!visited[temp.first-1])
				q.PB(MK(temp.first-1,temp.second+1));
		}
	}
	cout << q[0].second << endl;
	return 0;
}

