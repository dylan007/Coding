#include <stdio.h>
#include <stdlib.h>

int main()
{
	int r,c;
	printf("Enter the number of rows\n");
	scanf("%d",&r);
	int **vals;
	vals = (int **)calloc(r+1,sizeof(int *));
	int i;
	for(i=0;i<r;i++)
	{
		scanf("%d",&c);
		vals[i] = (int *)calloc(c+1,sizeof(int));
		int j;
		for(j=1;j<=c;j++)
			scanf("%d",vals[i]+j);
		vals[i][0] = c;
	}
	printf("Printing ragged array\n");
	for(i=0;i<r;i++)
	{
		int j;
		for(j=1;j<=vals[i][0];j++)
			printf("%d ",vals[i][j]);
		printf("\n");
	}
	return 0;
}