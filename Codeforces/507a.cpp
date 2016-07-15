#include<bits/stdc++.h>
#include<cstdlib>


using namespace std;
typedef struct inst
{
	int index,time;
}inst;

int cmpfunc(const void *a,const void *b)
{
	inst *elem1 = (inst *)a;
	inst *elem2 = (inst *)b;

	return (int)(elem1->time-elem2->time);
}


int main()
{
	int n,k;
	cin >> n >> k;
	inst a[n];
	for(int i=0;i<n;i++)
	{
		cin >> a[i].time;
		a[i].index = i+1;
	}
	qsort(a,n,sizeof(inst),cmpfunc);
	int sum=0,i=0;
	while(sum<=k)
	{
		sum += a[i].time;
		if(sum<=k)
			i++;
	}
	cout << i << endl;
	i=0;
	sum =0;
	while(sum<=k)
	{
		sum += a[i].time;
		if(sum<=k)
		{
			cout << a[i].index << " ";
			i++;
		}
	}
	if(i!=0)
		cout << endl;
	return 0;
}
