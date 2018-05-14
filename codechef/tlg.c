#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,i,x=0,y=0;
	scanf("%d",&n);
	int a[n],b[n],flag[n],l[n];
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&a[i],&b[i]);
		x+=a[i];
		y+=b[i];
		if(x>y)
		{
			l[i]=x-y;
			flag[i]=1;
		}
		else 
		{
			l[i]=y-x;
			flag[i]=2;
		}
	}
	int max=0,ind;
	for(i=0;i<n;i++)
	{
		if(max<l[i])
		{
			max=l[i];
			ind=i;
		}
	}
	printf("%d %d\n",flag[ind],max);
	return 0;
}
