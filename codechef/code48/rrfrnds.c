#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main()
{
	int n;
	scanf("%d",&n);
	int i,j,a[n][n],k,p,c=0;
	char t;
	for(i=0;i<n;i++)
	{
		getchar();
		for(j=0;j<n;j++)
		{
			t = getchar();
			a[i][j]= t-48;
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i!=j && a[i][j]!=1)
			{
				for(k=0;k<n;k++)
				{
					if(a[k][j]==1)
					{
						if(a[i][k]==1)
						{
							c+=1;
							break;
						}
					}
				}		
			}
		}
	}
	printf("%d\n",c);
	return 0;
}
