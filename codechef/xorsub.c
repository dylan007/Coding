#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int i,n,k,max=0;
		scanf("%d %d",&n,&k);
		int a[n];
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		int num=0,temp=0;
		for(num=0;num<pow(2,n);num++)
		{
			int t=0,x=0;
			temp =0;
			x=num;
			while(x>0)
			{
				if(x%2 == 1)
					temp = temp ^ a[t];
				t++;
				x/=2;
			}
			temp = temp ^ k;
			max = max>temp?max:temp;
		}
		printf("%d\n",max);
	}
	return 0;
}
