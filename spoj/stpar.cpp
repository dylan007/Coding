#include<bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin >> N;
	while(1)
	{
		if(N==0)
			break;
		int x,flag=0;
		stack<int> side;
		int curr = 1;
		for(int i=0;i<N;i++)
		{
			cin >> x;
			if(curr!=x)
			{
				if(!side.empty())
				{
					if(side.top()<x)
						flag=1;
				}
				side.push(x);
				curr--;
			}
			curr++;
		}
		if(!flag)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
		cin >> N;
	}
	return 0;
}
