#include<stdio.h>
#include<stdlib.h>

int main()
{
	char s[3],t[3],i,j;
	scanf("%s%s",s,t);
	int startx,count,starty,destx,desty,tempx,tempy,cx,cy;
	startx = s[0] - 'a'+1;
	starty = s[1] - '1' +1;
	destx = t[0] - 'a' + 1;
	desty = t[1] - '1'+1;
	cx = tempx = destx - startx;
	cy = tempy = desty - starty;
	cx = abs(cx);
	cy = abs(cy);	
	count = cx;
	if(count>cy) count = cy;
	count = cx+cy-count;
	printf("%d\n",count);
	while(tempx||tempy)
	{
		if(tempx>0 && tempy>0)
		{
			printf("RU\n");
			tempx--;
			tempy--;
		}
		else if(tempx<0 && tempy>0)
		{
			printf("LU\n");
			tempx++;
			tempy--;
		}
		else if(tempx<0 && tempy<0)
		{
			printf("LD\n");
			tempx++;
			tempy++;
		}
		else if(tempx>0 && tempy<0)
		{
			printf("RD\n");
			tempx--;
			tempy++;
		}
		else if(tempx>0)
		{
			printf("R\n");
			tempx--;
		}
		else if(tempx<0)
		{
			printf("L\n");
			tempx++;
		}
		else if(tempy>0)
		{
			printf("U\n");
			tempy--;
		}
		else if(tempy<0)
		{
			printf("D\n");
			tempy++;
		}

	}
	return 0;
}





