#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int p;
	scanf("%d",&p);
	if(p>5)
	{
		while(p>5)
		{
			p = (p%2 == 0)?((p-4)/2):((p-5)/2);
		}
	}
	switch(p){
		case 1:
			printf("Sheldon\n");
			break;
		case 2:
			printf("Leonard\n");
			break;
		case 3:
			printf("Penny\n");
			break;
		case 4:
			printf("Rajesh\n");
			break;
		case 5:
			printf("Howard\n");
			break;
	}

	//printf("%f\n",log2);
	return 0;
}
