#include<bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for(int t=0;t<T;t++)
	{
		int n,r,o,y,g,b,v;
		cin >> n >> r >> o >> y >> g >> b >> v;
		vector<int> ryb;
		printf("Case #%d: ",t);
		ryb.push_back(r);
		ryb.push_back(y);
		ryb.push_back(b);
		sort(ryb.begin(),ryb.end());
		int gaps = max(0,ryb[1]-ryb[0]-1);
		string c1,c2,c3;
		if(r==ryb[0])
			c1 = "R";
		else if(y==ryb[0])
			c1 = "Y";
		else
			c1 = "B";
		if(r==ryb[1] && c1!="R")
			c2 = "R";
		else if(y==ryb[1] && c1!="Y")
			c2 = "Y";
		else
			c2 = "B";
		if(r==ryb[2] && c1!="R" && c2!="R")
			c3 = "R";
		else if(y==ryb[2] && c1!="Y" && c2!="Y")
			c3 = "Y";
		else
			c3 = "B";
		//cout << c1 << c2 << c3 << endl;
		if(ryb[2] < (ryb[0]+ryb[1]+1-gaps))
		{
			string a="";
			for(int i=0;i<ryb[1];i++)
				a += c2;
			//cout << a << endl;
			for(int i=0;i<ryb[0];i++)
			{
			//	cout << 2*i+1 << endl;
				a.insert(2*i+1,c1);
			//	cout << a << endl;
			}
			int x = 2*ryb[0]+1;
			for(int i=x;i<gaps;i+=2)
			{
				a.insert(i,c3);
				ryb[0]--;
			}
			for(int i=0;i<ryb[0];i+=2)
				a.insert(i,c3);
			cout << a << endl;
		}
		else
			cout << "IMPOSSIBLE" << endl;
	}
	return 0;
}

