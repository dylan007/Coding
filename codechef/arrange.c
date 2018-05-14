#include<stdio.h>
#include<stdlib.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,i,k;
		char inp[65540]={0};
		char out[65540] = {0};
		scanf("%d%*c%s",&n,inp);
		int l,j,t;
		l = 1<<n;
		for(i=0;i<l;i++)
		{
			j=0;
			t = i;
			for(k=0;k<n;k++)
			{
				j = (j<<1) + (i&1);
				i = i>>1;
			}
			i = t;
			out[j] = inp[i];
		}
		out[i] = 0;
		printf("%s\n",out);
	}
	return 0;
}
