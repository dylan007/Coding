using namespace std;
 
int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int n,m;
		cin >> n >> m;
		int x,y;
		vector<int> c(n,0);
		int count=n;
		for(int i=0;i<m;i++)
		{
			cin >> x >> y;
			count -= !c[x-1]+!c[y-1];
			c[x-1] = 1;
			c[y-1] = 1;
		}
		if(count%2)
			cout << "no" << endl;
		else
			cout << "yes" << endl;
	}
	return 0;
}
