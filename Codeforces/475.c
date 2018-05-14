#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	int H,W;
	scanf("%d %d%*C",&W,&H);
	int horz[H],vert[W];
	int i,j;
	char c;
	for(i=0;i<W;i++)
	{
		c=getchar();
		horz[i] = (c=='<');
	}
	getchar();
	for(i=0;i<H;i++)
	{
		c=getchar();
		vert[i] = (c=='^');
	}
	int check[H][W];
	memset(check,0,4*H*W);
	for(i=0;i<W;i++)
		printf("%d\t",horz[i]);
	printf("\n");
	for(i=0;i<H;i++)
		printf("%d\t",vert[i]);
	int x=0,y=0;
	for(i=0;i<W;i++)
	{
		if(horz[i]==1)
		{
			x=H-1;
			check[x][y] = 1;
			while(x>=H || x<0 || y>=W || y<0)
			{
				
			}
		}
	}
	return 0;
}
