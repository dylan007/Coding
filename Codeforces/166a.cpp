#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

typedef int (*compfn)(const void*, const void*);

typedef struct
{
	int prob,time;
}team;

int cmpfunc(team *a,team *b)
{
	if(a->prob > b->prob)
		return -1;
	else if(a->prob < b->prob)
		return 1;
	else
	{
		if(a->time < b->time)
			return -1;
		else if(a->time > b->time)
			return 1;
		else
			return 0;
	}
}


int main()
{
	int n,k;
	cin >> n >> k;
	team a[n];
	for(int i=0;i<n;i++)
		cin >> a[i].prob >> a[i].time;
	qsort(a,n,sizeof(team),(compfn)cmpfunc);
	int count=0;
	k--;
	for(int i=0;i<n;i++)
		count += (a[i].prob==a[k].prob && a[i].time==a[k].time);	
	cout << count << endl;
}
