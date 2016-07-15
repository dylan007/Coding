#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int T;
	scanf("%d",&T);
	T--;
	int l,r;
	int L,R;
	scanf("%d %d",&L,&R);
	int i,j;
	int seg[R-L];
	memset(seg,0,4*(R-L));
	for(i=0;i<T;i++)
	{
		scanf("%d %d",&l,&r);
		for(j=l;j<r && j<R;j++)
			seg[j-L]=1;
	}
	int count=0;
	for(j=0;j<(R-L);j++)
		count += (seg[j]==0);
	printf("%d\n",count);
	return 0;
}
