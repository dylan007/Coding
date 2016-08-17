#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int main()
{
	int T;
	scanf("%d%*C",&T);
	while(T--)
	{
		char inp[100010];
		scanf("%s",inp);
		int k,i,len;
		len = strlen(inp);
		int j[len],m[len],r[len];
		memset(j,0,4*len);
		memset(m,0,4*len);
		memset(r,0,4*len);
		for(i=0;i<len;i++)
		{
			j[i] = j[i-(i!=0)]+(inp[i]=='J');
			m[i] = m[i-(i!=0)]+(inp[i]=='M');
			r[i] = r[i-(i!=0)]+(inp[i]=='R');
		}
		int count=0;
		for(i=0;i<len;i++)
		{
			for(k=0;k<i;k++)
			{
				printf("%d %d %d\n",i,k,count);
				count += ((j[i]-m[i])==(j[k]-m[k]))&&((j[i]-r[i])==(j[k]-r[k]));
			}
		}
		printf("%d\n",count);
	}
	return 0;
}
