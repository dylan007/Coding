#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int cmpfunc(const void *a,const void *b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
	int n;
	cin >> n;
	int a[n];
	int i;
	for(i=0;i<n;i++)
		cin >> a[i];
	qsort(a,n,sizeof(int),cmpfunc);
	int c=0,max=0,temp=a[0];
	for(i=0;i<n;i++)
	{
		if(temp!=a[i])
		{
			max = max>c?max:c;
			temp=a[i];
			c=1;
		}
		else
			c++;
	}
	max = max>c?max:c;
	if(max <= (n+1)/2)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
