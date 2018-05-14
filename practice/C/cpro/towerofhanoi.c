#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

void towers(int N,char from,char to,char aux)
{
	if(N==1)
	{
		printf("MOVE disk 1 from %c to %c\n",from,to);
		return ;
	}
	towers(N-1,from,aux,to);
	printf("MOVE DISK %d from %c to %c\n",N,from,to);
	towers(N-1,aux,to,from);
}

int main()
{
	int N;
	scanf("%d",&N);
	towers(N,'A','C','B');
	return 0;
}
