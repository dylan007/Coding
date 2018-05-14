#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	int N;
	char bus[100][100];
	int i,j;
	scanf("%d",&N);
	int count = N;
	for(i=0;i<27;i++)
	{
		switch(i)
		{
			case 0:
			case 25:
			{
				for(j=0;j<6;j++)
				{
					switch(j)
					{
						case 0:
						case 5:
							bus[j][i] = '+';
							break;
						default:
							bus[j][i] = '|';
			
					}
				}
			}
			break;
			case 26:
			{
				for(j=0;j<6;j++)
				{
					switch(j)
					{
						case 1:
						case 4:
							bus[j][i] = ')';
							
							break;

						
				
					}
				}
			}
			break;
			case 24:
			{
				for(j=0;j<6;j++)
				{
					switch(j)
					{
						case 0:
						case 5:
							bus[j][i] = '-';
							break;
						case 1:
							bus[j][i] = 'D';
							break;
						default:
							bus[j][i] = '.';
					
					}
				}
			}
			break;
			default:
			{	
				for(j=0;j<6;j++)
				{
					switch(j)
					{
						case 0:
						case 5:
							bus[j][i] = '-';
							break;
						case 3:
							if(count>0 && i==1)
								bus[j][i]='O',count--;
							else if(count<=0 && i==1)
								bus[j][i] = '#';
							else
								bus[j][i]='.';
							
							break;
						default:
							if(i%2 == 1)
							{
								if(count>0)
								{
									bus[j][i]='O';
									count--;
								}
								else
								{
									if(i==23)
										bus[j][i] = '|';
									else
										bus[j][i]='#';
								}
							}
							else
								bus[j][i]='.';
					
					}
				}	
			}
		
		}	
	}
	for(j=0;j<6;j++)
		printf("%s\n",bus[j]);
	return 0;
}
