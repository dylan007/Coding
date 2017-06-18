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
	if(n<=m)
	{
		vector<vector<int> > arr;
		int x;
		vector<int> temp;
		vector<int> row;
		int sr=0,sc=0;
		for(int i=0;i<n;i++)
		{
			arr.PB(temp);
			int ma=501;
			for(int j=0;j<m;j++)
			{
				cin >> x;
				arr[i].PB(x);
				ma = min(ma,x);
			}
			row.PB(ma);
			sr += ma;
		}
		//for(int i=0;i<n;i++)
		//{
		//	for(int j=0;j<m;j++)
		//		cout << arr[i][j] << " ";
		//	cout << endl;
		//}
		int flag=0;
		vector<int> col;
		for(int i=0;i<m;i++)
		{
			int j,curr=arr[0][i]-row[0];
			for(j=1;j<n;j++)
			{
				if(curr!= (arr[j][i]-row[j]))
					break;
			}
			if(j!=n)
			{
				flag=-1;
				break;
			}
			col.PB(curr);
			sc += curr;
		}
		if(flag<0)
			cout << "-1" << endl;
		else
		{
			cout << sr+sc << endl;
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<row[i];j++)
					cout << "row " << i+1 << endl;
			}
			for(int i=0;i<m;i++)
			{
				for(int j=0;j<col[i];j++)
					cout << "col " << i+1 << endl;
			}
		}
	}
	else
	{
		vector<vector<int> > arr;
		int x;
		vector<int> temp;
		vector<int> row;
		int sr=0,sc=0;
		vector<int> col(m,INT_MAX);
		for(int i=0;i<n;i++)
		{
			arr.PB(temp);
			for(int j=0;j<m;j++)
			{
				cin >> x;
				arr[i].PB(x);
				col[j] = min(col[j],x);
			}
		}
		for(int i=0;i<m;i++)
			sr += col[i];
		int flag=0;
		for(int i=0;i<n;i++)
		{
			int curr=arr[i][0]-col[0];
			for(int j=1;j<m;j++)
			{
				if(curr!=(arr[i][j]-col[j]))
				{
					flag=-1;
					break;
				}
			}
			row.PB(curr);
			sc += curr;
		}
		if(flag<0)
			cout << "-1" << endl;
		else
		{
			cout << sr+sc << endl;
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<row[i];j++)
					cout << "row " << i+1 << endl;
			}
			for(int i=0;i<m;i++)
			{
				for(int j=0;j<col[i];j++)
					cout << "col " << i+1 << endl;
			}
		}
	}
	return 0;
}

