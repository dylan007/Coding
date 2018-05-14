#include<iostream>
#include<cmath>
#include<utility>

using namespace std;

int main()
{
	int x,y;
	cin >> x >> y;
	int val = abs(x)+abs(y);
	pair<int,int> f = make_pair(val * (x<0 ? -1:1), 0);
	pair<int,int> s = make_pair(0, val * (y<0 ? -1:1));
        if (f.first > s.first)
		swap(f, s);
	cout << f.first << " " << f.second << " " << s.first << " " << s.second << endl;
	return 0;
}
